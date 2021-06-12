#include <stdio.h>
#include <string.h>

void xoakt(char a[]){
	for (int i = 0; i < strlen(a); i++){
		if (a[i] == ' ' && a[i + 1] == ' '){
			for (int j = i; j < strlen(a); j++)
				a[j] = a[j + 1];
			i--;
		}
	}
	if (a[0] == ' '){ // con co the viet if(a[0] == ' ') strcpy(a, a + 1);
		for (int j = 0; j < strlen(a); j++)
			a[j] = a[j + 1];
	}
	
}
void standar(char a[]){
	int j;
	if (a[0] >= 'a' && a[0] <='z')
		a[0] -= 32;
	j = 1;

	while (a[j] != ' '){
		if (a[j] >= 'A' && a[j] <= 'Z')
			a[j] += 32;
		j++;
	}

	for (int i = 1; i < strlen(a) - 1; i++){
		if (a[i] == ' '){
			j = i + 2;

			if (a[i + 1] >= 'a' && a[i + 1] <= 'z')
				a[i + 1] -= 32;

			while (a[j] != ' ' && j < strlen(a)){
				if (a[j] >= 'A' && a[j] <= 'Z')
					a[j] += 32;
				j++;
			}
		}
	}
	printf("%s\n", a);
}

int main(){
	int t;
	char k[51][1000];
	printf("nhap t: ");
	scanf("%d", &t);
	fflush(stdin);
	for (int i = 0; i < t; i++){
		gets(k[i]);
	}
	for (int i = 0; i < t; i++){
		xoakt(k[i]);
		printf("\n");
		standar(k[i]);
	}

	return 0;
}
