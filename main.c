#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
#define TAM 10000  //constante para tamanho do vetor

int movimentar, comparar ;

void swap(int *a, int *b)
{    
 
	int temp = *a;
	*a = *b;
	*b = temp;
	movimentar++;
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
		comparar++;
		{   
		   
			if (num[j] < num[min])
			movimentar++;
			min = j;
		      
		}
		if (i != min)
		{
		    movimentar++;
			aux = num[i];
			num[i] = num[min];
			num[min] = aux;
			
		}
	}
}

void insertionSort(int arr[], int size){
    int i, j, key;
    
    for (i = 1; i < size; i++) {
        comparar++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            movimentar++;
            arr[j + 1] = arr[j];
            j = j - 1;
            
        }
        arr[j + 1] = key;
        
       
    }
}

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
            comparar++;
        }
        while(a[j] > x && j > left) {
            j--;
            comparar++;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            movimentar++;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
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

	printf("\n [1] Bubble sort\n [2] Selection Sort\n [3] Insertion sort\n [4] Quick sort\n [5] Merge Sort\n->");
	scanf("%d", &type);

	for (i = 0; i < TAM; i++)
		vetor[i] = rand() % 10000;

	t = clock(); //armazena tempo
	if (type == 1)
	{
		bubbleSort(vetor, TAM - 1);
	}
	if (type == 2)
	{
		selection_sort(vetor, TAM);
	}
	if(type == 3)
	{
	    insertionSort(vetor,TAM);
	}
	if(type == 4)
	{
	    quick_sort(vetor, 0, TAM - 1);
	}
		if(type == 5)
	{
	     mergeSort(vetor, 0, TAM - 1);
	}
	t = clock() - t; //tempo final - tempo inicial
	for (i = 0; i < TAM; i++)
		printf("%d ", vetor[i]);
	printf("\n\nTempo de execucao: %lf", ((double)t) / ((CLOCKS_PER_SEC / 1000))); //conversão para double
	printf("\n\nMovimentações: %d\n\n", movimentar);
	printf("\nComparacoes: %d\n\n", comparar);
	return 0;
}
