#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5
#define PENSANDO 0
#define FOME 1
#define COMENDO 2
#define ESQ (num_fil + N - 1) % N
#define DIR (num_fil + 1) % N

int estado[N];
int fil[N] = { 0, 1, 2, 3, 4 };

sem_t mutex;
sem_t Semaforo[N];

void teste(int num_fil)
{
	if (estado[num_fil] == FOME && estado[ESQ] != COMENDO && estado[DIR] != COMENDO) 
	{
		estado[num_fil] = COMENDO;
		sleep(2);
		printf("Filosofo %d pegou o garfo %d e %d\n",num_fil, ESQ, num_fil);
		printf("Filosofo %d esta comendo!\n", num_fil);
		sem_post(&Semaforo[num_fil]);
	}
}
void pega_garfo(int num_fil)
{
	sem_wait(&mutex);
	estado[num_fil] = FOME;
	printf("Filosofo %d esta com fome\n", num_fil);
	teste(num_fil);
	sem_post(&mutex);
	// se nao esta disponivel, necessario esperar
	sem_wait(&Semaforo[num_fil]);
	sleep(1);
}
void devolve_garfo(int num_fil)
{
	sem_wait(&mutex);
	//volta a pensar 
	estado[num_fil] = PENSANDO;
	printf("Filosofo %d devolveu os garfos %d e %d\n", num_fil, ESQ, num_fil);
	printf("Filosofo %d esta pensando\n", num_fil);
	//verifica os "vizinhos"
	teste(ESQ);
	teste(DIR);

	sem_post(&mutex);
}

void *filosofo(void* num)
{
	while (1) 
	{
		int *i = num;
		sleep(1);
		pega_garfo(*i);
		sleep(0);
		devolve_garfo(*i);
	}
}
int main()
{
	int i;
	pthread_t thread_fil[N];
	sem_init(&mutex, 0, 1);

	for (i = 0; i < N; i++)
	{
		sem_init(&Semaforo[i], 0, 0);	
	}
	
	for (i = 0; i < N; i++) 
	{
		pthread_create(&thread_fil[i], NULL, filosofo, &fil[i]);
		printf("Filosofo %d esta pensando\n",i);
	}

	for (i = 0; i < N; i++)
	{
		pthread_join(thread_fil[i], NULL);	
	}

	return 0;
}
