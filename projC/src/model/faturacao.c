#include "../../include/model/faturacao.h"

struct fatura {
	double precoUnit;
	int quantidade;
	char* tipo;
	int mes;
	int filial;
};

struct avlFaturacao {
	char* codProd;
  struct fatura **f;
	int t;
  int bal;
  struct avlFaturacao *left, *right;
};

struct hashFaturacao {
	AVLFat* listaAVLFat;
};

int hashF(char* produto) {
  return produto[0]-65;
}

Faturacao* initFat(char* campos[]){
	Faturacao* f = (struct fatura**)malloc(sizeof(struct fatura*));
	f[0] = (struct fatura*)malloc(sizeof(struct fatura));
	f[0] -> precoUnit = atof(campos[1]);
	f[0] -> quantidade = atoi(campos[2]);
	f[0] -> tipo = strdup(campos[3]);
	f[0] -> mes = atoi(campos[5]);
	f[0] -> filial = atoi(campos[6]);

	return f;
}

Faturacao* addFat(Faturacao* f, char* campos[], int size){
	f = (struct fatura**)realloc(f, (size + 1) * sizeof(struct fatura*));
	f[size] = (struct fatura*)malloc(sizeof(struct fatura));
	f[size] -> precoUnit = atof(campos[1]);
	f[size] -> quantidade = atoi(campos[2]);
	f[size] -> tipo = strdup(campos[3]);
	f[size] -> mes = atoi(campos[5]);
	f[size] -> filial = atoi(campos[6]);

	return f;
}

/*Preenchimento de Árvores/Hash Tables*/

AVLFat rotateLeftFat (AVLFat b) {
	AVLFat a = b->right;
	b->right = a->left;
	a->left = b;
	return a;
}

AVLFat rotateRightFat (AVLFat a) {
	AVLFat b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

AVLFat fixRightFat (AVLFat fat) {
	AVLFat b, c;
	b = fat->right;
	if (b->bal == RIGHT) {
		fat->bal = b->bal = BAL;
		fat = rotateLeftFat(fat);
	} else {
		c = b->left;
		switch (c->bal) {
			case LEFT:  fat->bal = BAL;
					    b->bal = RIGHT;
					    break;
		    case RIGHT: fat->bal = LEFT;
		    			b->bal = BAL;
		    			break;
		    case BAL:   fat->bal = b->bal = BAL;
		}
		c->bal = BAL;
		fat->right = rotateRightFat(b);
		fat = rotateLeftFat(fat);
	}
	return fat;
}

AVLFat fixLeftFat (AVLFat fat) {
	AVLFat b, c;
	b = fat->left;
	if (b->bal == LEFT) {
		fat->bal = b->bal = BAL;
		fat = rotateRightFat(fat);
	} else {
		c = b->right;
		switch (c->bal) {
			case LEFT:  fat->bal = RIGHT;
					    b->bal = BAL;
					    break;
		    case RIGHT: fat->bal = BAL;
		    			b->bal = LEFT;
		    			break;
		    case BAL:   fat->bal = b->bal = BAL;
		}
		c->bal = BAL;
		fat->left = rotateLeftFat(b);
		fat = rotateRightFat(fat);
	}
	return fat;
}

AVLFat insertFaturaRec(AVLFat fat, char* campos[], int *g, int *u) {
  if (fat == NULL) {
		fat = (AVLFat)malloc(sizeof(struct avlFaturacao));
		fat->codProd = strdup(campos[0]);
		fat->f = initFat(campos);
		fat->t = 1;
		fat->bal = BAL;
		fat->left = fat->right = NULL;
		*g = 1; *u = 0;
	}

	else{
  	if (strcmp((fat->codProd), campos[0]) == 0){
			fat->f = addFat(fat->f, campos, fat->t);
			(fat->t)++;
		}else{
    	if (strcmp((fat->codProd), campos[0]) > 0) {
  			fat->left = insertFaturaRec(fat->left, campos, g, u);
  			if (*g == 1)
  				switch (fat->bal) {
  					case LEFT:  fat = fixLeftFat(fat); *g = 0; break;
  					case BAL:   fat->bal = LEFT; break;
  					case RIGHT: fat->bal = BAL; *g = 0; break;
  				}
  		} else {
  			fat->right = insertFaturaRec(fat->right, campos, g, u);
  			if (*g == 1)
  				switch (fat->bal) {
  					case RIGHT: fat = fixRightFat(fat); *g = 0; break;
  					case BAL:   fat->bal = RIGHT; break;
  					case LEFT:  fat->bal = BAL; *g = 0; break;
  				}
      }
		}
  }
	return fat;
}

AVLFat insertFatura(AVLFat *fat, char* campos[]) {
  int g, u;
  *fat = insertFaturaRec(*fat, campos, &g, &u);
	return *fat;
}

HashTableFat insertHashTableFat(HashTableFat f, char* campos[]){
	int hash = hashF(campos[0]);
	(f->listaAVLFat)[hash] = insertFatura(&(f->listaAVLFat)[hash], campos);
	return f;
}

void printAuxF(AVLFat a, int *i){
  if(a){
    printAuxF(a->left, i);
    printAuxF(a->right, i);
    (*i)+=a->t;
  }
}

void printHashF(HashTableFat fat){
  int i = 0, j;
  for(j = 0; j < 26; j++){
    printAuxF((fat->listaAVLFat)[j], &i);
  }
  printf("%d\n", i);
}

/*Preenchimento da avlFat*/

HashTableFat initHashTableFat (){
  HashTableFat fat = (HashTableFat)malloc(sizeof(struct hashFaturacao));
	(fat->listaAVLFat) = (AVLFat*)malloc(sizeof(struct avlFaturacao) * 26);
	int i;
	for (i = 0; i < 26; i++){
		(fat->listaAVLFat)[i] = NULL;
	}

  return fat;
}

/*Query 3*/

	/*Global*/
void query3FatAux(AVLFat fat, char* produto, int mes, double vals[]){

	if (fat != NULL){

		query3FatAux(fat->left, produto, mes, vals);

		if (strcmp(fat->codProd, produto) == 0){
			int i;
			for(i = 0; i < fat->t; i++){
				if (fat->f[i]->mes == mes){
					if (fat->f[i]->tipo[0] == 'N'){
						vals[0]++;
						vals[1] += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
					}
					else {
						vals[2]++;
						vals[3] += ((double)((fat->f)[i]->quantidade) * (fat->f[i]->precoUnit));
					}
				}
			}
		}
		query3FatAux(fat->right, produto, mes, vals);
	}
}

void query3Fat(HashTableFat fat, char* produto, int mes, double vals[]){
		int pos = produto[0]-65;
		query3FatAux((fat->listaAVLFat)[pos], produto, mes, vals);
}

	/*Filial a Filial*/
void query3fatFilAux(AVLFat fat, char* produto, int mes, double fils[]){

	if (fat != NULL){

		query3fatFilAux(fat->left, produto, mes, fils);

		if (strcmp(fat->codProd, produto) == 0){
			int i;
			for(i = 0; i < fat->t; i++){
				if (fat->f[i]->mes == mes){
					if (fat->f[i]->tipo[0] == 'N'){
						if (fat->f[i]->filial == 1){
							fils[0]++;
							fils[1] += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
						}
						else if(fat->f[i]->filial == 2){
							fils[4]++;
							fils[5] += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
						}
						else{
							fils[8]++;
							fils[9] += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
						}
					}
					else{
						if (fat->f[i]->filial == 1){
							fils[2]++;
							fils[3] += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
						}
						else if(fat->f[i]->filial == 2){
							fils[6]++;
							fils[7] += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
						}
						else{
							fils[10]++;
							fils[11] += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
						}
					}
				}
			}
		}
		query3fatFilAux(fat->right, produto, mes, fils);
	}
}

void query3fatFil(HashTableFat fat, char* produto, int mes, double fils[]){
	int pos = produto[0]-65;
	query3fatFilAux((fat->listaAVLFat)[pos], produto, mes, fils);
}

/* Query 4*/

Array query4FatAux(AVLFat f, Array ar, int fil){
	if(f != NULL){
		ar = query4FatAux(f->left, ar, fil);
		bool flag = false;
		int i = 0;
		for(i = 0; i < f->t; i++){
			if((f->f)[i]->filial == fil){
				flag = true;
				break;
			}
		}
		if(flag == false){
			ar = addToArray(ar, f->codProd);
		}
		ar = query4FatAux(f->right, ar, fil);
	}
	return ar;
}

Array query4Fat(HashTableFat f, Array ar, int fil){
	int i;
	for(i = 0; i < 26; i++){
		ar = query4FatAux((f->listaAVLFat)[i], ar, fil);
	}
	return ar;
}

/*Query 8*/

void query8FatAux(AVLFat fat, int mesI, int mesF, int* vendas, double* totalFat){

		if(fat != NULL){
			query8FatAux(fat->left, mesI, mesF, vendas, totalFat);
			int i;
			for(i = 0; i < fat->t; i++){
				if(fat->f[i]->mes >= mesI && fat->f[i]->mes <= mesF){
					(*vendas)++;
					(*totalFat) += ((double)(fat->f[i]->quantidade) * (fat->f[i]->precoUnit));
				}
			}

			query8FatAux(fat->right, mesI, mesF, vendas, totalFat);
		}
}

void query8Fat(HashTableFat fat, int mesI, int mesF, int* vendas, double* totalFat){
	int i;
	for(i = 0; i < 26; i++){
		query8FatAux((fat->listaAVLFat)[i], mesI, mesF, vendas, totalFat);
	}
}

/*Query 11*/

Array2 query11FatAux(AVLFat fat, Array2 array){

		if(fat != NULL){
			array = query11FatAux(fat->left, array);

			int quant = 0;
			int i;
			for(i = 0; i < fat->t; i++){
				quant += fat->f[i]->quantidade;
			}
			array = simpleAddToArray2(array, fat->codProd, quant);

			array = query11FatAux(fat->right, array);
		}

		return array;
}

Array2 query11Fat(HashTableFat fat, Array2 array){
	int i;
	for(i = 0; i < 26; i++){
		array = query11FatAux((fat->listaAVLFat)[i], array);
	}
	return array;
}

/*Esvaziar Árvores e Hash Tables e faturas*/

void freeFatura(AVLFat fat, int t){
  int i;
  for( i=0; i<t; i++){
    free((fat->f)[i]->tipo);
  }
  free(fat->f);
}

void freeAVLFat(AVLFat fat){
	if(fat != NULL){
		freeAVLFat(fat->left);
		freeAVLFat(fat->right);
		freeFatura(fat, fat->t);
		free(fat->codProd);
		free(fat);
	}
}

void freeFatHash(HashTableFat fat){
	int i;
	for (i = 0; i < 26; i++)
		freeAVLFat((fat->listaAVLFat)[i]);
	free(fat->listaAVLFat);
	free(fat);
}
