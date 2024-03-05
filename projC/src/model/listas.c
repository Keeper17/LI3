#include "../../include/model/listas.h"

/*Array genérico, corresponde a uma lista de strings e o tamanho da lista*/

struct arrayGenerico{
  char** array;
  int tam;
};

Array initArray(){
  Array a = (Array)malloc( sizeof(struct arrayGenerico));
  a->array = (char**)malloc(sizeof(char*));
  a->tam = 0;
  return a;
}

Array addToArray(Array a, char* c){
  a->array = (char**)realloc(a->array, sizeof(char*) * ((a->tam)+1));
  (a->array)[a->tam] = strdup(c);
  (a->tam)++;
  return a;
}

Array incSize(Array a){
  (a->tam)++;
  return a;
}

char** getArray(Array a){
  return a->array;
}

int getTam(Array a){
  return a->tam;
}

void freeArray(Array a){
  int i;
  for(i = 0; i < a->tam; i++){
    free((a->array)[i]);
  }
  free(a->array);
  free(a);
}

/*Array genérico, corresponde a uma lista de strings, lista de inteiros e tamanhos das listas*/

struct arrayGenerico2{
  char **arrayC;
  int *arrayI;
  int tam;
};

Array2 initArray2(){
  Array2 a = (Array2)malloc( sizeof(struct arrayGenerico2));
  a->arrayC = (char**)malloc(sizeof(char*));
  a->arrayI = (int*)malloc(sizeof(int));
  a->tam = 0;
  return a;
}

int existeString(Array2 s, char* string){
  bool flag = false;
  int i = 0;
  for(; i < s->tam; i++){
    if(strcmp((s->arrayC)[i], string) == 0){
      flag = true;
      break;
    }
  }
  if(flag == true) return i;
  else return -1;
}

Array2 simpleAddToArray2(Array2 a, char* c, int q){
  a->arrayC = (char**)realloc(a->arrayC, sizeof(char*) * ((a->tam)+1));
  a->arrayI = (int*)realloc(a->arrayI, sizeof(int) * ((a->tam)+1));
  (a->arrayC)[a->tam] = strdup(c);
  (a->arrayI)[a->tam] = q;
  (a->tam)++;
  return a;
}

Array2 addToArray2(Array2 a, char* c, int q){
  int flag = existeString(a, c);
  if(flag == -1){
    a->arrayC = (char**)realloc(a->arrayC, sizeof(char*) * ((a->tam)+1));
    a->arrayI = (int*)realloc(a->arrayI, sizeof(int) * ((a->tam)+1));
    (a->arrayC)[a->tam] = strdup(c);
    (a->arrayI)[a->tam] = q;
    (a->tam)++;
  }
  else{
    (a->arrayI)[flag] += q;
  }
  return a;
}


char** getArray2C(Array2 a){
  return a->arrayC;
}

int* getArray2I(Array2 a){
  return a->arrayI;
}

int getTam2(Array2 a){
  return a->tam;
}

void freeArray2(Array2 a){
  int i;
  for(i = 0; i < a->tam; i++){
    free((a->arrayC)[i]);
  }
  free(a->arrayI);
  free(a->arrayC);
  free(a);
}


Array2 freeArray2Tam(Array2 a, int tam){
  int i;
  for(i = tam; i < a->tam; i++){
    free((a->arrayC)[i]);
  }
  a->tam = tam;
  a->arrayI = (int*)realloc(a->arrayI, sizeof(int) * ((a->tam)+1));
  a->arrayC = (char**)realloc(a->arrayC, sizeof(char*) * ((a->tam)+1));

  return a;
}

/*Array genérico, com uma lista de strings, 3 matrizes de inteiros para cada filial e tamanho das listas/colunas das matrizes */

struct arrayGenerico4{
  char **arrayC;
  int **arrayFil1;
  int **arrayFil2;
  int **arrayFil3;
  int tam;
};

Array4 initArray4(int tamanho){
  Array4 a = (Array4)malloc( sizeof(struct arrayGenerico4));
  a->arrayC = (char**)malloc(tamanho * sizeof(char*));
  a->arrayFil1 = (int**)malloc(tamanho * sizeof(int*));
  a->arrayFil2 = (int**)malloc(tamanho * sizeof(int*));
  a->arrayFil3 = (int**)malloc(tamanho * sizeof(int*));
  a->tam = tamanho;
  int i;
  for(i = 0; i < tamanho; i++){
    a->arrayFil1[i] = (int*)malloc(sizeof(int));
    a->arrayFil2[i] = (int*)malloc(sizeof(int));
    a->arrayFil3[i] = (int*)malloc(sizeof(int));
  }

  for(i = 0; i < tamanho; i++){
    a->arrayFil1[i][0] = 0;
    a->arrayFil1[i][1] = 0;
    a->arrayFil2[i][0] = 0;
    a->arrayFil2[i][1] = 0;
    a->arrayFil3[i][0] = 0;
    a->arrayFil3[i][1] = 0;
  }
  return a;
}

Array4 preencheProdutosArray4(Array4 ar, Array2 array){
  int i;
  for(i = 0; i < ar->tam; i++){
    ar->arrayC[i] = strdup(array->arrayC[i]);
  }
  return ar;
}

bool verificaProdArray4(Array4 ar, char* prod, int pos){

  if (strcmp(prod, ar->arrayC[pos]) == 0) return true;
  else return false;
}

Array4 adicionaCliFil(Array4 ar, int pos, int fil){
  if (fil == 1)
    ar->arrayFil1[pos][0]++;
  else if (fil == 2)
    ar->arrayFil2[pos][0]++;
  else
    ar->arrayFil3[pos][0]++;

  return ar;
}

Array4 adicionaQntFil(Array4 ar, int qnt, int pos, int fil){
  if (fil == 1)
    ar->arrayFil1[pos][1] += qnt;
  else if (fil == 2)
    ar->arrayFil2[pos][1] += qnt;
  else
    ar->arrayFil3[pos][1] += qnt;

  return ar;
}

char** getArray4C(Array4 a){
  return a->arrayC;
}

int** getArray4Fil(Array4 a, int fil){
  if (fil == 1)
    return a->arrayFil1;
  else if(fil == 2)
    return a->arrayFil2;
  else
    return a->arrayFil3;
}

int getTam4(Array4 a){
  return a->tam;
}

void freeArray4(Array4 a){
  int i;
  for(i = 0; i < a->tam; i++){
    free((a->arrayC)[i]);
    free((a->arrayFil1)[i]);
    free((a->arrayFil2)[i]);
    free((a->arrayFil3)[i]);
  }
  free(a->arrayFil1);
  free(a->arrayFil2);
  free(a->arrayFil3);
  free(a->arrayC);
  free(a);
}

/*Array genérico, corresponde a uma lista de strings, lista de números reais e tamanhos das listas*/

struct arrayGenerico3{
  char **arrayC;
  float *arrayR;
  int tam;
};

Array3 initArray3(){
  Array3 a = (Array3)malloc( sizeof(struct arrayGenerico3));
  a->arrayC = (char**)malloc(sizeof(char*));
  a->arrayR = (float*)malloc(sizeof(float));
  a->tam = 0;
  return a;
}

int existeString3(Array3 s, char* string){
  bool flag = false;
  int i = 0;
  for(; i < s->tam; i++){
    if(strcmp((s->arrayC)[i], string) == 0){
      flag = true;
      break;
    }
  }
  if(flag == true) return i;
  else return -1;
}

Array3 simpleAddToArray3(Array3 a, char* c, float q){
  a->arrayC = (char**)realloc(a->arrayC, sizeof(char*) * ((a->tam)+1));
  a->arrayR = (float*)realloc(a->arrayR, sizeof(float) * ((a->tam)+1));
  (a->arrayC)[a->tam] = strdup(c);
  (a->arrayR)[a->tam] = q;
  (a->tam)++;
  return a;
}

Array3 addToArray3(Array3 a, char* c, float q){
  int flag = existeString3(a, c);
  if(flag == -1){
    a->arrayC = (char**)realloc(a->arrayC, sizeof(char*) * ((a->tam)+1));
    a->arrayR = (float*)realloc(a->arrayR, sizeof(float) * ((a->tam)+1));
    (a->arrayC)[a->tam] = strdup(c);
    (a->arrayR)[a->tam] = q;
    (a->tam)++;
  }
  else{
    (a->arrayR)[flag] += q;
  }
  return a;
}

char** getArray3C(Array3 a){
  return a->arrayC;
}

float* getArray3R(Array3 a){
  return a->arrayR;
}

int getTam3(Array3 a){
  return a->tam;
}

void freeArray3(Array3 a){
  int i;
  for(i = 0; i < a->tam; i++){
    free((a->arrayC)[i]);
  }
  free(a->arrayR);
  free(a->arrayC);
  free(a);
}

Array3 freeArray3Tam(Array3 a, int tam){
  if(tam <= a->tam){
    int i;
    for(i = tam; i < a->tam; i++){
      free((a->arrayC)[i]);
    }
    a->tam = tam;
    a->arrayC = (char**)realloc(a->arrayC, sizeof(char*) * ((a->tam)+1));
    a->arrayR = (float*)realloc(a->arrayR, sizeof(float) * ((a->tam)+1));
  }

  return a;
}

/*AVL básica*/

struct avl{
  char* string;
  int q;
  int bal;
  struct avl *left, *right;
};

AVL rotateLeft (AVL b) {
	AVL a = b->right;
	b->right = a->left;
	a->left = b;
	return a;
}

AVL rotateRight (AVL a) {
	AVL b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

AVL fixRight (AVL f) {
	AVL b, c;
	b = f->right;
	if (b->bal == DIR) {
		f->bal = b->bal = BAL;
		f = rotateLeft(f);
	} else {
		c = b->left;
		switch (c->bal) {
			case ESQ:  f->bal = BAL;
					    b->bal = DIR;
					    break;
		    case DIR: f->bal = ESQ;
		    			b->bal = BAL;
		    			break;
		    case BAL:   f->bal = b->bal = BAL;
		}
		c->bal = BAL;
		f->right = rotateRight(b);
		f = rotateLeft(f);
	}
	return f;
}

AVL fixLeft (AVL fil) {
	AVL b, c;
	b = fil->left;
	if (b->bal == ESQ) {
		fil->bal = b->bal = BAL;
		fil = rotateRight(fil);
	} else {
		c = b->right;
		switch (c->bal) {
			case ESQ:  fil->bal = DIR;
					    b->bal = BAL;
					    break;
		    case DIR: fil->bal = BAL;
		    			b->bal = ESQ;
		    			break;
		    case BAL:   fil->bal = b->bal = BAL;
		}
		c->bal = BAL;
		fil->left = rotateLeft(b);
		fil = rotateRight(fil);
	}
	return fil;
}

AVL insertRec(AVL a, char* string, int q, int *g, int *u){
	if (a == NULL){
		a = (AVL)malloc(sizeof(struct avl));
    a -> string = strdup(string);
    a -> q = q;
		a -> right = a -> left = NULL;
		*g = 1; *u = 0;
	}

  else{
      if(q < a->q){
        a->left = insertRec(a->left, string, q, g, u);
  			if (*g == 1)
  				switch (a->bal){
  					case ESQ:  a = fixLeft(a); *g = 0; break;
  					case BAL:   a->bal = ESQ; break;
  					case DIR: a->bal = BAL; *g = 0; break;
  				}
  		} else {
  			a->right = insertRec(a->right, string, q, g, u);
  			if(*g == 1)
  				switch(a->bal){
  					case DIR: a = fixRight(a); *g=0; break;
  					case BAL:   a->bal = DIR; break;
  					case ESQ:  a->bal = BAL; *g = 0; break;
  				}
  		}
  }
	return a;
}

AVL insert(AVL *f, char* string, int q){
	int g, u;
	*f = insertRec(*f, string, q, &g, &u);
  return *f;
}

void freeAVL(AVL a){
  if(a != NULL){
    freeAVL(a->left);
    free(a->string);
    freeAVL(a->right);
    free(a);
  }
}

struct avlF{
  char* string;
  int q;
  int bal;
  struct avlF *left, *right;
};

AVLF rotateLeftF (AVLF b) {
	AVLF a = b->right;
	b->right = a->left;
	a->left = b;
	return a;
}

AVLF rotateRightF (AVLF a) {
	AVLF b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

AVLF fixRightF (AVLF f) {
	AVLF b, c;
	b = f->right;
	if (b->bal == DIR) {
		f->bal = b->bal = BAL;
		f = rotateLeftF(f);
	} else {
		c = b->left;
		switch (c->bal) {
			case ESQ:  f->bal = BAL;
					    b->bal = DIR;
					    break;
		    case DIR: f->bal = ESQ;
		    			b->bal = BAL;
		    			break;
		    case BAL:   f->bal = b->bal = BAL;
		}
		c->bal = BAL;
		f->right = rotateRightF(b);
		f = rotateLeftF(f);
	}
	return f;
}

AVLF fixLeftF (AVLF f) {
	AVLF b, c;
	b = f->left;
	if (b->bal == ESQ) {
		f->bal = b->bal = BAL;
		f = rotateRightF(f);
	} else {
		c = b->right;
		switch (c->bal) {
			case ESQ:  f->bal = DIR;
					    b->bal = BAL;
					    break;
		    case DIR: f->bal = BAL;
		    			b->bal = ESQ;
		    			break;
		    case BAL:   f->bal = b->bal = BAL;
		}
		c->bal = BAL;
		f->left = rotateLeftF(b);
		f = rotateRightF(f);
	}
	return f;
}

AVLF insertRecF(AVLF a, char* string, float q, int *g, int *u){
	if (a == NULL){
		a = (AVLF)malloc(sizeof(struct avlF));
    a -> string = strdup(string);
    a -> q = q;
		a -> right = a -> left = NULL;
		*g = 1; *u = 0;
	}

  else{
      if(q < a->q){
        a->left = insertRecF(a->left, string, q, g, u);
  			if (*g == 1)
  				switch (a->bal){
  					case ESQ:  a = fixLeftF(a); *g = 0; break;
  					case BAL:   a->bal = ESQ; break;
  					case DIR: a->bal = BAL; *g = 0; break;
  				}
  		} else {
  			a->right = insertRecF(a->right, string, q, g, u);
  			if(*g == 1)
  				switch(a->bal){
  					case DIR: a = fixRightF(a); *g=0; break;
  					case BAL:   a->bal = DIR; break;
  					case ESQ:  a->bal = BAL; *g = 0; break;
  				}
  		}
  }
	return a;
}

AVLF insertF(AVLF *f, char* string, float q){
	int g, u;
	*f = insertRecF(*f, string, q, &g, &u);
  return *f;
}

void freeAVLF(AVLF a){
  if(a != NULL){
    freeAVLF(a->left);
    free(a->string);
    freeAVLF(a->right);
    free(a);
  }
}

Array2 avlToArray(AVL a, Array2 ar){
  if(a != NULL){
    ar = avlToArray(a->right, ar);
    ar = simpleAddToArray2(ar, a->string, a->q);
    ar = avlToArray(a->left, ar);
  }
  return ar;
}

AVL arrayToAVL(Array2 ar){
  AVL a = NULL;
  int i;
  for(i = 0; i < ar->tam; i++){
    a = insert(&a, (ar->arrayC)[i], (ar->arrayI)[i]);
  }
  return a;
}

Array2 sortArray2Dec(Array2 ar){
  AVL a = arrayToAVL(ar);
  freeArray2(ar);
  ar = initArray2();
  ar = avlToArray(a, ar);
  freeAVL(a);
  return ar;
}

Array3 avlToArray3(AVLF a, Array3 ar){
  if(a != NULL){
    ar = avlToArray3(a->right, ar);
    ar = simpleAddToArray3(ar, a->string, a->q);
    ar = avlToArray3(a->left, ar);
  }
  return ar;
}

AVLF arrayToAVLF(Array3 ar){
  AVLF a = NULL;
  int i;
  for(i = 0; i < ar->tam; i++){
    a = insertF(&a, (ar->arrayC)[i], (ar->arrayR)[i]);
  }
  return a;
}

Array3 sortArray3Dec(Array3 ar){
  AVLF a = arrayToAVLF(ar);
  freeArray3(ar);
  ar = initArray3();
  ar = avlToArray3(a, ar);
  freeAVLF(a);
  return ar;
}

struct pair{
  int x, y;
};

Pair initPair(int x, int y){
  Pair p = (struct pair*)malloc(sizeof(struct pair));
  p->x = x;
  p->y = y;
  return p;
}

int getX(Pair p){ return p->x; }
int getY(Pair p){ return p->y; }

void freePair(Pair p){
  free(p);
}

/*estrutura auxiliar usada para a query 8*/

struct pair2{
  int x;
  double y;
};

Pair2 initPair2(int x, double y){
  Pair2 p = (struct pair2*)malloc(sizeof(struct pair2));
  p->x = x;
  p->y = y;
  return p;
}

int getX2(Pair2 p){ return p->x; }
double getY2(Pair2 p){ return p->y; }

void freePair2(Pair2 p){
  free(p);
}

/*----------------------------------------------------------------------------*/

struct codsNP{
  char** codsN;
  char** codsP;
  int n;
  int p;
};

Cods initCods(){
  Cods c = (Cods)malloc(sizeof(struct codsNP));
  c->codsN = (char**)malloc(sizeof(char*));
  c->codsP = (char**)malloc(sizeof(char*));
  c->n = 0;
  c->p = 0;
  return c;
}

Cods addToCodsN(Cods c, char* cod){
  c->codsN = (char**)realloc(c->codsN,sizeof(char*)*((c->n)+1));
  (c->codsN)[c->n] = strdup(cod);
  (c->n)++;
  return c;
}

Cods addToCodsP(Cods c, char* cod){
  c->codsP = (char**)realloc(c->codsP,sizeof(char*)*((c->p)+1));
  (c->codsP)[c->p] = strdup(cod);
  (c->p)++;
  return c;
}

char** getCodsN(Cods c){
  return c->codsN;
}

char** getCodsP(Cods c){
  return c->codsP;
}

int getN(Cods c){
  return c->n;
}

int getP(Cods c){
  return c->p;
}

void freeCods(Cods c){
  int i;
  for(i = 0; i < c->n; i++){
    free((c->codsN)[i]);
  }
  for(i = 0; i < c->p; i++){
    free((c->codsP)[i]);
  }
  free(c->codsN);
  free(c->codsP);
  free(c);
}
