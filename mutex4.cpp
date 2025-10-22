/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   mutex4.cpp
 * Author: joram
 * 
 * Created on October 20, 2025, 6:13 PM
 */

#include "mutex4.h"

//inicializar var estatica
int mutex4::counter = 0;


mutex4::mutex4(std::mutex *mutex, int value) {
    this->mutex = mutex;
    this->value = value;
}

mutex4::mutex4(const mutex4& orig) {
}

mutex4::~mutex4() {
}

void mutex4::run(){ 
    //si funcion hilo lleva parametros se idnican despues del 'this' separados por coma (,)
    this->t = std::thread(&mutex4::threadFunction, this); //creamos hilos
}

void mutex4::join(){
    this->t.join(); //hacemos que hilos sean randomly
}

void mutex4::threadFunction(){
    this->mutex->lock(); //entramos en region critica
    std::cout << "Counter = " << this->value << " (Thread) --> ";
    
    for(int i = 0; i < IT_NUM; i++){
        std::cout << (this->counter+=value) << " ";
    }
    std::cout << "\n";
    this->mutex->unlock(); //salimos de region critica
    
}