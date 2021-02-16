# Pratice on POSIX Thread

練習基本的並行程式，內容包含:

- Mutex
- Condition Variable
- Semaphore
- Thread pool

## 編譯

由於程式碼有使用到 pthread library ，在編譯時需添加 `-pthread` 參數。

```
gcc -g -pthread -o file file.c
```
