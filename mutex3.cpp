/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   mutex3.cpp
 * Author: jamora
 * 
 * Created on 21 de octubre de 2025, 19:13
 */

#include "mutex3.h"

mutex3::mutex3(std::mutex *mutex, const std::string& character) {
    srand(time(NULL));
    this->mutex=mutex;
    this->character=character;
}

mutex3::mutex3(const mutex3& orig) {
}

mutex3::~mutex3() {
}

void mutex3::run(){
    //si la funcion hilo lleva parametros se indican despues del this separados por coma 
    this->t =std::thread(&mutex3::threadFunction,this);
}

void mutex3::join(){
    this->t.join();
}
void mutex3::threadFunction(){
    this->mutex->lock();
    for(int i=0;i<IT_NUM;i++){
        std::cout << this->character<<"\n";
        fflush(stdout);
        sleep(rand()%2);
    }
    this->mutex->unlock();
}