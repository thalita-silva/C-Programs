#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINHAS 1000
int tam_matriz()
{
	char linhas[LINHAS];
	FILE *csv_entrada = fopen("input_file.csv","r");
	int total_linhas_arq = 0;
	if(csv_entrada)
	{
		while(fgets(linhas,LINHAS,csv_entrada) != NULL)
		{
			total_linhas_arq++;
		}
		return total_linhas_arq;
	}
	else 
	{
		printf("Falha ao ler o arquivo!\n");
	}
}
float **criar_matriz(int tam)
{
	char linhas[LINHAS], *x[tam],*x1;
	FILE *csv_entrada = fopen("input_file.csv","r");
	int i = 0, l = 0, k = 0,c = 0,tam_total = tam + 1;
	float **matriz = (float **) malloc(tam * sizeof(float*));
	
	for(i = 0; i < tam; i++)
	{
		*(matriz + i) = (float *) malloc(tam_total * sizeof(float));
	}
	while(fgets(linhas,LINHAS,csv_entrada) != NULL)
	{
		x1 = strtok(linhas,",");
		matriz[l][0] = atof(x1);
		for(i=1;i<=tam;i++)
		{
			x[i] = strtok(NULL,",");
			matriz[l][i] = atof(x[i]);
		}
		l++;
	}
	return matriz;
}
void show(int tam, float **matriz)
{
  int i, j;

  printf("Ordem do sistema: n = %d\n\n\n", tam);
	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tam; j++)
		{
			printf("  %10.6f", matriz[i][j]);
		}
    printf(" | %10.6f\n", matriz[i][tam]);
    }
  
}
float det(float a, float b, float c, float d)
{
	return((a * d) - (b * c));
}
void triangulacao(int tam, float **matriz)
{
  int i, j, k;

	for(k = 0; k < (tam - 1); k++)
	{ 
    	for(i = k + 1; i < tam; i++)
    	{
    		for(j = k + 1; j < tam; j++)
        	{
        		matriz[i][j] = det(matriz[k][k], matriz[i][k], matriz[k][j], matriz[i][j]);
        		show(tam,matriz);
        	}
			matriz[i][tam] = det(matriz[k][k], matriz[i][k], matriz[k][tam], matriz[i][tam]);
      		matriz[i][k] = 0;
      		show(tam,matriz);
      	}
	}
}
void solucao(int tam, float **matriz)
{
  	int i, k, j; 
	float x[tam];
  	float s;

  	x[tam - 1] = matriz[tam - 1][tam]/matriz[tam - 1][tam - 1];
  	for(k = tam - 2; k >= 0; k--)
	{
    	s = 0;
    	for(j = k + 1; j < tam; j++)
    	{
      		s += matriz[k][j] * x[j];
    	}
    	x[k] = (matriz[k][tam] - s) / matriz[k][k];
    }
    printf("\n==== Solucao do sistema linear ====\n");
  	for(i = 0; i < tam; i++)
    {
    	printf("\tx(%d) =%10.6g\n", i, x[i]);
    } 	
}
int main()
{
	//header csv: n1,n2,n3,res
	int tam = tam_matriz();
	float **matriz = criar_matriz(tam);
	triangulacao(tam,matriz);
	solucao(tam,matriz);
	return 0;
}
