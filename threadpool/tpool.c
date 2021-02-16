#include <tpool.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// 定義 Task / Job

typedef struct{
	void (*function)(void *);
	void *argument;
} threadpool_task_t;

// 定義 Thread pool


struct threadpool_t {
	pthread_mutex_t lock;
	pthread_cond_t notify;
	pthread_t *threads;
	threadpool_task_t *queue;
	int thread_count;
	int queue_size;
	int head;
	int tail;
	int count;
	int shutdown;
	int started;
}

// 創建 pool 實體

threadpool_t * threadpool_init(int thread_count, int queue_size, int flag);

// 新增 Task

int threadpool_add(threadpool_t * pool, void (*routine)(void *),void *arg, int flags);

int threadpool_destroy(threadpool_t *pool, int flags);


