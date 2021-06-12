#include <stdio.h>


void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void InterchangeSort(int a[], int n){	
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
	        if(a[i] > a[j]){
		        Swap(&a[i], &a[j]);
			}
		}
	}
}
void BubbleSort(int a[], int n){	
	for (int i = 0; i < n - 1; i++){
		for (int j = n - 1; j > i; j--){
		    if(a[j] < a[j-1]){
				Swap(&a[j], &a[j-1]);
			}
		}
	}
}
void InsertionSort(int a[], int n){
	int pos, x;
	for (int i = 1; i < n; i++){
		pos = i;
		x = a[i];
		while (pos > 0 && x < a[pos - 1]){
			a[pos] = a[pos - 1];
			pos--;
		}
		a[pos] = x;
	}
}
void SelectionSort(int a[], int n){
	int min;
	for (int  i = 0; i < n - 1; i++){
		min = i; 
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
			Swap(&a[min], &a[i]);
	}
}

void ins(int a[], int n){
	int pos, x;
	
}

int main(){
	int a[100] = {4, 3, 2, 10, 12, 1, 5, 6};
	int n = 8;

	return 0;
}
