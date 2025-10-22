#include "semaphore2.h"
#include <fcntl.h>  // O_CREAT, O_EXCL
#include <cstring>  // memset
#include <cstdlib>  // exit

semaphore2::semaphore2() {
    //Crear semáforo con nombre - cada proceso hijo tiene su propia copia
    sem_unlink("/sem2"); // elimina uno previo si existe
    sem = sem_open("/sem2", O_CREAT, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("ERROR CREATING SEMAPHORE");
        exit(1);
    }
}

semaphore2::~semaphore2() {
    sem_close(sem);
    sem_unlink("/sem2");
}

void semaphore2::start() {
   
    for (int i = 1; i <= 4; ++i) {
        pid_t pid = fork();

        if (pid == 0) {
            //hijo
            sem_wait(sem); //entrar a region critica
            criticalSection(i);
            sem_post(sem); //salir de region critica
            _exit(0); // terminar el hijo
        } else if (pid < 0) {
            perror("ERROR");
            exit(1);
        }
    }

    //esperar a que terminen todos los hijos
    for (int i = 0; i < 4; ++i) {
        wait(NULL);
    }
}

void semaphore2::criticalSection(int id) {
    switch (id) {
        case 1:
            std::cout << "Child No.1" << std::endl;
            for (int i = 1; i <= 100; ++i)
                std::cout << i << (i == 100 ? "\n" : ", ");
            break;

        case 2:
            std::cout << "Child No.2" << std::endl;
            for (char c = 'a'; c <= 'z'; ++c)
                std::cout << c << (c == 'z' ? "\n" : ", ");
            break;

        case 3:
            std::cout << "Child No.3" << std::endl;
            for (int i = 100; i >= 1; --i)
                std::cout << i << (i == 1 ? "\n" : ", ");
            break;

        case 4:
            std::cout << "Child No.4" << std::endl;
            for (char c = 'z'; c >= 'a'; --c)
                std::cout << c << (c == 'a' ? "\n" : ", ");
            break;
    }
    std::cout.flush();
    sleep(1);
}
