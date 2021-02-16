#ifndef __tpool_h__
#define __tpool_h__
#define MAX_THREADS 64
#define MAX_QUEUE 65536

typedef enum {
	threadpool_thread_failure = -5,
	threadpool_shutdown,
	threadpool_queue_full,
	threadpool_lock_failure,
	threadpool_invalid
} threadpool_error_t

typedef enum {
	threadpool_graceful = 1
} threadpool_destroy_t


typedef struct threadpool_t threadpool_t;

// 創建 pool 實體

threadpool_t * threadpool_init(int thread_count, int queue_size, int flag);

// 新增 Task

int threadpool_add(threadpool_t * pool, void (*routine)(void *),void *arg, int flags);

int threadpool_destroy(threadpool_t *pool, int flags);

#endif
