#include "../../include/model/clientes.h"

/*Estruturas principais deste módulo - AVL Binary Trees e uma Hash Table*/

struct avlClientes
{
  char* codCliente;
  bool comprou;
  int bal;
  struct avlClientes *left, *right;
};

struct hashClientes
{
  AVLClientes* listaAVLClientes;
};

/*Funções auxiliares de impressão*/

void inOrderC(AVLClientes clientes){
  if(clientes != NULL){
    inOrderC(clientes->left);
    printf("%s\n", clientes->codCliente);
    inOrderC(clientes->right);
  }
}

void hashInOrderC(CatClientes clientes){
  if(clientes != NULL){
    int i;
    for(i = 0; i < 26; i++){
      if((clientes->listaAVLClientes)[i]){
        inOrderC((clientes->listaAVLClientes)[i]);
      }
    }
  }
}

bool existeClienteAux(char* cod, AVLClientes ap){
  if(ap != NULL){
    int c = strcmp(cod, ap->codCliente);
    if(c == 0){
      return true;
    }
    else{
      if(c > 0) return existeClienteAux(cod, ap->right);
      else return existeClienteAux(cod, ap->left);

    }
  }
  else return false;
}

bool existeCliente(char* cod, CatClientes cp){
  int l = hashC(cod);
  return existeClienteAux(cod, (cp->listaAVLClientes)[l]);
}

void updateExisteCAux(AVLClientes ap, char* cod){
  if(ap != NULL){
    int c = strcmp(cod, ap->codCliente);
    if(c == 0){
      ap->comprou = true;
    }
    else{
      if(c > 0) return updateExisteCAux(ap->right, cod);
      else return updateExisteCAux(ap->left, cod);
    }
  }
}

void updateExisteC(CatClientes c, char* cod){
  updateExisteCAux((c->listaAVLClientes)[hashC(cod)], cod);
}


/*Funções auxiliares, nomeadamente hashes e validações*/

bool validaCliente(char* cliente){
  int codigo = atoi(cliente+1);

  if(codigo < 1000 || codigo > 5000 || cliente[0] < 'A' || cliente [0] > 'Z' || cliente[5]) return false;
  else return true;
}

int hashC(char* clientes){
  return clientes[0]-65;
}

/*query 5*/

void clToArrayAux(AVLClientes c, Array r){
  if(c != NULL){
    clToArrayAux(c->left,r);
    if(c->comprou == true) addToArray(r,c->codCliente);
    clToArrayAux(c->right,r);
  }
}

Array clToArray(CatClientes c, Array r){
  int i;
  for(i=0; i<26; i++)
    clToArrayAux(c->listaAVLClientes[i],r);
  return r;
}


/*query 6*/
void query6CliAux(AVLClientes a, int *i){
  if(a != NULL){
    query6CliAux(a->left, i);
    if(a->comprou == false) (*i)++;
    query6CliAux(a->right, i);
  }
}

int query6Cli(CatClientes c){
  int s = 0, i;
  for(i = 0; i < 26; i++){
    query6CliAux((c->listaAVLClientes)[i], &s);
  }
  return s;
}




/*Preenchimento de Árvores/Hash Tables*/

AVLClientes rotateLeftC (AVLClientes b) {
	AVLClientes a = b->right;
	b->right = a->left;
	a->left = b;
	return a;
}

AVLClientes rotateRightC (AVLClientes a) {
	AVLClientes b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

AVLClientes fixRightC (AVLClientes clientes) {
	AVLClientes b, c;
	b = clientes->right;
	if (b->bal == RIGHT) {
		clientes->bal = b->bal = BAL;
		clientes = rotateLeftC(clientes);
	} else {
		c = b->left;
		switch (c->bal) {
			case LEFT:  clientes->bal = BAL;
					    b->bal = RIGHT;
					    break;
		    case RIGHT: clientes->bal = LEFT;
		    			b->bal = BAL;
		    			break;
		    case BAL:   clientes->bal = b->bal = BAL;
		}
		c->bal = BAL;
		clientes->right = rotateRightC(b);
		clientes = rotateLeftC(clientes);
	}
	return clientes;
}

AVLClientes fixLeftC (AVLClientes clientes) {
	AVLClientes b, c;
	b = clientes->left;
	if (b->bal == LEFT) {
		clientes->bal = b->bal = BAL;
		clientes = rotateRightC(clientes);
	} else {
		c = b->right;
		switch (c->bal) {
			case LEFT:  clientes->bal = RIGHT;
					    b->bal = BAL;
					    break;
		    case RIGHT: clientes->bal = BAL;
		    			b->bal = LEFT;
		    			break;
		    case BAL:   clientes->bal = b->bal = BAL;
		}
		c->bal = BAL;
		clientes->left = rotateLeftC (b);
		clientes = rotateRightC(clientes);
	}
	return clientes;
}

AVLClientes insertAVLClienteRec(AVLClientes clientes, char* cliente, int *g, int *u) {
  if (clientes == NULL) {
		clientes = (AVLClientes)malloc(sizeof(struct avlClientes));
		clientes->codCliente = strdup(cliente);
    clientes->comprou = false;
		clientes->bal = BAL;
		clientes->left = clientes->right = NULL;
		*g = 1; *u = 0;
	}
  if (strcmp((clientes->codCliente), cliente) != 0){
    if (strcmp((clientes->codCliente), cliente) > 0) {
  		clientes->left = insertAVLClienteRec(clientes->left, cliente, g, u);
  		if (*g == 1)
  			switch (clientes->bal) {
  				case LEFT:  clientes = fixLeftC(clientes); *g = 0; break;
  				case BAL:   clientes->bal = LEFT; break;
  				case RIGHT: clientes->bal = BAL; *g = 0; break;
  			}
  	} else  {
  		clientes->right = insertAVLClienteRec(clientes->right, cliente, g, u);
  		if (*g == 1)
  			switch (clientes->bal) {
  				case RIGHT: clientes = fixRightC(clientes); *g = 0; break;
  				case BAL:   clientes->bal = RIGHT; break;
  				case LEFT:  clientes->bal = BAL; *g = 0; break;
  			}
      }
  }
	return clientes;
}

AVLClientes insertAVLCliente(AVLClientes *clientes, char* cliente) {
  int g, u;
  *clientes = insertAVLClienteRec(*clientes, cliente, &g, &u);
  return *clientes;
}

CatClientes insertCatClientes(CatClientes cc, char* cliente){
  int hash = hashC(cliente);
  (cc->listaAVLClientes)[hash] = insertAVLCliente(&(cc->listaAVLClientes)[hash], cliente);
  return cc;
}

/*Esvaziar Árvores e Hash Tables*/

void freeAVLClientes(AVLClientes avlClientes){
  if(avlClientes != NULL){
    freeAVLClientes(avlClientes->left);
    freeAVLClientes(avlClientes->right);
    free(avlClientes->codCliente);
    free(avlClientes);
  }
}

void freeCatClientes(CatClientes cc){
  int i;
  for(i = 0; i < 26; i++){
    freeAVLClientes((cc->listaAVLClientes)[i]);
  }
  free(cc->listaAVLClientes);
  free(cc);
}

/*Inicilização das Estruturas*/

CatClientes initCatClientes(){

  CatClientes catC = (CatClientes)malloc(sizeof(struct hashClientes));
  catC->listaAVLClientes = (AVLClientes*)malloc(sizeof(struct avlClientes) * 26);
  int i;
  for(i = 0; i < 26; i++){
    (catC->listaAVLClientes)[i] = NULL;
  }

  return catC;
}
