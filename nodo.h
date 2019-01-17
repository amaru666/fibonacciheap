//
// Created by jaox on 2019-01-12.
//

#ifndef FIBONACCI_HEAP_NODO_H
#define FIBONACCI_HEAP_NODO_H

struct nodo {
    int dato;
    int degree = 0;
    bool mark;
    nodo* prev;
    nodo* next;
    nodo* parent;
    nodo* child;
    nodo(int dato):dato{dato}{};
};

#endif //FIBONACCI_HEAP_NODO_H
