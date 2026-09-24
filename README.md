# Laboratorio 9 - Clases y sincronización en C++

Este repositorio forma parte del curso de Sistemas Operativos y está orientado al estudio de la sincronización de hilos y procesos en C++.

## Descripción

El proyecto reúne ejemplos prácticos de:

- Clases y encapsulación en C++
- Hilos de ejecución
- Exclusión mutua con `mutex`
- Coordinación de procesos con `semaphore`
- Problemas clásicos de sincronización
- Comunicación entre tareas concurrentes

El objetivo principal es comprender cómo evitar condiciones de carrera, interbloqueos y problemas de consistencia al trabajar con concurrencia.

## Temas tratados

- Conceptos básicos de procesos y hilos
- Problemas de concurrencia
- `mutex` para asegurar acceso exclusivo a recursos compartidos
- `semaphore` para controlar acceso y coordinación entre tareas
- Patrones de productor-consumidor
- Manejo de recursos compartidos y sincronización
- Implementación de clases reutilizables para ejercicios de laboratorio

## Estructura del repositorio

Los archivos principales incluyen:

- `main.cpp`: punto de entrada del laboratorio
- `mutex*.h` / `mutex*.cpp`: implementaciones de ejercicios con mutex
- `semaphore*.h` / `semaphore*.cpp`: implementaciones de ejercicios con semáforos
- `messageCenter.*`: ejemplo de coordinación entre procesos o componentes
- `Makefile`: configuración para compilar el proyecto

## Requisitos

- Compilador de C++ compatible con C++11 o superior
- Make
- Entorno Linux/Unix (o un sistema compatible con herramientas POSIX)

## Instrucciones clave

1. Clona el repositorio.
2. Abre la carpeta del proyecto.
3. Compila con:

```bash
make
```

4. Si deseas limpiar los artefactos compilados:

```bash
make clean
```

5. Para ejecutar el programa resultante, usa la salida generada por el proyecto en tu entorno de compilación.

## Importante

En `main.cpp` se encuentran varios ejemplos comentados; cada bloque representa un ejercicio distinto. Para probar una práctica en particular, descomenta el bloque correspondiente y vuelve a compilar.

Esto permite ejecutar de forma independiente ejemplos de:

- mutex
- semáforos
- sincronización entre múltiples tareas
- modelos de producción/consumo

## Objetivo académico

El laboratorio busca desarrollar una base sólida en programación concurrente y sincronización, elementos fundamentales en sistemas operativos y en el diseño de software multitarea.

---

Este proyecto fue desarrollado con fines académicos dentro del curso de Sistemas Operativos.
