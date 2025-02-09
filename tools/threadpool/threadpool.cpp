#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

#include "threadpool.h"


ThreadPool::ThreadPool(int8_t num_threads)
:num_threads(num_threads), pool_stop(false)
 {

    for (int i = 0; i < num_threads; ++i){

        workers.push_back(std::thread(&ThreadPool::worker_thread, this));

    }

}

void ThreadPool::enqueue(std::function<void()> task){

    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.push(task);
    }
    condition.notify_one();
}




void ThreadPool::worker_thread(){

while (!pool_stop)
{
    /* code */
    std::function<void()> task;

    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        condition.wait(lock,  [this](){
            return !tasks.empty() && !pool_stop;
        }); 
        task= tasks.front();
        tasks.pop();
           
    }
    task();

}

}


void ThreadPool::stop(){

    pool_stop = true;


    for (std::thread &worker : workers){
        worker.join();
    }
    
}


ThreadPool::~ThreadPool() {

    stop();

}