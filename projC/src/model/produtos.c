#include "../../include/model/produtos.h"

/*Estruturas principais deste módulo - AVL Binary Trees e uma Hash Table*/

struct avlProdutos
{
  char* produto;
  bool comprado;
  int bal;
  struct avlProdutos *left, *right;
};

struct hashProdutos
{
  AVLProds* listaAVLProds;
};

/*Funções auxiliares de impressão*/

void inOrderP(AVLProds prods){
  if(prods != NULL){
    inOrderP(prods->left);
    printf("%s\n", prods->produto);
    inOrderP(prods->right);
  }
}

void hashInOrderP(CatProds prods){
  if(prods != NULL){
    int i;
    for(i = 0; i < 26; i++){
      printf("%d\n", i);
      if((prods->listaAVLProds)[i]){
        inOrderP((prods->listaAVLProds)[i]);
      }
    }
  }
}

/*Funções auxiliares, nomeadamente hashes e validações*/

bool validaProduto(char* produto){
  int codigo = atoi(produto+2);

  if(produto[0] < 'A' || produto[1] < 'A' || produto[1] > 'Z' || produto[0] > 'Z' || codigo < 1000 || codigo > 9999 || produto[6])
    return false;
  else
    return true;
}

int hashP(char* produto){
  return produto[0]-65;
}

/*Funções de procura para as queries*/

bool existeProdutoAux(char* cod, AVLProds ap){
  if(ap != NULL){
    int c = strcmp(cod, ap->produto);
    if(c == 0){
      return true;
    }
    else{
      if(c > 0) return existeProdutoAux(cod, ap->right);
      else return existeProdutoAux(cod, ap->left);

    }
  }
  else return false;
}

bool existeProduto(char* cod, CatProds cp){
  int l = hashP(cod);
  return existeProdutoAux(cod, (cp->listaAVLProds)[l]);
}

void updateExistePAux(AVLProds ap, char* cod){
  if(ap != NULL){
    int c = strcmp(cod, ap->produto);
    if(c == 0){
      ap->comprado = true;
    }
    else{
      if(c > 0) return updateExistePAux(ap->right, cod);
      else return updateExistePAux(ap->left, cod);
    }
  }
}

void updateExisteP(CatProds c, char* cod){
  updateExistePAux((c->listaAVLProds)[hashP(cod)], cod);
}

/*Query 2*/

Array query2ProdAux(AVLProds a, Array ar){
  if(a != NULL){
    ar = query2ProdAux(a->left, ar);
    ar = addToArray(ar, a->produto);
    ar = query2ProdAux(a->right, ar);
  }
  return ar;
}

Array query2Prod(CatProds c, char a, Array ar){
  int p = a-65;
  ar = query2ProdAux((c->listaAVLProds)[p], ar);
  return ar;
}

/*Query 4*/

Array query4ProdAux(AVLProds a, Array ar){
  if(a != NULL){
    ar = query4ProdAux(a->left, ar);
    if(a->comprado == true) ar = addToArray(ar, a->produto);
    ar = query4ProdAux(a->right, ar);
  }
  return ar;
}

Array query4Prod(CatProds c, Array ar){
  int i;
  for(i = 0; i < 26; i++){
    ar = query4ProdAux((c->listaAVLProds)[i], ar);
  }
  return ar;
}

/*Query 6*/

void query6ProdAux(AVLProds a, int *s){
  if(a != NULL){
    query6ProdAux(a->left, s);
    if(a->comprado == false) (*s)++;
    query6ProdAux(a->right, s);
  }
}

int query6Prod(CatProds c){
  int s = 0, i;
  for(i = 0; i < 26; i++){
    query6ProdAux((c->listaAVLProds)[i], &s);
  }
  return s;
}

/*Preenchimento de Árvores/Hash Tables*/

AVLProds rotateLeftP (AVLProds b) {
	AVLProds a = b->right;
	b->right = a->left;
	a->left = b;
	return a;
}

AVLProds rotateRightP (AVLProds a) {
	AVLProds b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

AVLProds fixRightP (AVLProds prods) {
	AVLProds b, c;
	b = prods->right;
	if (b->bal == RIGHT) {
		prods->bal = b->bal = BAL;
		prods = rotateLeftP(prods);
	} else {
		c = b->left;
		switch (c->bal) {
			case LEFT:  prods->bal = BAL;
					    b->bal = RIGHT;
					    break;
		    case RIGHT: prods->bal = LEFT;
		    			b->bal = BAL;
		    			break;
		    case BAL:   prods->bal = b->bal = BAL;
		}
		c->bal = BAL;
		prods->right = rotateRightP(b);
		prods = rotateLeftP(prods);
	}
	return prods;
}

AVLProds fixLeftP (AVLProds prods) {
	AVLProds b, c;
	b = prods->left;
	if (b->bal == LEFT) {
		prods->bal = b->bal = BAL;
		prods = rotateRightP(prods);
	} else {
		c = b->right;
		switch (c->bal) {
			case LEFT:  prods->bal = RIGHT;
					    b->bal = BAL;
					    break;
		    case RIGHT: prods->bal = BAL;
		    			b->bal = LEFT;
		    			break;
		    case BAL:   prods->bal = b->bal = BAL;
		}
		c->bal = BAL;
		prods->left = rotateLeftP (b);
		prods = rotateRightP(prods);
	}
	return prods;
}

AVLProds insertAVLProdutoRec(AVLProds prods, char* prod, int *g, int *u) {
  if (prods == NULL) {
		prods = (AVLProds)malloc(sizeof(struct avlProdutos));
		prods->produto = strdup(prod);
    prods->comprado = false;
		prods->bal = BAL;
		prods->left = prods->right = NULL;
		*g = 1; *u = 0;
	}
  if (strcmp((prods->produto), prod) != 0){
    if (strcmp((prods->produto), prod) > 0) {
  		prods->left = insertAVLProdutoRec(prods->left, prod, g, u);
  		if (*g == 1)
  			switch (prods->bal) {
  				case LEFT:  prods = fixLeftP(prods); *g = 0; break;
  				case BAL:   prods->bal = LEFT; break;
  				case RIGHT: prods->bal = BAL; *g = 0; break;
  			}
  	} else  {
  		prods->right = insertAVLProdutoRec(prods->right, prod, g, u);
  		if (*g == 1)
  			switch (prods->bal) {
  				case RIGHT: prods = fixRightP(prods); *g = 0; break;
  				case BAL:   prods->bal = RIGHT; break;
  				case LEFT:  prods->bal = BAL; *g = 0; break;
  			}
      }
  }
	return prods;
}

AVLProds insertAVLProduto(AVLProds *prods, char* prod) {
  int g, u;
  *prods = insertAVLProdutoRec(*prods, prod, &g, &u);
  return *prods;
}

CatProds insertCatProds(CatProds cp, char* produto){
  int hash = hashP(produto);
  (cp->listaAVLProds)[hash] = insertAVLProduto(&(cp->listaAVLProds)[hash], produto);
  return cp;
}

/*Esvaziar Árvores e Hash Tables*/

void freeAVLProdutos(AVLProds avlProds){
  if(avlProds != NULL){
    freeAVLProdutos(avlProds->left);
    freeAVLProdutos(avlProds->right);
    free(avlProds->produto);
    free(avlProds);
  }
}

void freeCatProds(CatProds cp){
  int i;
  for(i = 0; i < 26; i++){
    freeAVLProdutos((cp->listaAVLProds)[i]);
  }
  free(cp->listaAVLProds);
  free(cp);
}

/*Inicilização das Estruturas*/

CatProds initCatProds(){

  CatProds catP = (CatProds)malloc(sizeof(struct hashProdutos));
  catP->listaAVLProds = (AVLProds*)malloc(sizeof(struct avlProdutos) * 26);
  int i;
  for(i = 0; i < 26; i++){
    (catP->listaAVLProds)[i] = NULL;
  }
  return catP;
}
