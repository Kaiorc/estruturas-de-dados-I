#include <bits/stdc++.h>
using namespace std;

// Uma função para trocar dois elementos
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

//Essa função toma a última posição como pivô, coloca o pivô na posição correta no array selecionado,
//e coloca todos os elementos menores (menor que o pivô) à esquerda do pivô e os maiores à direita do pivô
int partition (int arr[ ], int low, int high){
	//Pivô
	int pivot = arr[high];
	//Índice de menor elemento
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++){
		//Verifica se o elemento atual é menor que o pivô e
		//incrementa no índice de menores elementos
		if (arr[j] < pivot){
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//Função que implementa o quicksort
//arr[] --> array a ser ordenado
//low --> índice inicial
//high --> índice final
void quickSort(int arr[], int low, int high){
	if (low < high){
		//pi é o índice de particionamento, arr[pi] está agora na posição direita
		int pi = partition(arr, low, high);

		//Ordena separadamente os elementos antes da partição e depois da partição
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


//Função que imprime o array
void printArray(int arr[ ], int size){
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//Função principal
int main(){
	int arr[] = { 10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);

return 0;
}
