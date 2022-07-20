#include "lib.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>
// #include <string.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// swap(&a[1], &a[2]);
// swap(&n, &m);

int StringEqual(char chuoi1[], char chuoi2[]){
    for (int i = 0; i < i + 1; i++){
        if(chuoi1[i] == '\0' && chuoi2[i] == '\0')
            return 1;
        else if (chuoi1[i] == '\0' || chuoi2[i] == '\0')
            return 0;
        else if (chuoi1[i] != chuoi2[i])
            return 0;
    }
}

int findMax(int a[], int n){
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

int findMin(int a[], int n){
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];
    return min;
}

void insertionSort(int a[], int n){
    int k;
    for (int i = 1; i < n; i++){
        k = a[i];
        int j = i;
        while (j > 0 && a[j-1] > k){
            a[j] = a[j-1];
            j--;
        }
        a[j] = k;
    }
}

void selectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[min], &a[i]);
    }
}

void bubbleSort(int a[], int n){
    for (int i = n-1; i > -1; i--){
        int flag = 1;
        for (int j = 0; j < i; j++){
            if (a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                flag = 0;
            }
        } if (flag) return;
    }
}

void bubbleSort2(int a[], int n){
    for (int i = n-1; i > -1; i--)
        for (int j = 0; j < i; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}


void show(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int test_atoi(char *string){
    int result = 0;
    for (int i = 0; string[i] != '\0'; i++)
        result = result*10 + (string[i] - 48);
    return result;
}

double test_atof(char *string){
    double result = 0, count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] == '.'){
            count++;
            continue;
        }
        if (count){
            count *= 10;
            result = result + (double)(string[i] - 48)/count;
        } else 
            result = result*10 + (string[i] - 48);
    }
    return result;
}

int test_strtod(char *string, char **ptr){
    int result = 0, j = 0;
    char *newPtr = (char *) malloc(20);
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] >= '0' && string[i] <= '9')
            result = result*10 + (string[i] - 48);
        else
            newPtr[j++] = string[i];
    }
    newPtr[j] = '\0';
    free(*ptr);
    *ptr = newPtr;
    return result;
}

//     char str[20] = "heohello123";
//     char *ptr;
//     double val = test_strtod(str, &ptr);
//     printf("chuoi: %s\n", ptr);
//     printf("val = %lf", val);
//     free(ptr);


int is_digit(int c) {
    return c >= '0' && c <= '9'; 
}

double my_stod(const char* s, const char **endptr) {
    while (*s && !is_digit(*s) && *s != '.')
        s++;

    double n = 0.0;
    while(*s && is_digit(*s))
    {
        n = n * 10.0 + ((*s) - '0');
        s++;
    }

    if (*s == '.')
        s++;
    double r = 0.0;
    double x = 10.0;
    while(*s && is_digit(*s)) {
        r = r + ((*s) - '0') / x;
        x = x * 10.0;
        s++;
    }
	printf("next = %s\n", s);
    if(endptr != NULL)
        *endptr = s;
    return n + r;
}

// char str[] = "abc123.4ss253.7dd";
// char* next;
// double v1 = my_stod(str, &next);
// double v2 = my_stod(next, NULL);
// printf("v1 = %lf\n", v1);
// printf("v2 = %lf\n", v2);