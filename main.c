// Importações
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Definindo um ponteiro para função
typedef double (*ponteiroParaFuncao)(double);

// Definições das funções
double segundosParaMinutos(double seg);
double segundosParaHoras(double seg);
double minutosParaSegundos(double min);
double minutosParaHoras(double min);
double horasParaMinutos(double min);
double horasParaSegundos(double min);
void menuConversaoTempo(void);

/// Conversão de bytes

void conversaoDeBytes();
double bytesParaKilobytes(double bytes);
double bytesParaMegabytes(double bytes);
double bytesParaGigabytes(double bytes);
double bytesParaTerabytes(double bytes);
double kilobytesParaBytes(double kilobytes);
double kilobytesParaMegabytes(double kilobytes);
double kilobytesParaGigabytes(double kilobytes);
double kilobytesParaTerabytes(double kilobytes);
double megabytesParaBytes(double megabytes);
double megabytesParaKilobytes(double megabytes);
double megabytesParaGigabytes(double megabytes);
double megabytesParaTerabytes(double megabytes);
double gigabytesParaBytes(double gigabytes);
double gigabytesParaKilobytes(double gigabytes);
double gigabytesParaMegabytes(double gigabytes);
double gigabytesParaTerabytes(double gigabytes);
double terabytesParaBytes(double terabytes);
double terabytesParaKilobytes(double terabytes);
double terabytesParaMegabytes(double terabytes);
double terabytesParaGigabytes(double terabytes);
void imprimirOpcoes(char *opcoes[], int tamanhoArray, int numeroDaOpcaoIgnorada);
bool opcaoValida(int opcao, int opcoesValidas[], int tamanhoAray);
void removerDasOpcoesValidasPorIndex(int opcoes[], int *tamanho, int index);
int obterInputDoUsuario(int opcoesValidas[],int tamanho);

int main(int argc, char const *argv[])
{
    return 0;
}

// Implementação das funções

/// Conversão de bytes

void conversaoDeBytes(){
    char *opcoes[] = {"Bytes",
    "Kilobytes (KB)",
    "Megabytes (MB)",
    "Gigabytes (GB)",
    "Terabytes (TB)"};

    int tamanhoOpcoes = sizeof(opcoes) / sizeof(opcoes[0]);

    int opcoesValidas[] = {1,2,3,4,5};

    int tamanhoOpcoesValidas = sizeof(opcoesValidas) / sizeof(opcoesValidas[0]);

    int primeiraOpcao, segundaOpcao;

    double valor, valorConvertido;

    /* Matriz que armazena ponteiros para funções, pra ficar mais fácil chamar a 
    função correta para a conversão escolhida.
    */
    ponteiroParaFuncao opcoesDeConversao[5][5] = {
        {NULL,bytesParaKilobytes,bytesParaMegabytes,bytesParaGigabytes,bytesParaTerabytes},
        {kilobytesParaBytes,NULL,kilobytesParaMegabytes,kilobytesParaGigabytes,kilobytesParaTerabytes},
        {megabytesParaBytes,megabytesParaKilobytes,NULL,megabytesParaGigabytes,megabytesParaTerabytes},
        {gigabytesParaBytes,gigabytesParaKilobytes,gigabytesParaMegabytes,NULL,gigabytesParaTerabytes},
        {terabytesParaBytes,terabytesParaKilobytes,terabytesParaMegabytes,terabytesParaGigabytes,NULL}
    };

    printf("Bem vindo ao menu de converção das unidades de byte!\nSelecione o número correspondente a unidade que você quer converter, ou pressione 0 para sair:\n\n");

    imprimirOpcoes(opcoes, tamanhoOpcoes, -1);

    printf("Informe sua escolha: ");

    primeiraOpcao = obterInputDoUsuario(opcoesValidas,tamanhoOpcoesValidas);

    removerDasOpcoesValidasPorIndex(opcoesValidas,&tamanhoOpcoesValidas,primeiraOpcao-1);

    printf("\n\nPara qual unidade deseja converter?\n\n");

    imprimirOpcoes(opcoes, tamanhoOpcoes, primeiraOpcao);

    printf("Informe sua escolha: ");

    segundaOpcao = obterInputDoUsuario(opcoesValidas,tamanhoOpcoesValidas);

    printf("\nVocê escolheu converter %s para %s.\n", opcoes[primeiraOpcao - 1], opcoes[segundaOpcao - 1]);

    printf("Informe a quantidade de %s que serão convertidos: ",opcoes[primeiraOpcao-1]);

    scanf("%lf",&valor);

    valorConvertido = opcoesDeConversao[primeiraOpcao-1][segundaOpcao-1](valor);

    printf("%.2lf %s equivalem a %.2lf %s!\n\n",valor,opcoes[primeiraOpcao -1],valorConvertido,opcoes[segundaOpcao-1]);

}

void imprimirOpcoes(char *opcoes[], int tamanhoArray, int numeroDaOpcaoIgnorada){
    for(int contador = 0; contador < tamanhoArray; contador++){
        if(contador + 1 == numeroDaOpcaoIgnorada){
            continue;
        }else{
            printf("%d - %s\n",contador + 1,opcoes[contador]);
        }
    }

    printf("0 - Sair\n\n");
}

// Verifica se a opção inserida pelo usuário é válida
bool opcaoValida(int opcao, int opcoesValidas[], int tamanhoAray){
    for (int contador = 0; contador < tamanhoAray; contador++)
    {
        if(opcao == opcoesValidas[contador]) return true;
    }
    
    return false;
}


int obterInputDoUsuario(int opcoesValidas[],int tamanho){
    int valor;

    scanf("%d",&valor);

    if(valor == 0) exit(0);

    while (!opcaoValida(valor,opcoesValidas,tamanho))
    {
        printf("\nA opção escolhida é inválida, tente novamente: ");

        scanf("%d",&valor);

        if(valor == 0) exit(0);
    }

    return valor;
}

/*
    Remove a primeira opção selecionada pelo usuário do array de opções válidas,
    evitando que a mesma unidade seja selecionada duas vezes, após isso, diminui
    o valor da variável que informa o tamanho do array de opções.
*/
void removerDasOpcoesValidasPorIndex(int opcoes[], int *tamanho, int index){
    for (int contador = index; contador < (*tamanho); contador++)
    {
        opcoes[contador] = opcoes[contador+1];
    }
    
    (*tamanho) --;
}

double bytesParaKilobytes(double bytes) {
    return bytes / 1024.0;
}

double bytesParaMegabytes(double bytes) {
    return bytes / pow(1024.0,2);
}

double bytesParaGigabytes(double bytes){
    return bytes / pow(1024.0,3);
}

double bytesParaTerabytes(double bytes){
    return bytes / pow(1024.0,4);
}

double kilobytesParaBytes(double kilobytes){
    return kilobytes * 1024.0;
}

double kilobytesParaMegabytes(double kilobytes){
    return kilobytes / 1024.0;
}

double kilobytesParaGigabytes(double kilobytes){
    return kilobytes / pow(1024.0,2);
}

double kilobytesParaTerabytes(double kilobytes){
    return kilobytes / pow(1024.0,3);
}

double megabytesParaBytes(double megabytes){
    return megabytes * pow(1024.0,2);
}

double megabytesParaKilobytes(double megabytes){
    return megabytes * 1024.0;
}

double megabytesParaGigabytes(double megabytes){
    return megabytes / 1024.0;
}

double megabytesParaTerabytes(double megabytes){
    return megabytes / pow(1024.0,2);
}

double gigabytesParaBytes(double gigabytes){
    return gigabytes * pow(1024.0,3);
}

double gigabytesParaKilobytes(double gigabytes){
    return gigabytes * pow(1024.0,2);
}

double gigabytesParaMegabytes(double gigabytes){
    return gigabytes * 1024.0;
}

double gigabytesParaTerabytes(double gigabytes){
    return gigabytes / 1024.0;
}

double terabytesParaBytes(double terabytes){
    return terabytes * pow(1024.0,4);
}

double terabytesParaKilobytes(double terabytes){
    return terabytes * pow(1024.0,3);
}

double terabytesParaMegabytes(double terabytes){
    return terabytes * pow(1024.0,2);
}

double terabytesParaGigabytes(double terabytes){
    return terabytes * 1024.0;
}

double segundosParaMinutos(double seg)
{
	return seg / 60.0;
}

double segundosParaHoras(double seg)
{
	return seg / 60.0 / 60.0;
}

double minutosParaSegundos(double min)
{
	return min * 60.0;
}

double minutosParaHoras(double min)
{
	return min / 60.0;
}

double horasParaMinutos(double min)
{
	return min * 60.0;
}

double horasParaSegundos(double min)
{
	return min * 60.0 * 60.0;
}

void menuConversaoTempo(void)
{
	printf("Coversor de unidades de tempo\n");
	while (1) {
		printf("\n");
		printf("1. Segundos para minutos\n");
		printf("2. Segundos para horas\n");
		printf("3. Minutos para segundos\n");
		printf("4. Minutos para horas\n");
		printf("5. Horas para minutos\n");
		printf("6. Horas para segundos\n");
		printf("7. Sair\n");

		int opcao;
		printf("Opção: ");
		scanf("%d", &opcao);

		int parar = 0;

		switch (opcao) {
		case 1: {
			double segundos;
			printf("Digite os segundos: ");
			scanf("%lf", &segundos);
			printf("Resultado: %.2lfm\n", segundosParaMinutos(segundos));
			break;
		}
		case 2: {
			double segundos;
			printf("Digite os segundos: ");
			scanf("%lf", &segundos);
			printf("Resultado: %.2lfh\n", segundosParaHoras(segundos));
			break;
		}
		case 3: {
			double minutos;
			printf("Digite os minutos: ");
			scanf("%lf", &minutos);
			printf("Resultado: %.2lfs\n", minutosParaSegundos(minutos));
			break;
		}
		case 4: {
			double minutos;
			printf("Digite os minutos: ");
			scanf("%lf", &minutos);
			printf("Resultado: %.2lfh\n", minutosParaHoras(minutos));
			break;
		}
		case 5: {
			double horas;
			printf("Digite as horas: ");
			scanf("%lf", &horas);
			printf("Resultado: %.2lfm\n", horasParaMinutos(horas));
			break;
		}
		case 6: {
			double horas;
			printf("Digite as horas: ");
			scanf("%lf", &horas);
			printf("Resultado: %.2lfs\n", horasParaSegundos(horas));
			break;
		}
		case 7:
			parar = 1;
			break;
		default:
			printf("Opção inválida!\n");
			break;
		}

		if (parar)
			break;
	}
}
