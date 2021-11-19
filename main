
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
#define TAM 100	  //constante para tamanho do vetor

int troca, comparar ;

void swap(int *a, int *b)
{    
 
	int temp = *a;
	*a = *b;
	*b = temp;
	troca++;
}
void bubbleSort(int *v, int n)
{   
   
	if (n < 1)
		return;
	for (int i = 0; i < n; i++){
		if (v[i] > v[i + 1]){
		    comparar++;
			swap(&v[i], &v[i + 1]);
		}
		comparar++;
	}
	bubbleSort(v, n - 1);
    
}

void selection_sort(int num[], int tam)
{
	int i, j, min, aux;
	for (i = 0; i < (tam - 1); i++)
	{
		min = i;
		for (j = (i + 1); j < tam; j++)
		{
			if (num[j] < num[min])
				min = j;
		}
		if (i != min)
		{
			aux = num[i];
			num[i] = num[min];
			num[min] = aux;
		}
	}
}

int main()
{
	int tam, i, *v, t, type;
	int count = 0;
	int vetor[TAM];
	srand(time(NULL));

	//scanf("%d",&tam);
	//v=(int*)malloc(tam*sizeof(int));

	printf("\n [1] Bubble sort\n [2] Selection Sort\n [3] Insertion sort\n [4] Quick sort\n->");
	scanf("%d", &type);

	for (i = 0; i < TAM; i++)
		vetor[i] = rand() % TAM;

	t = clock(); //armazena tempo
	if (type == 1)
	{
		bubbleSort(vetor, TAM - 1);
	}
	if (type == 2)
	{
		selection_sort(vetor, TAM);
	}
	t = clock() - t; //tempo final - tempo inicial
	for (i = 0; i < TAM; i++)
		printf("%d ", vetor[i]);
	printf("\n\nTempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000))); //conversão para double
	printf("\n\nTrocas: %d\n\n", troca);
	printf("\nComparacoes: %d\n\n", comparar);
	return 0;
}
