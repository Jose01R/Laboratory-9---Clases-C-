#ifndef MESSAGECENTER_H
#define MESSAGECENTER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <string>

class MessageCenter {
public:
    MessageCenter();
    ~MessageCenter();

    void start(); //inicia el centro de mensajes

private:
    int pipe_fd[2];   
    std::mutex mutex_lock;    // mutex para proteger escritura en pipe
    std::thread threads[3];  //tres hilos emisores

    void centralReader();  // hilo que lee mensajes
    void threadFunction(const std::string &name);//hilo que envía mensajes
};

#endif


