#ifndef MUTEX5_H
#define MUTEX5_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <stdio.h> //fflush
#include <random>
#include <time.h>

#define IT_NUM 5

class mutex5 {
public:
    mutex5(std::mutex *mutex, int p, int c);
    mutex5(const mutex5& orig);
    virtual ~mutex5();
    
    //metodos
    void run(); //lanzar hilos 
    void join();
    
private:
    //atributos
    static int buffer;
    int p, c; //cant productores y consumidores
    std::thread *t1, *t2;
    std::mutex *mutex;
    
    //definimos funcion hilos
    void producer();
    void consumer();
};

#endif /* MUTEX5_H */

