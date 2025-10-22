#ifndef SEMAPHORE2_H
#define SEMAPHORE2_H

#include <semaphore.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

class semaphore2 {
private:
    sem_t *sem; // semáforo compartido entre procesos

    static void criticalSection(int id);

public:
    semaphore2();
    ~semaphore2();

    void start();
};

#endif /* SEMAPHORE2_H */
