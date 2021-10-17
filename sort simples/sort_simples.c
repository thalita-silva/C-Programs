#include<stdio.h>
#include<stdlib.h>

int main()
{
    int qntd, op, j, m, i, num[3], aux[3];
	do{
	    printf("\nInsira a opcao desejada:\n1 - Ordem Crescente\n2 - Ordem Decrescente\n0 - Sair\n\n");
	    scanf("%d",&op);
	    switch (op)
	    {
	    	case 0:
	    		printf("\nSaindo do sort...\n");
	    		return 0;
	    	case 1: 
	    		printf("Insira 3 valores que deseja ordenar: ");
	        	for(i=0;i<3;i++)
	    		{
	        		scanf("%d",&num[i]);
	        		aux[i] = num[i];
	    		}
	    		for(i=0;i<3;i++)
	    		{
	    			for(j=i+1;j<3;j++)
	    			{
	    				if(num[i] > num[j])
	    				{
				
				    		m = num[i];
				    		num[i] = num[j];
				    		num[j] = m;
						}
					}
				}
				printf("-----------------Ordem crescente-----------------\n");
				for(i=0;i<3;i++)
				{
					printf("%d\n",num[i]);
				}
				break;
			case 2:
				printf("Insira 3 valores que deseja ordenar: ");
	    
	    		for(i=0;i<3;i++)
	    		{
	        		scanf("%d",&num[i]);
	        		aux[i] = num[i];
	    		}
				for(i=0;i<3;i++)
	    		{
	    			for(j=i+1;j<3;j++)
	    			{
	    				if(num[i] < num[j])
	    				{
				
				    		m = num[i];
				    		num[i] = num[j];
				    		num[j] = m;
						}
					}
				}
				printf("-----------------Ordem decrescente-----------------\n");
				for(i=0;i<3;i++)
				{
					printf("%d\n",num[i]);
				}
	    		break;
	    	default:
	    		printf("\nOpcao invalida!\n");
		}
	}while(op);
    return 0;
}
