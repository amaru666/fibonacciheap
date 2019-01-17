//
// Created by jaox on 2019-01-12.
//

#ifndef FIBONACCI_HEAP_FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_FIBONACCI_HEAP_H

#include <iostream>
#include <cmath>
#include "nodo.h"

struct linkedlist {
    nodo* head;
    int nodos = 0;
    void insert(nodo* nuevo) {
        if(find(nuevo)) std::cout<<"no se puede ingresar dos veces el mismo valor"<<'\n';
        else {
            if(!head) {
                head= nuevo;
                nuevo->next = nuevo;
                nuevo->prev = nuevo;
            }else {
                nuevo->prev = head->prev;
                head->prev->next = nuevo;
                nuevo->next = head;
                head->prev = nuevo;
            }
            nodos++;
        }
    }
    nodo* find(nodo* nuevo) {
        if(head){
            nodo* temp = head;
            do{
                if(temp->dato == nuevo->dato) return temp;
                temp = temp->next;
            }while(temp != head);
        }
        return nullptr;
    }
};

struct fibonacciheap{
    linkedlist rootlist;
    nodo* min;
    int n;   //numero de nodos
    fibonacciheap() {}
    void insert(int dato){
        nodo* nuevo = new nodo(dato);
        nuevo->degree = 0;
        nuevo->parent = nullptr;
        nuevo->child = nullptr;
        nuevo->mark = false;
        if(!min) {
            min = nuevo;
        } else if(min->dato > nuevo->dato) min = nuevo;
        rootlist.insert(nuevo);
        n++;
    }
    nodo* extractmin(){
        nodo* minimum = min;
        if(minimum) {
            if(minimum->child) {
                nodo* temp = minimum->child;
                do{
                    nodo* save = temp->next;  //add children to rootlist
                    temp->next = min;
                    temp->prev = min->prev;
                    min->prev = temp;
                    temp->prev->next = temp;
                    temp->parent = nullptr;
                    temp = save;
                    rootlist.nodos++;
                }while(temp != minimum->child);
            }
            minimum->prev->next = minimum->next;
            minimum->next->prev = minimum->prev;
            if(min->next == min) min = nullptr;
            else {
                min = min->next;
                consolidate();
            }
            minimum->next = nullptr;
            minimum->prev = nullptr;
            n--;
            rootlist.nodos--;
        }
        return minimum;
    }
    void consolidate() {
       //maximun degree of any node in an n-node fibonacci heap is O(lg(n))
       int m = log(n)/log(2);
       nodo* array[m];
       for(int i = 0; i <= m; i++)
           array[i]= nullptr;
       nodo* temp = min;
       int currentnodes = rootlist.nodos-1;
       for(int i = 0; i < currentnodes; i++) {
           nodo* current = temp;
           int d = temp->degree;
           nodo* proof = array[d];
           while(array[d]) {
               nodo* another = array[d];
               if(current->dato > another->dato) {
                   nodo* aux = another;
                   another = current;
                   current = aux;
               }
               fibonacci_link(another, current);
               array[d] = nullptr;
               d++;
           }
           array[d] = current;
           temp = current->next;
       }
       min = nullptr;
       for(int i = 0; i <= m; i++){
           if(array[i]){
               if(!min){
                   min=array[i];
               } else if(min->dato > array[i]->dato) min = array[i];
           }
       }
       rootlist.head = min;
    }
    void fibonacci_link(nodo* y, nodo* x){
        //remove y from the root list
        y->prev->next = y->next;
        y->next->prev = y->prev;
        y->prev = y;
        y->next = y;
        if(!x->child) {
            x->child = y;
            y->parent = x;
            x->degree++;
        } else {
            nodo* child = x->child;
            y->prev = child->prev;
            child->prev->next = y;
            y->next = child;
            child->prev = y;
            x->degree++;
            y->mark = false;
            y->parent = x;
        }
        rootlist.nodos--;
    }
};

#endif //FIBONACCI_HEAP_FIBONACCI_HEAP_H
