//
// Created by alejandro on 6/19/19.
//

#ifndef UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H
#define UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H


#include <iostream>
#include <thread>
#include <bits/stl_vector.h>
#include <vector>

class matriz_thread;
void multiplicar(matriz_thread& m1, matriz_thread& m2, matriz_thread& respuesta, int thread_num, int max_threads);

class matriz_thread {
    int n;//filas
    int m;//columnas
    friend void multiplicar(matriz_thread& m1, matriz_thread& m2, matriz_thread& respuesta, int thread_num, int max_threads);

public:
    int** matriz;

    matriz_thread()=default;

    matriz_thread(int n, int m):n{n},m{m}{
        matriz = new int*[n];
        for(int row = 0;row<n;row++){
            matriz[row]=new int[m];
        }

        for(int row = 0;row<n;row++){
            for(int column = 0; column<n;column++) {
                matriz[row][column]=0;
            }
        }
    }

    void llenarMatriz(int _n, int _m){
        if(_n<n && _n >= 0 && _m<m && _m >= 0) {
            std::cin >> matriz[_n][_m];
        }
    }

    void llenarMatriz(int num){
        for(int row = 0;row<n;row++){
            for(int column = 0;column<m;column++){
                matriz[row][column]=num;
            }
        }
    }

    void imprimir(){
        for(int row = 0;row<n;row++){
            for(int column = 0;column<m;column++){
                std::cout<<matriz[row][column];
            }
            std::cout<<"\n";
        }
    }


    matriz_thread* operator*(const matriz_thread rhs) {

        if (m==rhs.n) {

            auto respuesta = new matriz_thread(n, rhs.m);

            int max_hilos = 3;

            std::thread hilos[max_hilos];

            for (int i = 0; i < max_hilos; i++) {

                hilos[i]= std::thread(multiplicar,
                                            std::ref(*this),
                                      std::ref(rhs),
                                            std::ref(respuesta),
                                            i,
                                            max_hilos);


                for (int i = 0;i<max_hilos;i++) {
                    hilos[i].join();
                }


            }
        }

        else{
            std::cout<<"Matrices invalidas\n";
            auto respuesta = new matriz_thread(1, 1);
            respuesta->llenarMatriz(0);
            return respuesta;
        }
    }

};

void multiplicar(matriz_thread& m1, matriz_thread& m2, matriz_thread& respuesta, int thread_num, int max_threads){

    for (int i = thread_num*m1.n/max_threads; i < (thread_num+1)*m1.n/max_threads; i++) {
        for (int j = 0; j < m2.m; j++) {
            for (int k = 0; k < m2.n; k++) {
                respuesta.matriz[i][j] += (m1.matriz[i][k] * m2.matriz[k][j]);
            }
        }
    }
};


#endif //UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H
