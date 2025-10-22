
#include "mutex1.h"

mutex1::mutex1(std::mutex *mutex, char character) {
    srand(time(NULL)); //seed
    this->mutex = mutex;
    this->character = character;
}

mutex1::mutex1(const mutex1& orig) {
}

mutex1::~mutex1() {
}

void mutex1::run(){ 
    //si funcion hilo lleva parametros se idnican despues del 'this' separados por coma (,)
    this->t = std::thread(&mutex1::threadFunction, this); //creamos hilos
}

void mutex1::join(){
    this->t.join(); //hacemos que hilos sean randomly
}

void mutex1::threadFunction(){
    this->mutex->lock(); //entramos en region critica
    for(int i = 0; i < IT_NUM; i++){
        std::cout << this->character;
        fflush(stdout);
        sleep(rand()%2);
    }
    this->mutex->unlock(); //salimos de region critica
    
}
