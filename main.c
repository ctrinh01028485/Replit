#include <stdio.h>

void nhap(int *n){
	scanf("%d", &(*n));
}
int main() {
	int n;
	nhap(&n);

	printf("%d", n);
	
	return 0;
}