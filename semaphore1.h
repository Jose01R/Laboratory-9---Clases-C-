#ifndef SEMAPHORE1_H
#define SEMAPHORE1_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

#define IT_NUM 5 // número de veces que se imprimirá cada carácter

class semaphore1 {
private:
    int semid;      //id sem
    int n;          //cant procesos hijos
    char* symbols;  //array caracteres para hijos

    void P(); //op wait
    void V(); //op signal
    void childProcess(char c); 

public:
    semaphore1(int n, char* symbols); //constructor
    ~semaphore1(); //destructor

    void start(); //iniciar procesos
};

#endif /* SEMAPHORE1_H */
