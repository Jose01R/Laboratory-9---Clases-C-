#ifndef MUTEX1_H
#define MUTEX1_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <stdio.h> //fflush
#include <random>
#include <time.h>

#define IT_NUM 5

class mutex1 {
public:
    //mutex1(); //constructor vacio
    
    mutex1(std::mutex *mutex, char character);
    mutex1(const mutex1& orig); //constructor X DEFAULT
    virtual ~mutex1(); //destructor
    
    //definimos metodos
    void run(); //para crear hilos
    void join();
    
private:
    //ATRIBUTOS
    char character;
    std::thread t;
    std::mutex *mutex;
    
    //definimos funcion hilo
    void threadFunction();
    
};

#endif /* MUTEX1_H */

