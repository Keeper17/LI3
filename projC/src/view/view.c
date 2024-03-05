#include "../../include/view/view.h"

/*Funções para obter tamanho da bash para uma printing mais pretty*/
int getBashHeight (){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_row)-3;
}
int getBashWidth(){
  struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

/*Print de erros genéricos*/
void printErro(){
  printf("Erro!\n");
}

/*Print do menu principal*/
void printMenu(){
  printf(" \n------------------------------- Bem Vindo ao SGV -------------------------------\n");
  printf("Selecione uma opção:\n");
  printf("1 - Preencher SGV (estrutura)\n");
  printf("2 - Produtos por letra\n");
	printf("3 - Nº total de vendas e total faturado com um produto num dado mês\n");
  printf("4 - Produtos não vendidos\n");
	printf("5 - Clientes que compraram em todas as filiais\n");
	printf("6 - Clientes que não compraram e Produtos não vendidos (total)\n");
	printf("7 - Número total de produtos comprados por mes, organizado por filial\n");
	printf("8 - Nº total de vendas e total faturado num intervalo de meses\n");
	printf("9 - Clientes que compraram um produto em determinada filial\n");
	printf("10 - Produto mais comprado por um cliente num dado mês\n");
	printf("11 - N produtos mais vendidos em todo o ano.\n");
	printf("12 - N produtos em que um cliente gastou mais dinheiro\n");
  printf("13 - Estatísticas dos valores lidos\n");
	printf("q - Terminar o programa\n\n");
}

/*Query 1*/

void printQ1A(){
  printf("Deseja abrir ficheiros novos (n) ou utilizar os ficheiros default (d)?\n");
}

void printQ1B(){
  printf("Insira os ficheiros que pretende abrir um de cada vez (Produtos, Clientes e Vendas, por esta ordem).\n");
}

void printQ1C(){
  printf("Ficheiros lidos com sucesso!\n");
}

void printQ1Def(){
  printf("A abrir os ficheiros utilizados por defeito!\n");
}

/*Query 2*/

void printQ2A(){
  printf("Insira uma letra\n");
}

void printQ2B(char** produtos, int size, int start, int end){
  printf("Total: %d\n", size);
	int i;
  for(i = start; (i < end) && i < size; i++){
    printf("%s\n", produtos[i]);
  }
  printf("Anterior (a) Próximo (s) Sair (q)\n");
}

/*Query 3*/

void printQ3A(){
	printf("Insira o mês (1-12) que pretende analisar.\n");
}

void printQ3B(){
	printf("Insira o código do produto que pretende analisar.\n");
}

void printQ3C(){
	printf("Indique se pretende o resultado global (G) ou filial a filial(F).\n");
}

void printR3(double vals[]){
	printf("Os resultados globais são:\n");
	printf("Modo N:\n Total de vendas: %f, Total faturado: %f\n", vals[0], vals[1]);
	printf("Modo P:\n Total de vendas: %f, Total faturado: %f\n", vals[2], vals[3]);
}

void printR4(double fils[]){
	printf("Os resultados filial a filial são:\n\n");
	printf("Filial 1: \n");
	printf("Modo N:\n Total de vendas: %f, Total faturado: %f\n", fils[0], fils[1]);
	printf("Modo P:\n Total de vendas: %f, Total faturado: %f\n", fils[2], fils[3]);
	printf("\nFilial 2\n");
	printf("Modo N:\n Total de vendas: %f, Total faturado: %f\n", fils[4], fils[5]);
	printf("Modo P:\n Total de vendas: %f, Total faturado: %f\n", fils[6], fils[7]);
	printf("\nFilial 3\n");
	printf("Modo N:\n Total de vendas: %f, Total faturado: %f\n", fils[8], fils[9]);
	printf("Modo P:\n Total de vendas: %f, Total faturado: %f\n", fils[10], fils[11]);
}

/*Query 4*/

void printQ4(){
  printf("Insira a filial que quer analisar (1, 2 ou 3): ");
}

/*Query 6*/

void printQ6(int sp, int sc){
	printf("Total:\nClientes: %d Produtos: %d\n", sc, sp);
}

/*Query 7*/
void printQ7(){
	printf("Insira um código de cliente\n");
}

void printQ7R(int *f){
	printf("Mês       %s               %s                 %s\n","Filial 1","Filial 2", "Filial 3" );
	printf("JAN         %-12d            %-11d              %-10d\n",f[0],f[12],f[24]);
	printf("FEV         %-12d            %-11d              %-10d\n",f[1],f[13],f[25]);
	printf("MAR         %-12d            %-11d              %-10d\n",f[2],f[14],f[26]);
	printf("ABR         %-12d            %-11d              %-10d\n",f[3],f[15],f[27]);
	printf("MAI         %-12d            %-11d              %-10d\n",f[4],f[16],f[28]);
	printf("JUN         %-12d            %-11d              %-10d\n",f[5],f[17],f[29]);
	printf("JUL         %-12d            %-11d              %-10d\n",f[6],f[18],f[30]);
	printf("AGO         %-12d            %-11d              %-10d\n",f[7],f[19],f[31]);
	printf("SET         %-12d            %-11d              %-10d\n",f[8],f[20],f[32]);
	printf("OUT         %-12d            %-11d              %-10d\n",f[9],f[21],f[33]);
	printf("NOV         %-12d            %-11d              %-10d\n",f[10],f[22],f[34]);
	printf("DEZ         %-12d            %-11d              %-10d\n",f[11],f[23],f[35]);
}

void printQ7F(){
	printf("- Voltar ao menu -\n" );
}
/*Query 8*/

void printQ8A(){
	printf("Indique o mes de início do intervalo: \n");
}

void printQ8B(){
	printf("Indique o mes de fim do intervalo: \n");
}

void print8R(int mesI, int mesF, int vendas, double totalFat){
	printf("Durante o intervalo de meses [%d,%d]:\n", mesI, mesF);
	printf("Total de vendas: %d, Total faturado: %f\n", vendas, totalFat);
}

/*Query 9*/

void printQ9C(){
	printf("Insira um código de produto:");
}

void printQ9F(){
	printf("Insira a filial que pretende analisar:");
}

void printQ9R(int tN, int tP, char** cN, char** cP){
	int i;
	printf("\nTotal de compras com preço Normal: %d\n",tN );
	if(tN<0){
				printf("   Clientes que compraram em preço Normal:\n");
				}
	for( i=0; i<tN; i++)
	printf("   -%s\n",cN[i]);

	printf("\nTotal de compras com preço Promoção: %d\n",tP );
		if(tP<0){
			printf("   Clientes que compraram em preço Promoção:\n");
	}
	for( i=0; i<tP; i++)
	printf("   -%s\n",cP[i]);
}

/*Query 10*/

void printQ10A(){
		printf("Insira um código de cliente: ");
}

void printQ10B(){
		printf("Insira um mês (1 a 12): ");
}


void printQ10C(char** produtos, int* quants, int size, int start, int end){
	int i;
		printf("Produto             Quantidade\n");
	for(i = start; (i < end) && i < size; i++){
		printf("%s          %10d\n", produtos[i], quants[i]);
	}
	printf("Anterior (a) Próximo (s) Sair (q)\n");
}

/*Query 11*/

void printQ11(){
	printf("Insira quantos produtos quer na lista dos mais vendidos:\n");
}

void print11RA(int tam){
	printf("Os %d produtos mais vendidos são: \n", tam);
}

void print11RB(char** produtos, int** arrayFil1, int** arrayFil2, int** arrayFil3, int size, int start, int end){
	printf("Produtos       Fil1: Tot Cli    Tot Uni       Fil2: Tot Cli    Tot Uni       Fil3: Tot Cli    Tot Uni\n");
	int i;
	for(i = start; (i < end) && i < size; i++){
		printf("%s%18d%13d%19d%12d%18d%13d\n", produtos[i], arrayFil1[i][0], arrayFil1[i][1], arrayFil2[i][0], arrayFil2[i][1], arrayFil3[i][0], arrayFil3[i][1]);
	}
	printf("Anterior (a) Próximo (s) Sair (q)\n");
}

/*Query 12*/

void printQ12A(){
  printf("Insira o número de produtos a mostrar: ");
}

void printQ12(char** produtos, float* fats, int size, int start, int end){
	printf("Produto               Total Gasto\n");
	int i;
	for(i = start; (i < end) && i < size; i++){
		printf("%s          %17f\n", produtos[i], fats[i]);
	}
	printf("Anterior (a) Próximo (s) Sair (q)\n");
}

/*Query 13*/

void printQ13(int tp, int tc, int tv, int vp, int vc, int vv, char* p1, char* p2, char *p3){
  printf("\n\n\nProdutos lidos de \"%s\", com %d produtos, dos quais %d válidos\n", p1, tp, vp);
  printf("Clientes lidos de \"%s\", com %d clientes, dos quais %d válidos\n", p2, tc, vc);
  printf("Vendas lidas de \"%s\", com %d vendas, das quais %d válidas\n", p3, tv, vv);
}

void printAviso(){
	printf("\n                SGV NÃO INICIALIZADO. EXECUTE (1) PARA INICIALIZAR.            \n");
}
