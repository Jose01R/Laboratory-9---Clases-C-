/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: joram
 *
 * Created on October 20, 2025, 5:18 PM
 */

#include <cstdlib>
#include "mutex1.h"
#include "mutex2.h"
#include "mutex4.h"
#include "mutex5.h"
#include "semaphore5.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

//    //MUTEX1
//    mutex1 *m[5];
//    std::mutex mutex;
//    char a[] = {'*', '$', '#', '%', '&', '!', '+', '-', '<', '>'};
//    
//    //creamos instancia de la clase Mutex1 y se asignan los caracteres
//    for(int i = 0; i < 5; i++){
//        //instanciamos e asignamos un char
//        m[i] = new mutex1(&mutex, a[i]);
//        //lanzamos el hilos
//        m[i]->run();
//        
//        //puedo hacer join aca cuando necesito que sean secuenciales
//    }
//    
//    //se hacen los join - a parte para q hilos sean aleatorios
//    for(int i = 0; i < 5; i++){
//        m[i]->join();
//    }
//    
    
    //MUTEX2
    srand(time(NULL));
    mutex2* m[4];
    std::mutex mutex;

    int a[100];
    char b[32];
    int c[100];
    char d[32];

    for (int j = 0; j < 100; j++)
        a[j] = j + 1;

    for (int j = 0; j < 26; j++)
        b[j] = 'a' + j;
    b[26] = '\0';

    for (int j = 0; j < 100; j++)
        c[j] = 100 - j;

    for (int j = 0; j < 26; j++)
        d[j] = 'z' - j;
    d[26] = '\0';

    m[0] = new mutex2(&mutex, a, 100, 1, "INT");
    m[1] = new mutex2(&mutex, b, 26, 2, "CHAR");
    m[2] = new mutex2(&mutex, c, 100, 3, "INT");
    m[3] = new mutex2(&mutex, d, 26, 4, "CHAR");

    for (int i = 0; i < 4; i++)
        m[i]->run();

    for (int i = 0; i < 4; i++)
        m[i]->join();

   
    
    
    //MUTEX4
//    mutex4 *m[10];
//    std::mutex mutex;
//    int n = 10;
//    int a[] = {-5, 10, 15, 25, -30, -8, 5, 7, -9, -2};
//    
//    //creamos instancia de la clase Mutex1 y se asignan los caracteres
//    for(int i = 0; i < n; i++){
//        //instanciamos e asignamos un char
//        m[i] = new mutex4(&mutex, a[i]);
//        //lanzamos el hilos
//        m[i]->run();
//        
//        //puedo hacer join aca cuando necesito que sean secuenciales
//    }
//    
//    //se hacen los join - a parte para q hilos sean aleatorios
//    for(int i = 0; i < n; i++){
//        m[i]->join();
//    }
    
    //MUTEX 5
//    std::mutex mutex;
//    mutex5 *m = new mutex5(&mutex, 2, 3);
//    m->run();
//    m->join();
    
    //SEMAPHORE 5 - FILOSOFOS
//    semaphore5 *s = new semaphore5();
//    s->start();
//    s->join();
    
    
    return 0;
}

