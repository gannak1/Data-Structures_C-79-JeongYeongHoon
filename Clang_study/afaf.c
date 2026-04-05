#include <stdio.h>

typedef union
{
	char a;
	short b;
	int c;
} SHAREDATA;

int main(void)
{
	SHAREDATA var;
	var.c = 12345678;
	
	printf("%x\n", var.a);
	printf("%x\n", var.b);
	printf("%x\n", var.c);
  printf("%d\n", sizeof(var));
	return 0;
}
