//
// Created by alejandro on 6/19/19.
//

#ifndef UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H
#define UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H


#include <iostream>
#include <thread>
#include <bits/stl_vector.h>
#include <vector>
#include <iomanip>
#include <mutex>


class matriz_thread {
    std::mutex mtx;
    int n;//filas
    int m;//columnas
    int thread_num;

public:
    int** matriz;

    matriz_thread()=default;

    matriz_thread(int n, int m, int thread_num):n{n},m{m},thread_num{thread_num}{
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

    void llenarMatriz_auto(int _n, int _m, int num){
        if(_n<n && _n >= 0 && _m<m && _m >= 0) {
            matriz[_n][_m]=num;
        }
    }

    void llenarMatriz_por_coordenada(int _n, int _m){
        if(_n<n && _n >= 0 && _m<m && _m >= 0) {
            std::cin >> matriz[_n][_m];
        }
    }

    void llenarMatriz_un_digito(int num){
        for(int row = 0;row<n;row++){
            for(int column = 0;column<m;column++){
                matriz[row][column]=num;
            }
        }
    }

    void imprimir(){
        for(int row = 0;row<n;row++){
            for(int column = 0;column<m;column++){
                std::cout<<std::setw(5)<<matriz[row][column];
            }
            std::cout<<"\n";
        }
    }


    void multiplicar(matriz_thread& m1, matriz_thread& m2, int thread){

        for (int i = thread*m1.n/thread_num; i < (thread+1)*m1.n/thread_num; i++) {
            for (int j = 0; j < m2.m; j++) {
                for (int k = 0; k < m2.n; k++){
                    matriz[i][j] += (m1.matriz[i][k] * m2.matriz[k][j]);
                }
            }
        }

    }


    void multiplicar_thread(matriz_thread& m1, matriz_thread& m2) {

        if (m1.m == m2.n) {
//        n=m1.n;
//        m=m2.m;
//
//        int** temp = new int*[m1.n];
//        for(int i = 0; i<n;i++){
//            temp[i]=new int[m2.m]{0};
//        }
//
//        matriz=temp;

            std::vector<std::thread> threads(thread_num);

            int pos = 0;

            for (auto &h:threads) {
                h = std::thread(&matriz_thread::multiplicar, this, std::ref(m1), std::ref(m2), pos);
                pos++;
            }

            for (auto &i: threads) {
                i.join();
            }

        }else{
            std::cout<<"Matrices invalidas.";
        }

    }
};



#endif //UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H
