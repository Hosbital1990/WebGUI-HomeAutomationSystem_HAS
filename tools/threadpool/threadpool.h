#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>



class ThreadPool {

public:

    ThreadPool(int8_t num_threads);

    ~ThreadPool();

void enqueue(std::function<void()> f);

void stop();

private:

std::vector<std::thread> workers;

std::queue<std::function<void()>> tasks;

std::mutex queue_mutex;

std::condition_variable condition;

int8_t num_threads;

bool pool_stop;

void worker_thread();






};




#endif // THREADPOOL_H
