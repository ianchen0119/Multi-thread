#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

static sem_t A_B;
static sem_t B_C;
static sem_t C_A;

void *printA(void *arg)
{
	int i = 0;
	for(i = 1;i<11;i++){
		sem_wait(&C_A);
		printf("第%02d次:A",i);
		sem_post(&A_B);
	}
	return NULL;
}
void *printB(void *arg)
{
	int i = 0;
	for(i = 1;i<11;i++){
		sem_wait(&A_B);
		printf("B");
		sem_post(&B_C);
	}
	return NULL;
}
void *printC(void *arg)
{
	int i = 0;
	for(i = 1;i<11;i++){
		sem_wait(&B_C);
		printf("C");
		sem_post(&C_A);
	}
	return NULL;
}
int main(){
	pthread_t thread_A;
	pthread_t thread_B;
	pthread_t thread_C;
	sem_init(&A_B,0,0);
	sem_init(&B_C,0,0);
	sem_init(&C_A,0,1);
	pthread_create(&thread_A,NULL,printA,NULL);
	pthread_create(&thread_B,NULL,printB,NULL);
	pthread_create(&thread_C,NULL,printC,NULL);
	pthread_join(thread_A, NULL);
	pthread_join(thread_B, NULL);
	pthread_join(thread_C, NULL);
	sem_destroy(&A_B);
	sem_destroy(&B_C);
	sem_destroy(&C_A);
	printf("\n");
	return 0;


}
