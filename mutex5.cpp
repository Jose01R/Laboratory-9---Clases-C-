
#include "mutex5.h"

int mutex5::buffer = 100;

mutex5::mutex5(std::mutex *mutex, int p, int c) {
    srand(time(NULL)); //seed

    this->mutex = mutex;
    this->p = p;
    this->c = c;
}

mutex5::mutex5(const mutex5& orig) {
}

mutex5::~mutex5() {
}

void mutex5::run() {
    t1 = new std::thread[p]; //array de hilos para prod
    t2 = new std::thread[c]; //array de hilos para prod

    for (int i = 0; i < p; i++) {
        this->t1[i] = std::thread(&mutex5::producer, this); //creamos hilos
    }
    for (int i = 0; i < p; i++) {
        this->t2[i] = std::thread(&mutex5::consumer, this); //creamos hilos
    }
}

void mutex5::join() {
    for (int i = 0; i < p; i++) {
        this->t1[i].join(); //hacemos que hilos sean randomly
    }

    for (int i = 0; i < c; i++) {
        this->t2[i].join(); //hacemos que hilos sean randomly
    }
}


//funcion hilos - implementacion

void mutex5::producer() {
    mutex->lock();

    for (int i = 0; i < IT_NUM; i++) {
        std::cout << "Producing to buffer: " << (this->buffer += 1) << "\n";
        fflush(stdout);
        sleep(rand() % 2);
    }

    mutex->unlock();
}

void mutex5::consumer() {
    mutex->lock();

    for (int i = 0; i < IT_NUM; i++) {
        std::cout << "Consuming to buffer: " << (this->buffer -= 1) << "\n";
        fflush(stdout);
        sleep(rand() % 2);
    }

    mutex->unlock();
}

