/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   mutex3.h
 * Author: jamora
 *
 * Created on 21 de octubre de 2025, 19:13
 */

#ifndef MUTEX3_H
#define MUTEX3_H
#include <iostream>
#include <unistd.h> //sleep
#include <thread>
#include <mutex>
#include <stdio.h>//fflush
#include <random>
#include <time.h>
#define IT_NUM 5
class mutex3 {
public:
    mutex3(std::mutex *mutex, const std::string& character);
    mutex3(const mutex3& orig);
    virtual ~mutex3();
    //metodos 
    void run();
    void join();
private:
    std::string character;
    std::thread t;
    std::mutex *mutex;
    
    //definimos una funcion hilo
    void threadFunction();
};

#endif /* MUTEX3_H */

