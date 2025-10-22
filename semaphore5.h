#ifndef SEMAPHORE5_H
#define SEMAPHORE5_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <stdio.h> //fflush
#include <random>
#include <time.h>
#include <semaphore.h>
#include <sys/sem.h> //struct_sembuf - semget - semctl - setval
#include <sys/wait.h> // wait


#define IT_NUM 5

//CENA DE LOS FILOSOFOS
#define N 5                     /* numero de filosofos */
#define LEFT(i)   ((i+N-1)%N)   /* número del vecino izquierdo de i */
#define RIGHT(i)  ((i+1)%N)     /* número del vecino derecho de i */
#define THINKING 0              /* el filósofo está pensando */
#define HUNGRY   1              /* el filósofo trata de obtener los tenedores */
#define EATING   2              /* el filósofo está comiendo */



class semaphore5 {
public:
    semaphore5();
    semaphore5(const semaphore5& orig);
    virtual ~semaphore5();
    
    //metodo de inicio de hilos
    void start();
    void join();
    
private:
    std::thread *f; //hilos filosofos
    int state[N];
    sem_t lock;
    sem_t s[N]; //array semaforos
    sem_t dining;              /* al menos 2 filosofos pueden comer  */

    
    //funcion hilo
    void philosopher(int i);
    
    //metodos de los filosofos
    void think(int i);
    void eat(int i);
    void takeFork(int i);
    void putFork(int i);
    void test(int i);
    
    
};

#endif /* SEMAPHORE5_H */

