/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   mutex4.h
 * Author: joram
 *
 * Created on October 20, 2025, 6:13 PM
 */

#ifndef MUTEX4_H
#define MUTEX4_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <stdio.h> //fflush
#include <random>
#include <time.h>

#define IT_NUM 5

class mutex4 {
public:
    mutex4(std::mutex *mutex, int value);
    mutex4(const mutex4& orig);
    virtual ~mutex4();
    
    //metodoss
    void run();
    void join();
    
private:
    //atributos
    static int counter; //var estatica - misma para todas las instancias
    int value;
    std::thread t;
    std::mutex *mutex;
    
    //funcion hilo
    void threadFunction();
};

#endif /* MUTEX4_H */

