//
// Created by alejandro on 6/19/19.
//

#include <iostream>
#include "matriz_reg.h"
#include "matriz_thread.h"

int main(){
    matriz_reg m1(3,2);

    for(int row = 0;row<3;row++){
        for(int column = 0; column<3;column++) {
            m1.llenarMatriz(row,column);
        }
    }


    matriz_reg m2(2,1);

    for(int row = 0;row<3;row++){
        for(int column = 0; column<3;column++) {
            m2.llenarMatriz(row,column);
        }
    }

    matriz_reg* m3 = m1*m2;

    std::cout<<"NORMAL\n\n";
    m1.imprimir();
    std::cout<<"\n";
    m2.imprimir();
    std::cout<<"\n";
    m3->imprimir();
    std::cout<<"\n";


    matriz_thread m4(3,2);

    for(int row = 0;row<3;row++){
        for(int column = 0; column<3;column++) {
            m4.llenarMatriz(row,column);
        }
    }


    matriz_thread m5(2,1);

    for(int row = 0;row<3;row++){
        for(int column = 0; column<3;column++) {
            m5.llenarMatriz(row,column);
        }
    }

    matriz_thread* m6 = m4*m5;

    std::cout<<"THREAD\n\n";
    m4.imprimir();
    std::cout<<"\n";
    m5.imprimir();
    std::cout<<"\n";
    m6->imprimir();
    std::cout<<"\n";

}