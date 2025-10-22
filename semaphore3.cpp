#include "semaphore3.h"

semaphore3::semaphore3(int n, std::string arr[]) {
    this->n = n;

    //Copiar cadenas
    for (int i = 0; i <= n; i++)
        cadenas[i] = arr[i];

    //Crear semáforo del sistema
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("Error creando semáforo");
        exit(1);
    }

    //inicializar semáforo con valor 1
    int valorInicial = 1;
    if (semctl(semid, 0, SETVAL, valorInicial) == -1) {
        perror("Error al inicializar semáforo");
        exit(1);
    }
}

semaphore3::~semaphore3() {
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("Error eliminando semáforo");
    }
}

void semaphore3::down() {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}

void semaphore3::up() {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}

void semaphore3::start() {
    pid_t pid;

    for (int i = 0; i < n; i++) {
        pid = fork();

        if (pid < 0) {
            perror("Error en fork");
            exit(1);
        }

        if (pid == 0) { // proceso hijo
            for (int j = 0; j < IT_NUM; j++) {
                down();
                std::cout << cadenas[i] << std::endl;
                fflush(stdout);
                up();
                sleep(1);
            }
            _exit(0);
        }

        //Esperar que el hijo actual termine antes de crear el siguiente
        waitpid(pid, NULL, 0);
    }

    //el padre imprime su cadena 5 veces
    for (int j = 0; j < IT_NUM; j++) {
        down();
        std::cout << cadenas[n] << std::endl;
        fflush(stdout);
        up();
        sleep(1);
    }
}



