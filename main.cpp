//
// Created by alejandro on 6/19/19.
//

#include <iostream>
#include "matriz_reg.h"
#include "matriz_thread.h"
#include <ctime>
#include <random>

static const int rows = 2000;
static const int columns = 2000;
static const int TOTAL_THREADS = 2;


int main(){
    srand(time(nullptr));

//    matriz_reg m1(rows,columns);
//
//    for(int row = 0;row<rows;row++){
//        for(int column = 0; column<columns;column++) {
//            m1.llenarMatriz_auto(row,column,(rand()%20)+1);
//        }
//    }
//
//
//    matriz_reg m2(rows,columns);
//
//    for(int row = 0;row<rows;row++){
//        for(int column = 0; column<columns;column++) {
//            m2.llenarMatriz_auto(row,column,(rand()%20)+1);
//        }
//    }
//
//    clock_t start_secuential = clock();
//
//    matriz_reg* m3 = m1*m2;
//
//    clock_t end_secuential = clock();
//
//    double total_secuential = double(end_secuential-start_secuential)/(CLOCKS_PER_SEC);
//
//    std::cout<<total_secuential;

//    std::cout<<"NORMAL\n\n";
//    m1.imprimir();
//    std::cout<<"\n";
//    m2.imprimir();
//    std::cout<<"\n";
//    m3->imprimir();
//    std::cout<<"\n";

    matriz_thread m4(rows,columns,TOTAL_THREADS);

    for(int row = 0;row<rows;row++){
        for(int column = 0; column<columns;column++) {
            m4.llenarMatriz_auto(row,column,(rand()%20)+1);
        }
    }


    matriz_thread m5(rows,columns,TOTAL_THREADS);

    for(int row = 0;row<rows;row++){
        for(int column = 0; column<columns;column++) {
            m5.llenarMatriz_auto(row,column,(rand()%20)+1);
        }
    }

    matriz_thread m6(rows,columns,TOTAL_THREADS);

    clock_t start_thread = clock();

    m6.multiplicar_thread(m4,m5);

    clock_t end_thread = clock();

    double total_thread = double(end_thread-start_thread)/(CLOCKS_PER_SEC*TOTAL_THREADS);

    std::cout<<std::endl<<total_thread;

//    std::cout<<"THREAD\n\n";
//    m4.imprimir();
//    std::cout<<"\n";
//    m5.imprimir();
//    std::cout<<"\n";
//    m6.imprimir();
//    std::cout<<"\n";

}