#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_SIZE 10
typedef pthread_mutex_t pm_t;
pm_t lock;

int buffer[10];
int *in;
int count = 0;
void *producer(void *arg){
	for(;;){
		while(count == MAX_SIZE);
		pthread_mutex_lock(&lock);
		buffer[count] = 1;
		count++;
		printf("%d", count);
		pthread_mutex_unlock(&lock);
	}
}
void *consumer(void *arg){
	for(;;){
		while(count == 0);
		pthread_mutex_lock(&lock);
		count--;
		printf("%d", count);
		pthread_mutex_unlock(&lock);
	}
}

int main(){
	pthread_mutex_init(&lock, NULL);
	pthread_t thread_p;
	pthread_t thread_c;
	pthread_create(&thread_p, NULL, producer, NULL);
	pthread_create(&thread_c, NULL, consumer, NULL);
	pthread_join(thread_p, NULL);
	pthread_join(thread_c, NULL);
	pthread_mutex_destroy(&lock);
}

