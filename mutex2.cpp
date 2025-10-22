#include "mutex2.h"

mutex2::mutex2(std::mutex* mutex, const void* array, int size, int threadNumber, std::string type) {
    this->mutex = mutex;
    this->array = array;
    this->size = size;
    this->threadNumber = threadNumber;
    this->type = type;
}

mutex2::~mutex2() {
    t.join();
}

void mutex2::run() {
    t = std::thread(&mutex2::threadFunction, this);
}

void mutex2::join() {
    t.join();
}

void mutex2::threadFunction() {
    mutex->lock(); //entramos en region critica
 
    std::cout << "Thread no. " << threadNumber << " = ";

    //VERIFICAMOS SI ES ENTERO O CHAR EL ARR
    if (type == "CHAR") {
        const char* arr = static_cast<const char*>(array);
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << ' ';
    } else if (type == "INT") {
        const int* arr = static_cast<const int*>(array);
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
    fflush(stdout);
    sleep(rand() % 2);

    mutex->unlock(); //salimos de region critica
}
