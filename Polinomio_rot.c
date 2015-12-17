#include "TDA_Polinomio.h"

void IniciaLista(struct RegDescr *poli)
{
	poli->inicio = NULL;
	poli->qntd = 0;
}

int IncluiNoh(struct RegDescr *poli, int c, int e)
{
	struct Polinomio *aux, *ant;
	
	if (poli->inicio == NULL)
	{
		ant = NULL;
	}
	else
	{	
		ant = poli->inicio;
		while (ant->prox != NULL)
		{
			ant = ant->prox;
		}
	}
	
	aux = (struct Polinomio *) malloc(sizeof(struct Polinomio));
	
	if (aux == NULL)
	{	
		printf("Memoria insuficiente para esta operacao ...\n");
		return FALSE;
	}
	
	aux->prox = NULL;
	aux->coef = c;
	aux->exp = e;	
		
	//poli->qntd = poli->qntd + 1;
		
	if (poli->inicio == NULL)
	{
		poli->inicio = aux;
	}
	else
	{
		ant->prox = aux;
	}
	
	return TRUE;
}

//funcao que soma os coeficientes com o mesmo expoente
int SomaIguais(struct RegDescr *poli)
{
	struct Polinomio *aux, *ant, *atual;
	int num, cont;
	
	poli->qntd = 0;
	
	aux = poli->inicio;
	ant = aux;
	
	while(aux != NULL)
	{
		atual = aux->prox;
		ant = aux;
		while(atual != NULL) 
		{
			//condicional para expoentes iguais
			if(atual->exp == aux->exp)
			{
				ant->prox = atual->prox;
				
				//soma dos coeficientes
				aux->coef += atual->coef; 
				
				if(atual->prox == NULL)
				{
					ant->prox = NULL;
				}
				free(atual);
				
				atual = ant->prox;
			}
			else
			{
				ant = atual;
				atual = atual->prox;
			}
		}
		
		poli->qntd += 1;
		aux = aux->prox;
	}
	
	return TRUE;
}

void Ordena(struct RegDescr *poli)
{
	struct Polinomio *aux, *atual;
	int c, e;
	
	aux = poli->inicio;
	
	while(aux != NULL)
	{
		atual = aux->prox;
		while(atual != NULL)
		{
			if(aux->exp < atual->exp)
			{
				c = atual->coef;
				e = atual->exp;
				
				atual->coef = aux->coef;
				atual->exp = aux->exp;
				
				aux->coef = c;
				aux->exp = e;
			}
			atual = atual->prox;
		}
		aux = aux->prox;
	}
	
}

//funcao que resolve o valor do polinomio
int ResolvePolinomio(struct RegDescr *poli, int num)
{
	struct Polinomio *aux;
	int resultado = 0;
	
	aux = poli->inicio;
	
	while(aux != NULL)
	{
		//tratamento de expoentes = 0
		if(aux->exp == 0)
		{
			resultado += aux->coef;
		}
		else //tratamento de expoentes diferentes != 0
		{
			resultado += pow(num, aux->exp) * aux->coef;
		}
		
		aux = aux->prox;
	}
	
	return resultado;
}

int LimparLista(struct RegDescr *poli)
{
	struct Polinomio *aux;
	
	while(poli->inicio != NULL)
	{
		aux = poli->inicio;
		poli->inicio = aux->prox;
		
		free(aux);
	}
	
	if(poli->inicio == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void ImprimeLista(struct RegDescr *poli, char *texto)
{	struct Polinomio *aux; 

	if (poli->inicio == NULL)
		printf("A lista estah vazia\n");
	else
	{	printf("%s", texto);
		aux = poli->inicio;
		
			printf("%dx", aux->coef);
			printf("%d", aux->exp);
			
		aux = aux->prox;	
		while (aux != NULL)
		{	
			//printf("Coeficiente: %d\n", aux->coef);
			//printf("Expoente: %d\n", aux->exp);
			
			if(aux->coef > 0)
			{
				printf("+%dx", aux->coef);
				printf("%d", aux->exp);
			}
			else
			{
				printf("%dx", aux->coef);
				printf("%d", aux->exp);
			}
			
			aux = aux->prox;
		}
	}
}
