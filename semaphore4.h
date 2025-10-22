#ifndef SEMAPHORE4_H
#define SEMAPHORE4_H

#include <iostream>
#include <vector>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>

#define IT_NUM 5

class semaphore4 {
public:
    semaphore4(int n, int values[]);
    ~semaphore4();

    void start(); // crear hijos y padre

private:
    int n;
    std::vector<int> values;
    sem_t semaphore; // semáforo POSIX

    void printCounter(int value, const std::string& who); // imprime bloque de counter
};

#endif
