#include "messageCenter.h"

MessageCenter::MessageCenter() {
    if (pipe(pipe_fd) == -1) {
        perror("Error creando pipe");
        exit(1);
    }
}

MessageCenter::~MessageCenter() {
    close(pipe_fd[0]);
    close(pipe_fd[1]);
}

void MessageCenter::threadFunction(const std::string &name) {
    for (int i = 1; i <= 10; i++) {
        std::string message = "Message: " + std::to_string(i) + " of Thread " + name;
        {
            std::lock_guard<std::mutex> lock(mutex_lock);
            write(pipe_fd[1], message.c_str(), message.size() + 1); // +1 para '\0'
        }
        std::cout << "Thread " << name << " sent: " << message << std::endl;
        usleep(200000);
    }
}

void MessageCenter::centralReader() {
    char buffer[256];
    ssize_t n;

    while (true) {
        n = read(pipe_fd[0], buffer, sizeof(buffer));
        if (n > 0) {
            std::cout << "Central reader received: " << buffer << std::endl;
            usleep(300000); //300 milisegundos
        } else if (n == 0) {
            // pipe cerrado, todos los escritores terminaron
            break;
        } else {
            perror("Error leyendo pipe");
            break;
        }
    }

    std::cout << "Message Center simulation is over" << std::endl;
}

void MessageCenter::start() {
    //hilo lector
    std::thread reader(&MessageCenter::centralReader, this);

    //hilos emisores
    threads[0] = std::thread(&MessageCenter::threadFunction, this, "A");
    threads[1] = std::thread(&MessageCenter::threadFunction, this, "B");
    threads[2] = std::thread(&MessageCenter::threadFunction, this, "C");

    //esperar que los hilos emisores terminen
    for (int i = 0; i < 3; i++)
        threads[i].join();

    //cerrar el extremo de escritura para que el lector detecte EOF
    close(pipe_fd[1]);

    //esperar al hilo lector
    reader.join();
}


