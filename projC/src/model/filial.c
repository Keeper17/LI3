#include "../../include/model/filial.h"


struct info{
  char* codProd;
  int qnt;
  float preco;
  int mes;
  char* tipo;
};

struct avlFilial{
	struct info **f;
  int t;
  char* cliente;
	int bal;
	struct avlFilial *left, *right;
};

struct filiais{
	AVLFil* filiais;
};

int hashFil(char* c){
  return c[0]-65;
}

Fil* initFil ( char* campos[]){
	Fil* f = (struct info**)malloc(sizeof(struct info*));
  f[0] = (struct info*)malloc(sizeof(struct info));
	f[0] -> codProd = strdup(campos[0]);
	f[0] -> qnt = atoi(campos[2]);
	f[0] -> preco = atof(campos[1]);
  f[0] -> mes = atoi(campos[5]);
  f[0] -> tipo = strdup(campos[3]);

	return f;
}

Fil* addInfo(Fil* f, char* campos[], int size){
  f = (struct info**)realloc(f, (size+1) * sizeof(struct info*));
  f[size] = (struct info*)malloc(sizeof(struct info));
  f[size] -> codProd = strdup(campos[0]);
	f[size] -> qnt = atoi(campos[2]);
	f[size] -> preco = atof(campos[1]);
  f[size] -> mes = atoi(campos[5]);
  f[size] -> tipo = strdup(campos[3]);
  return f;
}

/*-----------------------------------------------------------------*/

AVLFil rotateLeftFil (AVLFil b) {
	AVLFil a = b->right;
	b->right = a->left;
	a->left = b;
	return a;
}

AVLFil rotateRightFil (AVLFil a) {
	AVLFil b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

AVLFil fixRightFil (AVLFil f) {
	AVLFil b, c;
	b = f->right;
	if (b->bal == RIGHT) {
		f->bal = b->bal = BAL;
		f = rotateLeftFil(f);
	} else {
		c = b->left;
		switch (c->bal) {
			case LEFT:  f->bal = BAL;
					    b->bal = RIGHT;
					    break;
		    case RIGHT: f->bal = LEFT;
		    			b->bal = BAL;
		    			break;
		    case BAL:   f->bal = b->bal = BAL;
		}
		c->bal = BAL;
		f->right = rotateRightFil(b);
		f = rotateLeftFil(f);
	}
	return f;
}

AVLFil fixLeftFil (AVLFil fil) {
	AVLFil b, c;
	b = fil->left;
	if (b->bal == LEFT) {
		fil->bal = b->bal = BAL;
		fil = rotateRightFil(fil);
	} else {
		c = b->right;
		switch (c->bal) {
			case LEFT:  fil->bal = RIGHT;
					    b->bal = BAL;
					    break;
		    case RIGHT: fil->bal = BAL;
		    			b->bal = LEFT;
		    			break;
		    case BAL:   fil->bal = b->bal = BAL;
		}
		c->bal = BAL;
		fil->left = rotateLeftFil(b);
		fil = rotateRightFil(fil);
	}
	return fil;
}

/*-----------------------------------------------------------------*/

AVLFil insertFilRec(AVLFil fl, char* campos[], int *g, int *u){
	if (fl == NULL){
		fl = (AVLFil)malloc(sizeof(struct avlFilial));
		fl -> f = initFil(campos);
    fl -> cliente = strdup(campos[4]);
		fl -> bal = BAL;
    fl->t = 1;
		fl -> right = fl -> left = NULL;
		*g = 1; *u = 0;
	}

  else{
    if (strcmp((fl->cliente),campos[4]) == 0){
      fl->f = addInfo(fl->f, campos, fl->t);
      (fl->t)++;
    }else{
      if(strcmp((fl->cliente),campos[4]) > 0){
        fl->left = insertFilRec(fl->left, campos, g, u);
  			if (*g == 1)
  				switch (fl->bal){
  					case LEFT:  fl = fixLeftFil(fl); *g = 0; break;
  					case BAL:   fl->bal = LEFT; break;
  					case RIGHT: fl->bal = BAL; *g = 0; break;
  				}
  		} else {
  			fl->right = insertFilRec(fl->right, campos, g, u);
  			if(*g == 1)
  				switch(fl->bal){
  					case RIGHT: fl = fixRightFil(fl); *g=0; break;
  					case BAL:   fl->bal = RIGHT; break;
  					case LEFT:  fl->bal = BAL; *g = 0; break;
  				}
  		}
    }
  }
	return fl;
}

AVLFil insertFil(AVLFil *f, char* campos[]){
	int g, u;
	*f = insertFilRec(*f, campos, &g, &u);
  return *f;
}

FilHash insertFilHash(FilHash f, char* campos[]){
  int filial = atoi(campos[6]);
  int cliente = hashFil(campos[4]);
  (f->filiais)[(filial-1) * 26 + cliente] = insertFil(&( (f->filiais)[(filial-1) * 26 + cliente]), campos);
  return f;
}

FilHash initFilHash(){
	FilHash f = (FilHash)malloc(sizeof(struct filiais));
  (f->filiais) = (struct avlFilial**)malloc(sizeof(struct avlFilial) * 26 * 3);
  int j;
  for(j = 0; j < 26 * 3; j++){
    (f->filiais)[j] = NULL;
  }
  return f;
}
/*------------- Query 5 --------------------------------------------*/

bool pertenceFil(AVLFil a, char* cod){
	if( a != NULL){
		pertenceFil(a->left,cod);
		int c = strcmp(cod, a->cliente);
		if(c == 1) return true;
		if(c < 0) return false;
		pertenceFil(a->right,cod);
	}
	return false;
}

bool query5Aux(FilHash fil, char* cod){
	bool res = false;
	int p = hashFil(cod);
	bool f1,f2,f3;
	f1 = pertenceFil((fil->filiais)[p],cod);
	f2 = pertenceFil((fil->filiais)[26+p],cod);
	f3 = pertenceFil((fil->filiais)[52+p],cod);

	if(f1 == f2 == f3 == true) return true;
}

void query5Fil(FilHash fil, char** ar, int c, Array res){
  int i;
	for(i = 0; i<c; i++){
		bool r = query5Aux(fil,ar[i]);
		if(r == true) addToArray(res,ar[i]);
	}

}


/*------------- Query 7 -------------------------------------------*/

int* filFil(int* a, AVLFil fil, char* c,int nf){
  if( fil != NULL){
    a = filFil(a, fil->left, c, nf);

    if(strcmp(c,(fil->cliente)) == 0){
      int m, q, i;
      int k = fil->t;
      for(i = 0; i<k; i++){
        m = (fil->f)[i]->mes;
        q = (fil->f)[i]->qnt;
        a[(m+12*nf)-1] += q;
      }
    }
    a = filFil(a, fil->right, c, nf);
  }
  return a;
}


void query7Fil(int* r,FilHash fil,char* cod){
  int p = hashFil(cod);
  int i;
  for(i=0;i<3;i++)
    filFil(r, (fil->filiais)[p+26*i], cod,i);

}


/*------------- Query 9 --------------------------------------------*/

void query9Aux(AVLFil avl, char* codP, Cods N){
  if(avl != NULL){
    query9Aux(avl->left,codP,N);

      int k = avl->t, i;
      for(i = 0; i<k; i++){
        if(strcmp( (avl->f)[i]->codProd, codP ) == 0){
          char* c = (avl->f)[i]->tipo;
          if( strcmp(c,"N") == 0 ) addToCodsN(N,avl->cliente);
          if( strcmp(c,"P") == 0 ) addToCodsP(N,avl->cliente);
        }
      }
    query9Aux(avl->right,codP,N);
  }
}

void query9F(int f, char* codP, FilHash fil, Cods N){
  int i;

    for(i=0; i<26; i++)
      query9Aux((fil->filiais)[f*26 + i],codP,N);
}


/*------------- Query 10 -------------------------------------------*/

Array2 query10FilAux(Array2 ar, AVLFil avl, int mes, char* cliente){
  if(avl != NULL){
    if(strcmp((avl->cliente), cliente) == 0){
      int i;
      for(i = 0; i < avl->t; i++){
        if(mes == (avl->f)[i]->mes){
          ar = addToArray2(ar, (avl->f)[i]->codProd, (avl->f)[i]->qnt);
        }
      }
    }
    else
    {
      if(strcmp((avl->cliente), cliente) > 0)
        ar = query10FilAux(ar, avl->left, mes, cliente);
      else
        ar = query10FilAux(ar, avl->right, mes, cliente);
    }
  }
  return ar;
}

Array2 query10Fil(Array2 ar, FilHash f, int mes, char* cliente){
  int cod = hashFil(cliente);
  int i;
  for(i = 0; i <= 2; i++){
    ar = query10FilAux(ar, (f->filiais)[i * 26 + cod], mes, cliente);
  }
  return ar;
}

/*------------- Query 11 -------------------------------------------*/

Array4 query11FilAux(AVLFil avl, Array4 ar, int tamanho, int fil){
  bool flag = false;

  if(avl != NULL){
    ar = query11FilAux(avl->left, ar, tamanho, fil);
    int i, j;
    for(j = 0; j < tamanho; j++){
      for(i = 0; i < avl->t; i++){
        if(verificaProdArray4(ar, avl->f[i]->codProd, j)){
          if(fil == 1){
            if(flag == false) { ar = adicionaCliFil(ar, j, 1); flag = true; }
            ar = adicionaQntFil(ar, avl->f[i]->qnt, j, 1);
          }
          else if(fil == 2){
            if(flag == false) { ar = adicionaCliFil(ar, j, 2); flag = true; }
            ar = adicionaQntFil(ar, avl->f[i]->qnt, j, 2);
          }
          else{
            if(flag == false) { ar = adicionaCliFil(ar, j, 3); flag = true; }
            ar = adicionaQntFil(ar, avl->f[i]->qnt, j, 3);
          }
        }
      }
    }

    ar = query11FilAux(avl->right, ar, tamanho, fil);
  }
  return ar;
}

Array4 query11Fil(FilHash f, Array4 ar, int tamanho){
  int i;
  for(i = 0; i < 26; i++){
    ar = query11FilAux(f->filiais[i], ar, tamanho, 1);
  }
  for(i = 26; i < 26*2; i++){
    ar = query11FilAux(f->filiais[i], ar, tamanho, 2);
  }
  for(i=26*2; i < 26*3; i++){
    ar = query11FilAux(f->filiais[i], ar, tamanho, 3);
  }
}


/*------------- Query 12 -------------------------------------------*/

Array3 query12FilAux(Array3 ar, AVLFil a, char* cliente){
  if(a != NULL){
    if(strcmp((a->cliente), cliente) == 0){
      int i;
      for(i = 0; i < a->t; i++){
          float tot = (float)((a->f)[i]->qnt) * (a->f)[i]->preco;
          ar = addToArray3(ar, (a->f)[i]->codProd, tot);
      }
  }
  else
  {
    if(strcmp((a->cliente), cliente) > 0)
      ar = query12FilAux(ar, a->left, cliente);
    else
      ar = query12FilAux(ar, a->right, cliente);
  }
}
  return ar;
}

Array3 query12Fil(Array3 ar, FilHash f, char* cliente){
  int cod = hashFil(cliente), i;
  for(i = 0; i <= 2; i++){
    ar = query12FilAux(ar, (f->filiais)[i * 26 + cod], cliente);
  }
  return ar;
}

/*Esvaziar Árvores e Hash Tables e infos*/

void freeInfo(AVLFil fil,int t){
  int i;
  for( i=0; i<t; i++){
    free((fil->f)[i]->codProd);
    free((fil->f)[i]->tipo);
  }
  free(fil->f);
}


void freeAVLFil(AVLFil avlF){
  if(avlF != NULL){
    freeAVLFil(avlF->left);
    freeAVLFil(avlF->right);
    freeInfo(avlF,avlF->t);
    free(avlF->cliente);
    free(avlF);
  }
}

void freeFilHash(FilHash f){
  int i,j;
  for(i = 0; i < 26*3; i++)
    freeAVLFil((f->filiais)[i]);
  free(f->filiais);
  free(f);
}
