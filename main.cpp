//
// Created by alejandro on 6/19/19.
//

#include <iostream>
#include "matriz_reg.h"
#include "matriz_thread.h"
#include <ctime>
#include <random>

static const int rows = 10;
static const int columns = 10;


int main(){
    srand(time(nullptr));
    matriz_reg m1(rows,columns);

    for(int row = 0;row<rows;row++){
        for(int column = 0; column<columns;column++) {
            m1.llenarMatriz_auto(row,column,(rand()%20)+1);
        }
    }


    matriz_reg m2(rows,columns);

    for(int row = 0;row<rows;row++){
        for(int column = 0; column<columns;column++) {
            m2.llenarMatriz_auto(row,column,(rand()%20)+1);
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


    matriz_thread m4(rows,columns);

    for(int row = 0;row<rows;row++){
        for(int column = 0; column<columns;column++) {
            m4.llenarMatriz_auto(row,column,(rand()%20)+1);
        }
    }


    matriz_thread m5(rows,columns);

    for(int row = 0;row<rows;row++){
        for(int column = 0; column<columns;column++) {
            m5.llenarMatriz_auto(row,column,(rand()%20)+1);
        }
    }

    matriz_thread m6;

    std::cout<<"THREAD\n\n";
    m4.imprimir();
    std::cout<<"\n";
    m5.imprimir();

    m6.multiplicar_thread(m4,m5);


    std::cout<<"\n";
    m6.imprimir();
    std::cout<<"\n";

}