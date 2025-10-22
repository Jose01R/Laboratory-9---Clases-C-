#ifndef MUTEX2_H
#define MUTEX2_H

#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <stdio.h>
#include <string>



class mutex2 {
public:
    mutex2(std::mutex* mutex, const void* array, int size, int threadNumber, std::string type);
    virtual ~mutex2();

    void run();
    void join();

private:
    std::mutex* mutex;
    std::thread t;
    const void* array;
    int size;
    int threadNumber;
    std::string type;

    void threadFunction();
};

#endif /* MUTEX2_H */
