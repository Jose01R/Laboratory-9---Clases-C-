#ifndef MUTEX6_H
#define MUTEX6_H
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define IT_NUM 5 

class mutex6 {
public:
    mutex6(int p, int c);
    ~mutex6();

    void run();  //iniciar hilos
    void join();//esperar hilos

private:
    static int buffer;
    int p, c;// numero de productores y consumidores
    std::thread *t1, *t2;

    std::mutex mutex_lock;
    std::condition_variable condition_var;

    void producer();//función productor
    void consumer();// función consumidor
};

#endif



