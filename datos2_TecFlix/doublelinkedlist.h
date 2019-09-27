#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
template <class T>
class DoubleLinkedList
{
private:
    typedef struct node{
        int index;
        T data;
        node* next;
        node* prev;
    } *nodePtr;

    nodePtr first;
    nodePtr curr;
    nodePtr temp;
    int size;


public:
    DoubleLinkedList(){
        first = NULL;
        curr = NULL;
        temp = NULL;
        size = 0;
    }

    ~DoubleLinkedList(){
        curr = first;
        nodePtr next;

        while(curr != NULL){
            next = curr->next;
            free(curr);
            curr = next;
        }
        free(first);
    }

    bool isEmpty(){
        return first == NULL;
    }

    void addLast(T data){
        nodePtr n = new node;
        n->index = size;
        n->next = nullptr;
        n->data = data;

        if(isEmpty()){
            n->prev = nullptr;
            first = n;
            size ++;
            return;
        }

        curr = first;
        while(curr->next!=NULL){
            curr = curr->next;
        }

        curr->next = n;
        n->prev = curr;
        size ++;
        return;
    }

    void addFirst(T data){
        nodePtr n = new node;

        n->index = 0;
        n->data = data;
        n->prev = NULL;
        first->prev = n;
        n->next = first;
        first = n;

        nodePtr aux = first->next;
        while(aux != NULL){
            aux->index = aux->index+1;
            aux = aux->next;
        }
        size++;
    }

    void deleteFirst(){
        if (isEmpty()){
            return;
        }

        temp = first;
        first = first->next;
        first->prev = NULL;

        delete temp;

        nodePtr aux = first->next;
        while(aux != NULL){
            aux->index = aux->index-1;
            aux = aux->next;
        }

        size--;
    }

    void deleteLast(){
        if(isEmpty()){
            return;
        }
        if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
            return;
        }
        else{
            curr = first;
            while(curr->next && curr->next->next != NULL){
                curr = curr->next;
            }
            delete curr->next;
            curr->next = NULL;
            size--;
        }
    }

    int getSize(){
        return size;
    }

    void print(){
        curr = first;
        while(curr!=nullptr){
            std::cout << curr->data << std::endl;
            curr = curr->next;
        }
    }

    void clear(){
        curr = first;
        while(curr != NULL){
            temp = curr->next;
            delete(curr);
            curr = temp;
        }
    }

    node getByPos(int pos) {
        if(isEmpty()){
            std::cout<<"Lista vacía";
            return NULL;
        }
        else{
            nodePtr aux = first;
            while(aux != NULL){
                if(aux->index == pos){
                    return *aux;
                }
                aux = aux->next;
            }
        }
        return NULL;
    }






};


#endif // DOUBLELINKEDLIST_H
