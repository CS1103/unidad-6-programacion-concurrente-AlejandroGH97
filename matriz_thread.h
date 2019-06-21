//
// Created by alejandro on 6/19/19.
//

#ifndef UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H
#define UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H


#include <iostream>
#include <thread>
#include <bits/stl_vector.h>
#include <vector>

static const int thread_num = 2;


class matriz_thread {
    int n;//filas
    int m;//columnas

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


    void multiplicar(matriz_thread& m1, matriz_thread& m2, int thread){

        for (int i = thread*m1.n/thread_num; i < (thread+1)*m1.n/thread_num; i++) {
            for (int j = 0; j < m2.m; j++) {
                for (int k = 0; k < m2.n; k++){
                    std::cout<<i<<j<<std::endl;
                    matriz[i][j] += (m1.matriz[i][k] * m2.matriz[k][j]);
                }
            }
        }

    }


    void multiplicar_thread(matriz_thread& m1, matriz_thread& m2){

        n=m1.n;
        m=m2.m;
        std::vector<std::thread> threads(thread_num);

        int** temp = new int*[m1.n];
        for(int i = 0; i<m2.m;i++){
            temp[i]=new int[m2.m]{0};
        }

        matriz=temp;

        int pos = 0;

        for(auto& h:threads){
            h=std::thread(&matriz_thread::multiplicar,this,std::ref(m1),std::ref(m2),pos);
            pos++;
        }

        for(auto& i: threads){
            i.join();
        }

    };

};



#endif //UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_THREAD_H
