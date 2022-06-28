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
	int i = 0, l = 0,tam_total = tam + 1;
	float **matriz = (float **) malloc(tam * sizeof(float*));
	if(csv_entrada)
	{
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
	}
	else
	{
		printf("Falha ao ler o arquivo!");
	}
	return matriz;
}
void gauss_jordan(int tam, float **matriz)
{
	int i, j, k;
	float res, x[tam];
	printf("\n   ==== Matriz Inicial ====\n");
	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tam; j++)
		{
			printf("%10.6f ",matriz[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tam; j++)
		{
			if(i != j)
			{
				res = matriz[j][i]/matriz[i][i];
				for(k = 0; k < tam + 1; k++)
				{
					matriz[j][k] = matriz[j][k] - res * matriz[i][k];
				}
			}
		}
	}
	printf("\n  ==== Matriz final ====\n");
	for(i = 0; i < tam; i++)
	{
		if(matriz[i][i] == 0.0)
		{
			printf("Erro ao resolver o sistema linear!\n");
		}
		else
		{
			x[i] = matriz[i][tam]/matriz[i][i];
			matriz[i][i] = 1.0;
			for(j = 0; j < tam; j++)
			{
				printf("%10.6f ",matriz[i][j]);
			}
			matriz[i][tam] = x[i];
			printf(" | %10.6f\n",matriz[i][tam]);
		}
		
	}
	printf("\n==== Resultado do sistema linear: ====\n");
	for(i = 0; i < tam; i++)
	{
		printf("x(%d) = %10.6g\n",i,x[i]);	
	}
}
int main()
{
	int tam = tam_matriz();
	float **matriz = criar_matriz(tam);
	gauss_jordan(tam,matriz);
	return 0;
}
