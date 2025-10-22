#include "semaphore1.h"
#include <cstdlib>
#include <ctime>

semaphore1::semaphore1(int n, char* symbols) {
    this->n = n;
    this->symbols = symbols;

    //crear semaforo (System V)
    key_t key = ftok(".", 'S');
    semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("ERROR");
        exit(1);
    }

    //inicializar semaforo con valor 1
    semctl(semid, 0, SETVAL, 1);
}

semaphore1::~semaphore1() {
    //eliminar semaforo
    semctl(semid, 0, IPC_RMID, 0);
}

//Wait
void semaphore1::P() {
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = -1;
    op.sem_flg = 0;
    semop(semid, &op, 1);
}

//Signal
void semaphore1::V() {
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = 1;
    op.sem_flg = 0;
    semop(semid, &op, 1);
}

void semaphore1::childProcess(char c) {
    srand(getpid());
    for (int i = 0; i < IT_NUM; ++i) {
        P(); // entramos a region critica
        
        for (int j = 0; j < IT_NUM; ++j)
            std::cout << c;
        std::cout.flush();
        
        V(); //salimos de region critica
        usleep(200000 + rand() % 300000); 
    }
    _exit(0); //terminar el hijo
}

//iniciar procesos 
void semaphore1::start() {
    for (int i = 0; i < n; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            childProcess(symbols[i]);
        } else if (pid < 0) {
            perror("Error al crear proceso hijo");
        }
    }

    //padre imprime su propio char
    char parentChar = '@';
    for (int i = 0; i < IT_NUM; ++i) { //for para determinar cuantas veces entra un proceso a la regon critica
        P();
        for (int j = 0; j < IT_NUM; ++j) //for para imprimir secuencia
            std::cout << parentChar;
        std::cout.flush();
        V();
        usleep(300000 + rand() % 200000);
        
        //NOTA: SI SOLO SE USA UN FOR (INTERNO) - IMPRIME SECUENCIA DESORDENADA
    }

    //esepramos a que terminen los hijos
    for (int i = 0; i < n; ++i)
        wait(NULL);

}
