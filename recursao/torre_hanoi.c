#include<stdlib.h>
#include<stdio.h>
void hanoi(int n, char *a, char *b, char *c)
{
	if(n < 2)
	{
		printf("Quantidade invalida de discos!\n");
	}
	else if(n == 2)
	{
		printf("\n(%s,%s),(%s,%s),(%s,%s)",a,b,a,c,b,c);
	}
	else
	{
		hanoi(n-1,a,c,b);
		printf("(%s,%s)",a,c);
		hanoi(n-1,b,a,c);
	}
}
int main()
{
	hanoi(5,"a","b","c");
	return 0;	
}
