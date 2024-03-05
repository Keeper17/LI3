#include "../../include/control/control.h"

/*Estruturas*/

struct fileInfo{
  int vp, vc, vv;
  int tp, tc, tv;
  char *prodsPath, *cliPath, *vendaPath;
};

struct sgv{
  CatProds catProds;
  CatClientes catClientes;
  HashTableFat faturacao;
  FilHash filiais;
  FI info;
};

FI initFI(){
  FI f = (struct fileInfo*)malloc(sizeof(struct fileInfo));
  f->vp = f->vc = f->vv = f->tp = f->tc = f->tv = 0;
  f->prodsPath = (char*)malloc(sizeof(char*));
  f->cliPath = (char*)malloc(sizeof(char*));
  f->vendaPath = (char*)malloc(sizeof(char*));

  return f;
}

void freeFI(FI f){
  free(f->prodsPath);
  free(f->cliPath);
  free(f->vendaPath);
  free(f);
}

SGV initSGV(){
  SGV gestor = (struct sgv*)malloc(sizeof(struct sgv));
  gestor->catProds = initCatProds();
  gestor->catClientes = initCatClientes();
  gestor->faturacao = initHashTableFat();
  gestor->filiais = initFilHash();
  gestor->info = initFI();

  return gestor;
}

void destroySGV(SGV gestor){
  if(gestor != NULL){
    freeCatProds(gestor->catProds);
    freeCatClientes(gestor->catClientes);
    freeFI(gestor->info);
    freeFilHash(gestor->filiais);
    freeFatHash(gestor->faturacao);
  }
}

/*Funções para ler dos ficheiros*/

SGV lerProdutos(SGV gestor, char* pathProds){
  (gestor->info->prodsPath) = strdup(pathProds);
  FILE *fp = fopen(pathProds, "r");
  char buffer[MAXBUFSIZE] = "";
  int prods_val = 0;

  if(fp){
    while(fgets(buffer, MAXBUFSIZE, fp)){
      char* prod_token = strtok(buffer, "\r\n");
      (gestor->info->tp)++;
      if(validaProduto(prod_token) == true){
        insertCatProds(gestor->catProds, prod_token);
        (gestor->info->vp)++;
      }
    }
    fclose(fp);
  }
  else
    printf("Unable to open file %s\n", pathProds);

  return gestor;
}

SGV lerClientes(SGV gestor, char* pathClientes){
  (gestor->info->cliPath) = strdup(pathClientes);
  FILE *fp = fopen(pathClientes, "r");
  char buffer[MAXBUFSIZE] = "";
  int clientes_val = 0;

  if(fp){
    while(fgets(buffer, MAXBUFSIZE, fp)){
      char* cliente_token = strtok(buffer, "\r\n");
      (gestor->info->tc)++;
      if(validaCliente(cliente_token) == true){
        insertCatClientes(gestor->catClientes, cliente_token);
        (gestor->info->vc)++;
      }
    }
    fclose(fp);
  }
  else
    printf("Unable to open %s!\n", pathClientes);

  return gestor;
}

SGV lerVendas(SGV gestor, char* pathVendas){
  (gestor->info->vendaPath) = strdup(pathVendas);
  FILE *fp = fopen(pathVendas, "r");
  char buffer[MAXBUFSIZE] = "";
  char** campos = (char**)malloc(7*sizeof(char*));

  if(fp){
    while(fgets(buffer, MAXBUFSIZE, fp)){
      char* token = strtok(buffer, " ");
      (gestor->info->tv)++;
      int i = 0;

      while(token != NULL){
        campos[i] = strdup(token);
        token = strtok(NULL, " ");
        i++;
      }
      if(existeProduto(campos[0], gestor->catProds) == true && existeCliente(campos[4], gestor->catClientes) == true){
        insertHashTableFat(gestor->faturacao, campos);
        insertFilHash(gestor->filiais, campos);
        updateExisteP(gestor->catProds, campos[0]);
        updateExisteC(gestor->catClientes, campos[4]);
        (gestor->info->vv)++;
      }

    }
    fclose(fp);
  }
  else
    printf("Unable to open file %s\n", pathVendas);
  return gestor;
}

/*Interface pedida*/

SGV loadSGVFromFiles(SGV gestor, char* clientes, char* produtos, char* vendas){
  gestor = lerClientes(gestor, clientes);
  gestor = lerProdutos(gestor, produtos);
  gestor = lerVendas(gestor, vendas);

  return gestor;
}

FI getCurrentFilesInfo(SGV sgv){
  return sgv->info;
}

Array getProductStartedByLetter(SGV sgv, char letter){
    Array a = initArray();
    a = query2Prod(sgv->catProds, letter, a);
    return a;
}

SGV getProductSalesAndProfit(SGV sgv, char* productID, int month){
  char res[MAXBUFSIZE];

  fgets(res, MAXBUFSIZE, stdin);
  if(!(res[0] == 'G' || res[0] == 'F')) { printErro(); return sgv; }

  if (res[0] == 'G'){
    double vals[4];
    int i = 0;

    for(i = 0; i < 4; i++){
      vals[i] = 0;
    }

    query3Fat(sgv->faturacao, productID, month, vals);
    printR3(vals);
  }
  else{
    double fils[12];
    int i = 0;

    for(i = 0; i < 12; i++){
      fils[i] = 0;
    }

    query3fatFil(sgv->faturacao, productID, month, fils);
    printR4(fils);
  }
  return sgv;
}

Array getProductsNeverBought(SGV sgv, int branchID){
  Array a = initArray();
  a = query4Fat(sgv->faturacao, a, branchID);
  return a;
}

Array getClientsOfAllBranches(SGV sgv){
  Array a = initArray();
  clToArray(sgv->catClientes,a);

  Array r = initArray();
  query5Fil(sgv->filiais,getArray(a),getTam(a),r);
  freeArray(a);
  return r;
}


Pair getClientsAndProductsNeverBoughtCount(SGV sgv){
  int a1 = query6Prod(sgv->catProds);
  int a2 = query6Cli(sgv->catClientes);

  Pair p = initPair(a1, a2);

  return p;
}


int* getProductsBoughtByClient(SGV sgv, char* clientID){
  int* r = malloc(sizeof(int)*36);
  int i;
  for( i = 0; i < 36; i++ ) r[i] = 0;

  query7Fil(r,sgv->filiais,clientID);

  return r;
}


Pair2 getSalesAndProfit(SGV sgv, int minMonth, int maxMonth){
  int vendas = 0;
  double totalFat = 0;

  query8Fat(sgv->faturacao, minMonth, maxMonth, &vendas, &totalFat);
  Pair2 p = initPair2(vendas, totalFat);

  return p;
}


Cods getProductBuyers (SGV sgv, char* productID, int branch){
  Cods codigos = initCods();

  query9F(branch,productID,sgv->filiais,codigos);

  return codigos;
}


Array2 getClientFavoriteProducts(SGV sgv, char* clientID, int month){
  Array2 a = initArray2();
  a = query10Fil(a, sgv->filiais, month, clientID);
  a = sortArray2Dec(a);
  return a;
}

Array4 getTopSelledProducts(SGV sgv, int limit){
  Array2 array = initArray2();

  array = query11Fat(sgv->faturacao, array);
  array = sortArray2Dec(array);
  array = freeArray2Tam(array, limit);

  Array4 ar = initArray4(limit);
  ar = preencheProdutosArray4(ar, array);
  freeArray2(array);
  ar = query11Fil(sgv->filiais, ar, limit);

  return ar;
}

Array3 getClientTopProfitProducts(SGV sgv, char* clientID, int limit){
  Array3 ar = initArray3();
  ar = query12Fil(ar, sgv->filiais, clientID);
  ar = sortArray3Dec(ar);
  ar = freeArray3Tam(ar, limit);
  return ar;
}

/*Queries*/

SGV query1(SGV gestor){
  char c[MAXBUFSIZE];

  printQ1A();
  scanf(" ");
  fgets(c, MAXBUFSIZE, stdin);
  if(strlen(c)>2) printErro();
  switch(c[0]){
    case 'd': {
      if(gestor != NULL) destroySGV(gestor);
      gestor = initSGV();
      printQ1Def();
      gestor = loadSGVFromFiles(gestor, "Clientes.txt", "Produtos.txt", "Vendas_1M.txt");
      break;
    }
    case 'n':{
      if(gestor != NULL) destroySGV(gestor);
      gestor = initSGV();
      printQ1B();

      fgets(c, MAXBUFSIZE, stdin);
      c[strlen(c)-1] = '\0';
      char* produtos = strdup(c);

      fgets(c, MAXBUFSIZE, stdin);
      c[strlen(c)-1] = '\0';
      char* clientes = strdup(c);

      fgets(c, MAXBUFSIZE, stdin);
      c[strlen(c)-1] = '\0';
      char* vendas = strdup(c);

      gestor = loadSGVFromFiles(gestor, clientes, produtos, vendas);

      free(produtos);
      free(clientes);
      free(vendas);

      break;
    }
    default: {
      printErro();
    }
  }
  if(gestor!=NULL) printQ1C();
  return gestor;
}

SGV query2(SGV gestor){
  char b[MAXBUFSIZE];
  printQ2A();
  scanf(" ");
  fgets(b, MAXBUFSIZE, stdin);

  if(b[0] < 'A' || b[0] > 'Z') printErro();
  else{
    Array a = getProductStartedByLetter(gestor, b[0]);
    printQ2B(getArray(a), getTam(a), 0, getBashHeight());
    int t = 0;
    while(1){
      scanf(" ");
      fgets(b, MAXBUFSIZE, stdin);
      switch(b[0]){
        case 's':{
          if((t+1)*getBashHeight() < getTam(a))t++;
          printQ2B(getArray(a), getTam(a), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'a':{
          if(t>0) t--;
          printQ2B(getArray(a), getTam(a), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'q':{
          freeArray(a);
          return gestor;
        }
      }
    }
  }
  return gestor;
}

SGV query3(SGV gestor){
  char mes[MAXBUFSIZE];
  char prod[MAXBUFSIZE];

  printQ3A();
  scanf(" ");
  fgets(mes, MAXBUFSIZE, stdin);
  if(!(atoi(mes) > 0 && atoi(mes) <= 12)) { printErro(); return gestor; }

  printQ3B();
  fgets(prod, MAXBUFSIZE, stdin);
  strtok(prod, "\n");
  if(validaProduto(prod) == false) { printErro(); return gestor; }

  printQ3C();

  gestor = getProductSalesAndProfit(gestor, prod, atoi(mes));
  return gestor;
}

SGV query4(SGV gestor){
  char b[MAXBUFSIZE];
  printQ4();
  scanf(" ");
  fgets(b, MAXBUFSIZE, stdin);
  if(b[0] != '1' && b[0] != '2' && b[0] != '3') printErro();
  else{
    Array ap = getProductsNeverBought(gestor, b[0]-'0');
    printQ2B(getArray(ap), getTam(ap), 0, getBashHeight());
    int t = 0;
    while(1){
      scanf(" ");
      fgets(b, MAXBUFSIZE, stdin);
      switch(b[0]){
        case 's':{
          if((t+1)*getBashHeight() < getTam(ap))t++;
          printQ2B(getArray(ap), getTam(ap), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'a':{
          if(t>0) t--;
          printQ2B(getArray(ap), getTam(ap), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'q':{
          freeArray(ap);
          return gestor;
        }
      }
    }
  }
  return gestor;
}

SGV query5(SGV gestor){
  char b[MAXBUFSIZE];
  Array clientes = getClientsOfAllBranches(gestor);

    printQ2B(getArray(clientes), getTam(clientes), 0, getBashHeight());
    int t = 0;
    while(1){
      scanf(" ");
      fgets(b, MAXBUFSIZE, stdin);
      switch(b[0]){
        case 's':{
          if((t+1)*getBashHeight() < getTam(clientes))t++;
          printQ2B(getArray(clientes), getTam(clientes), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'a':{
          if(t>0) t--;
          printQ2B(getArray(clientes), getTam(clientes), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'q':{
          freeArray(clientes);
          return gestor;
        }
      }
    }
  freeArray(clientes);
  return gestor;
}

SGV query6(SGV gestor){
  char b[MAXBUFSIZE];
  Pair p = getClientsAndProductsNeverBoughtCount(gestor);
  printQ6(getX(p), getY(p));
  freePair(p);
  return gestor;
}

SGV query7(SGV gestor){
  printQ7();
  char cod[MAXBUFSIZE];

  char* cliente = (char*)malloc(sizeof(char) * 10);
  scanf(" ");
  fgets(cliente,10,stdin);
  cliente[5]='\0';
  if(!existeCliente(cliente,gestor->catClientes)) {printErro(); return gestor;}

  int* f = getProductsBoughtByClient(gestor,cliente);

  printQ7R(f);
  printQ7F();
  char b[MAXBUFSIZE];
  scanf(" ");
  fgets(b,MAXBUFSIZE,stdin);

  free(cliente);
  free(f);
  return gestor;
}

SGV query8(SGV gestor){
  char mesInicio[MAXBUFSIZE];
  char mesFim[MAXBUFSIZE];
  int mesI;
  int mesF;

  printQ8A();
  scanf(" ");
  fgets(mesInicio, MAXBUFSIZE, stdin);
  mesI = atoi(mesInicio);

  if(!(mesI >= 1 && mesI <= 12)) { printErro(); }
  else{
    printQ8B();
    scanf(" ");
    fgets(mesFim, MAXBUFSIZE, stdin);
    mesF = atoi(mesFim);

    if(!(mesF >= 1 && mesF <= 12) || (mesF < mesI)) { printErro(); }
    else{
      Pair2 p = getSalesAndProfit(gestor, mesI, mesF);
      print8R(mesI, mesF, getX2(p), getY2(p));
      freePair2(p);
    }
  }
  return gestor;
}

SGV query9(SGV gestor){
  char* prod = (char*)malloc(sizeof(char) * 10);
  printQ9C();
    scanf(" ");
    fgets(prod,10,stdin);
    prod[6]='\0';
    if(!existeProduto(prod,gestor->catProds)){printErro(); return gestor;}
    printQ9F();
    int f;
    char b[MAXBUFSIZE];
    scanf(" ");
    fgets(b,MAXBUFSIZE, stdin);
    f = atoi(b);
    if(f <1 || f>3) {printErro(); return gestor;}

    Cods R = getProductBuyers( gestor, prod, f);

    char** cN = getCodsN(R);
    char** cP = getCodsP(R);
    int tN = getN(R), tP = getP(R);

    printQ9R(tN,tP,cN,cP);

    free(prod);
    freeCods(R);
    return gestor;
}

SGV query10(SGV gestor){
  int mes;
  char* cliente = (char*)malloc(sizeof(char*));
  char b[MAXBUFSIZE];

  printQ10B();
  scanf(" ");
  fgets(b, MAXBUFSIZE, stdin);
  if(atoi(b) >= 1 && atoi(b) <= 12){
    mes = atoi(b);
    printQ10A();
    scanf(" ");
    fgets(cliente, 10, stdin);
    cliente[5] = '\0';
    if(!existeCliente(cliente,gestor->catClientes)){printErro();return gestor;}
    Array2 ar = getClientFavoriteProducts(gestor, cliente, mes);
    printQ10C(getArray2C(ar), getArray2I(ar), getTam2(ar), 0, getBashHeight());
    int t = 0;
    while(1){
      scanf(" ");
      fgets(b, MAXBUFSIZE, stdin);
      switch(b[0]){
        case 's':{
          if((t+1)*getBashHeight() < getTam2(ar))t++;
          printQ10C(getArray2C(ar), getArray2I(ar), getTam2(ar), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'a':{
          if(t>0) t--;
          printQ10C(getArray2C(ar), getArray2I(ar), getTam2(ar), t * getBashHeight(), (t+1) * getBashHeight());
          break;
        }
        case 'q':{
          freeArray2(ar);
          free(cliente);
          return gestor;
        }
      }
    }
  }
  else{
    printErro();
    free(cliente);
    return gestor;
  }
}

SGV query11(SGV gestor){
  char p[MAXBUFSIZE];
  int tamanho;

  printQ11();
  scanf(" ");
  fgets(p, MAXBUFSIZE, stdin);
  tamanho = atoi(p);
  Array4 ar = getTopSelledProducts(gestor, tamanho);

  print11RA(tamanho);

  print11RB(getArray4C(ar), getArray4Fil(ar, 1), getArray4Fil(ar, 2), getArray4Fil(ar, 3), getTam4(ar), 0, getBashHeight());
  int t = 0;
  while(1){
    scanf(" ");
    fgets(p, MAXBUFSIZE, stdin);
    switch(p[0]){
      case 's':{
        if((t+1)*getBashHeight() < getTam4(ar))t++;
        print11RB(getArray4C(ar), getArray4Fil(ar, 1), getArray4Fil(ar, 2), getArray4Fil(ar, 3), getTam4(ar), t * getBashHeight(), (t+1) * getBashHeight());
        break;
      }
      case 'a':{
        if(t>0) t--;
        print11RB(getArray4C(ar), getArray4Fil(ar, 1), getArray4Fil(ar, 2), getArray4Fil(ar, 3), getTam4(ar), t * getBashHeight(), (t+1) * getBashHeight());
        break;
      }
      case 'q':{
        freeArray4(ar);
        return gestor;
      }
    }
  }
}

SGV query12(SGV gestor){
  char b[MAXBUFSIZE];
  char* cliente = (char*)malloc(sizeof(char) * 10);
  int n;
  printQ10A();
  scanf(" ");
  fgets(cliente,10,stdin);
  cliente[5] = '\0';
  if(!existeCliente(cliente,gestor->catClientes)){printErro();return gestor;}
  printQ12A();
  scanf(" ");
  fgets(b,MAXBUFSIZE, stdin);
  if(atoi(b) != 0){
    n = atoi(b);
    Array3 ar = getClientTopProfitProducts(gestor, cliente, n);
    printQ12(getArray3C(ar), getArray3R(ar), getTam3(ar), 0, getBashHeight() - 1);
    int t = 0;
    while(1){
      scanf(" ");
      fgets(b, MAXBUFSIZE, stdin);
      switch(b[0]){
        case 's':{
          if((t+1)*getBashHeight() < getTam3(ar))t++;
          printQ12(getArray3C(ar), getArray3R(ar), getTam3(ar), t * getBashHeight(), (t+1) * getBashHeight() - 1);
          break;
        }
        case 'a':{
          if(t>0) t--;
          printQ12(getArray3C(ar), getArray3R(ar), getTam3(ar), t * getBashHeight(), (t+1) * getBashHeight() - 1);
          break;
        }
        case 'q':{
          free(cliente);
          freeArray3(ar);
          return gestor;
        }
      }
    }
  }
  else{printErro(); return gestor;}
}

SGV query13(SGV gestor){
  FI info = getCurrentFilesInfo(gestor);
  printQ13(info->tp, info->tc, info->tv, info->vp, info->vc, info->vv, info->prodsPath, info->cliPath, info->vendaPath);
  return gestor;
}

SGV menu(SGV gestor){
  char c[MAXBUFSIZE];
  printMenu();
  if(!gestor) printAviso();
  fgets(c, MAXBUFSIZE, stdin);
  switch(c[0]){
    case '1' : {
      switch(c[1]){
        case '\n' : gestor = query1(gestor);  break;
        case '0'  : gestor = query10(gestor); break;
        case '1'  : gestor = query11(gestor); break;
        case '2'  : gestor = query12(gestor); break;
        case '3'  : gestor = query13(gestor); break;
        deafult   : printErro();
      }
      break;
    }
    case '2' : gestor = query2(gestor); break;
    case '3' : gestor = query3(gestor); break;
    case '4' : gestor = query4(gestor); break;
    case '5' : gestor = query5(gestor); break;
    case '6' : gestor = query6(gestor); break;
    case '7' : gestor = query7(gestor); break;
    case '8' : gestor = query8(gestor); break;
    case '9' : gestor = query9(gestor); break;
    case 'q' : return NULL;
    default : printErro();
  }
  return gestor;
}

int main(){
  SGV gestor = NULL;
  do{
    gestor = menu(gestor);
  }while(gestor);
  destroySGV(gestor);
  return 0;
}
