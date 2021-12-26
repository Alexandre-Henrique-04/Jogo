//******************************************************

//Tipo de jogo......: Jogo de adivinhação

//Developer...........: Alexandre Henrique Ribeiro de Melo Jorge

//******************************************************

//inclusão de arquivos de cabeçalho
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//função principal do programa
int main (int argc, char * argv[])
{
	//imprime uma ascii art
	printf("\n\n");
	printf("          P  /_\\  P                              \n");
	printf("         /_\\_|_|_/_\\                            \n");
	printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
	printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n");
	printf("    |\" \"  |  |_|  |\"  \" |                     \n");
	printf("    |_____| ' _ ' |_____|                         \n");
	printf("          \\__|_|__/                              \n");
	printf("\n\n");

	//variável inicializa e gera o ponto de partida
	int seconds = time (0);
	srand (seconds); 

	// variável gera um número aleatório
	int numgrande= rand(); 

	//variável que dar o resto da divisão do número por 100 (aleatório entre 0 e 99) 
	int numsecreto=numgrande % 100; 
	
	//variáveis declaradas do tipo inteiro
	int chute, tentativas=1; 
	
	//variável do tipo ponto flutuante de dupla precisão
	double pontos=1000;

	//variáveis declarado do tipo inteiro
	int igual=0, nivel;

	//imprime os níveis e o usuário fornece a entrada dos dados para a variável nível
	printf ("Qual seu nivel medio de jogo? ");
	printf ("(1) Facil (2) Medio (3) Dificil\n\n");
	printf ("Escolha: ");
	scanf ("%d", &nivel);

	//variável declarada como tipo inteiro
	int numerodetentativas; 

	//menu interativo de niveis de 1 a 3
	switch(nivel)
	{	
		case 1:
		system ("color 02"); //a linha muda a cor do prompt do cmd para preto e verde
		numerodetentativas=20;
		break;

		case 2:
		system ("color 1F"); //a linha muda a cor do prompt do cmd para azul e branco brilhante
		numerodetentativas=15;
		break; 

		default:
		system ("color 70"); //a linha muda a cor do prompt do cmd para branco e preto
		numerodetentativas=6;
		break;
	}

	//bloco do laço de repetição
	for (int i=1; i<= numerodetentativas; i++)
	{

		//imprime o número de tentativas no meu programa
		printf ("tentativa %d\n", tentativas);
		
	//vai ler a entrada a partir do teclado
		printf ("O numero chutado eh: ");
		scanf ("%d", &chute);

	//se chute for menor que 0 então imprima o aviso e continue a execução
		if (chute <0)
		{
			printf ("O programa nao aceita numeros negativos\a\n\n", chute);
			continue;
		}

	//compara as variaveis
		igual = (chute==numsecreto); 
		int maior = chute > numsecreto;

	//se variavel for igual a outra variavel então imprima	
		if (igual) 
		{ 
			break; //interrompe o programa após a execução
		}

		//se variável for maior que a outra, imprima
		else if (maior)
		{
			printf ("Chute maior que numero secreto\n\n");
		}

		//caso contrário imprima variável menor que a outra variavel
		else {
			printf ("Chute menor que numero secreto\n\n");
		}

		//operador de incremento tentativas= tentativas +1
		tentativas++;

		//declaração de uma nova variável com casting e valor absoluto
		double pontosperdidos= abs(chute-numsecreto) / (double) 2;
		pontos= pontos - pontosperdidos;
	}
	
	//imprime uma mensagem na tela
	printf ("fim de jogo\n");

	//se acertou então imprima
	if (igual)
	{

		//imprime a ascii art
		printf("\n\n");
		printf("             OOOOOOOOOOO               \n");
		printf("         OOOOOOOOOOOOOOOOOOO           \n");
		printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		printf("    OOOOOO      OOOOO      OOOOOO      \n");
		printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		printf("         OOOOOO         OOOOOO         \n");
		printf("             OOOOOOOOOOOO              \n");
		printf("\n\n");

		//imprime na tela
		printf ("Voce ganhou\n");
		printf ("Fim de programa!! Voce acertou em numero de tentativas: %d\n", tentativas);
		printf ("Seu score foi: %.1f\n", pontos);
	}

	// caso contrário 
	else {

		//imprime a ascii art
		printf("\n\n");
		printf("       \\|/ ____ \\|/    \n");
		printf("        @~/ ,. \\~@      \n");
		printf("       /_( \\__/ )_\\    \n");
		printf("          \\__U_/        \n");
		printf("\n\n");
	}
	
	//pausa o programa após a execução 
	system("pause");
	
	//limpa a tela
	system ("cls");

	//retorna o valor 0 para o sistema operacional indicando que está tudo ok
	return 0;
}