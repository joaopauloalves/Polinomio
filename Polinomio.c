#include "TDA_Polinomio.h"

int main()
{	
	struct RegDescr poli;
	int c, e, cont, val, num;
	
	IniciaLista(&poli);
	
	for(cont = 0; cont < 2; cont++)
	{
		printf("Digite o coeficiente:");
		scanf("%d", &c);
		
		printf("Digite o expoente:");
		scanf("%d", &e);
		
		if(IncluiNoh(&poli, c, e) == FALSE)
		{
			printf("Noh nao incluido!!\n");
		}
		else
		{
			printf("Noh incluido com sucesso!!\n");
		}
	}
	
	printf("\n\n");
	ImprimeLista(&poli, "Dados Polinomio pos entradas:\n");
	printf("\n-----------------------------------------\n");
	
	//Chamada da funcao para somar nohs de mesmo expoente
	SomaIguais(&poli);
	ImprimeLista(&poli, "Dados Polinomio pos reorganizacao:\n");
	printf("\n-----------------------------------------\n");
	
	Ordena(&poli);
	ImprimeLista(&poli, "Dados Polinomio pos ordenacao:\n");
	
	printf("\n-----------------------------------------\n");
	printf("Digite o valor de 'X': ");
	scanf("%d", &num);
	//chamada da funcao que resolve o polinomio 
	val = ResolvePolinomio(&poli, num);
	printf("Resultado: %d\n", val);
	
	
	printf("\n-----------------------------------------\n");
	if(LimparLista(&poli) == TRUE)
	{
		printf("Lista VAZIA!!\n");
	}		
	else
	{
		printf("LISTA CHEIA\n");
	}
	
	printf("\n-----------------------------------------\n");
	ImprimeLista(&poli, "Dados Polinomio pos esvaziar:\n");
	
	return 0;
}
