//#include "main.h"
//#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int test_strcspn(char *a, char *b){
    int i = 0, min = -1;
    while (*b){
        for (i = 0; *(a+i) != '\0'; i++)
            if (*b == *(a + i) && (min > i || min == -1) )
                min = i;
		b++;
	}
    if (min == -1) return i;
    return min;
}

int is_digit(int c) {
    return c >= '0' && c <= '9'; 
}

double test_strtod(const char* s, const char **endptr) {
    while (*s && !is_digit(*s) && *s != '.')
        s++;

    double n = 0.0;
    while(*s && is_digit(*s)){
        n = n * 10.0 + ((*s) - '0');
		s++;
	}

    if (*s == '.')	s++;
    double r = 0.0;
    double x = 10.0;
	
    while(*s && is_digit(*s)) {
        r = r + ((*s) - '0') / x;
        x = x * 10.0;
        s++;
    }
    if(endptr != NULL)
        *endptr = s;
    return n + r;
}



int main()
{
	char s[] = "ff123.54a2.78cc33fff";
	char *ptr;
	// ptr += 5;
	// char **p = &ptr;
	double a = test_strtod(s, &ptr);
	printf("a = %lf\n", a);
	printf("ptr = %s\n", ptr);
	double b = test_strtod(ptr, NULL);
	printf("b = %lf\n", b);
	printf("ptr = %s\n", ptr);
    return 0;
}