//
// Created by alejandro on 6/19/19.
//

#ifndef UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_REG_H
#define UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_REG_H


#include <iostream>
#include <iomanip>


class matriz_reg {
    int n;//filas
    int m;//columnas


public:
    int** matriz;

    matriz_reg()=default;

    matriz_reg(int n, int m):n{n},m{m}{
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

    matriz_reg* operator*(const matriz_reg rhs) {
        if (m==rhs.n) {
            auto respuesta = new matriz_reg(n, rhs.m);


            for (int i = 0; i < n; i++) {
                for (int j = 0; j < rhs.m; j++) {
                    for (int k = 0; k < rhs.n; k++) {
                        respuesta->matriz[i][j] += (matriz[i][k] * rhs.matriz[k][j]);
                    }
                }
            }

            return respuesta;

        }
        else{
            std::cout<<"Matrices invalidas\n";
            auto respuesta = new matriz_reg(1, 1);
            respuesta->llenarMatriz_un_digito(0);
            return respuesta;
        }
    }

};


#endif //UNIDAD_6_PROGRAMACION_CONCURRENTE_ALEJANDROGH97_MATRIZ_REG_H
