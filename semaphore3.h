#ifndef SEMAPHORE3_H
#define SEMAPHORE3_H

#include <iostream>
#include <unistd.h>     // fork, sleep
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>    // semáforos del sistema
#include <sys/wait.h>   // wait
#include <string>

#define IT_NUM 5        // número de repeticiones
#define MAX_PROC 10     // máximo de procesos posibles

class semaphore3 {
public:
    semaphore3(int n, std::string arr[]);
    ~semaphore3();

    void start();

private:
    int n;                         // cantidad de procesos hijos
    std::string cadenas[MAX_PROC]; // cadenas para hijos + padre
    int semid;                     // ID del semáforo

    void down(); // P()
    void up();   // V()
};

#endif /* SEMAPHORE3_H */


