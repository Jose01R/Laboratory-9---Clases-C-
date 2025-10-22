#include "semaphore4.h"
#include <cstdlib>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>

#define IT_NUM 5

semaphore4::semaphore4(int n, int valuesArray[]) {
    this->n = n;
    this->values.assign(valuesArray, valuesArray + n);
    sem_init(&semaphore, 1, 1); // semáforo compartido entre procesos
}

semaphore4::~semaphore4() {
    sem_destroy(&semaphore);
}

void semaphore4::printCounter(int value, const std::string& who) {
    int counter = 0;
    sem_wait(&semaphore);  // inicio sección crítica
    std::cout << "counter=" << value << "(" << who << ")→";
    for (int i = 0; i < IT_NUM; ++i) {
        counter += value;
        std::cout << counter;
        if (i != IT_NUM - 1) std::cout << " ";
        std::cout.flush();
        usleep(100000);
    }
    std::cout << std::endl;
    sem_post(&semaphore); // fin sección crítica
}

void semaphore4::start() {
    // padre primero
    printCounter(values[5], "parent");

    // secuencia exacta de los hijos
    int childOrder[] = {0, 2, 3, 4, 1};

    for (int i = 0; i < 5; ++i) {
        printCounter(values[childOrder[i]], "child");
    }
}

