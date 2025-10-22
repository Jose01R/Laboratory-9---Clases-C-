/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   semaphore5.cpp
 * Author: joram
 * 
 * Created on October 20, 2025, 7:38 PM
 */

#include "semaphore5.h"

semaphore5::semaphore5() {
    srand(time(NULL));
    //INICIALIZAMOS VAR DE BLOQUEO

    sem_init(&this->lock, 0, 1);
    sem_init(&dining, 0, 2);   // max 2 filosofos comen al msmo tiempo
    //INICIALIZAMOS LOS SEMAFOROS
    for (int i = 0; i < N; i++) {
        sem_init(&this->s[i], 0, 0);
        this->state[i] = THINKING;
    }

}

semaphore5::semaphore5(const semaphore5& orig) {
}

semaphore5::~semaphore5() {
}

void semaphore5::start() {
    this->f = new std::thread[N];

    //AHORA CREAMOS HILOS
    for (int i = 0; i < N; i++) {
        this->f[i] = std::thread(&semaphore5::philosopher, this, i + 1);
    }
}

void semaphore5::join() {
    for (int i = 0; i < N; i++) {
        this->f[i].join();
    }
}

//IMPLEMENTAMOS FUNCION HILO
void semaphore5::philosopher(int i){
    while(true){
        this->think(i); //filosofo pensando
        this->takeFork(i); //trate de tomar los tenedores
        this->eat(i); //si tomo tenedores entonces, coma
        this->putFork(i); //cuando finaliza regrese los tenedores
    }
}

void semaphore5::think(int i){
    std::cout << "Philosopher " << i << " is thinking\n";
    sleep(rand()%2);
}

void semaphore5::takeFork(int i){
    sem_wait(&lock); //entra en region critica
    state[i] = HUNGRY;
    test(i);                 //trata de adquirir el fork
    sem_post(&lock); //sale de region critica
    sem_wait(&s[i]);         //espera si los procesos no estan disponibles
    sem_wait(&dining);       //verificamos que solo 2 coman
}

void semaphore5::eat(int i){
    std::cout << "Philosopher " << i << " is eating\n";
    sleep(rand()%2);
}

void semaphore5::putFork(int i){
    sem_wait(&lock);
    state[i] = THINKING;
    test(LEFT(i));           //revisamos vecino izq
    test(RIGHT(i));          //revismos vecino der
    sem_post(&lock);
    sem_post(&dining);       //libre un espacio para comer
}

void semaphore5::test(int i){
    if (state[i] == HUNGRY &&
        state[LEFT(i)] != EATING &&
        state[RIGHT(i)] != EATING) {
        state[i] = EATING;
        sem_post(&s[i]);  //permitimos filosofo  pueda comer
    }
}