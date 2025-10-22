#include "mutex6.h"

int mutex6::buffer = 100;

mutex6::mutex6(int p, int c) {
    srand(time(NULL));
    this->p = p;
    this->c = c;
}

mutex6::~mutex6() {
    delete[] t1;
    delete[] t2;
}

void mutex6::run() {
    t1 = new std::thread[p];
    for (int i = 0; i < p; i++) {
        t1[i] = std::thread(&mutex6::producer, this);
    }

    t2 = new std::thread[c];
    for (int i = 0; i < c; i++) {
        t2[i] = std::thread(&mutex6::consumer, this);
    }
}

void mutex6::join() {
    for (int i = 0; i < p; i++)
        t1[i].join();
    for (int i = 0; i < c; i++)
        t2[i].join();
}

void mutex6::producer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex_lock);

        //Esperar si el buffer está lleno
        while (buffer >= 400) {
            condition_var.wait(lock);
        }

        buffer++;
        std::cout << "Producing to buffer: " << buffer << std::endl;

        //notifica a consumidor que puede consumir
        condition_var.notify_one();

        lock.unlock();
        sleep(rand() % 2);
    }
}

void mutex6::consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex_lock);

        //esperar si  buffer esta vacío
        while (buffer <= 0) {
            condition_var.wait(lock);
        }

        buffer--;
        std::cout << "Consuming from buffer: " << buffer << std::endl;

        //notificar a un productor que puede producir
        condition_var.notify_one();

        lock.unlock();
        sleep(rand() % 2);
    }
}
