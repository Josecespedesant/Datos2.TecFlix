#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
template <class T>

/*!
 * \brief Declaración de la clase LinkedList
 */
class LinkedList
{
private:
    typedef struct node{
        int index;
        T data;
        node* next;
    } *nodePtr;

    nodePtr first;
    nodePtr curr;
    nodePtr temp;
    int size;

public:
    /*!
     * \brief Constructor de la clase LinkedList
     */
    LinkedList(){
        first = NULL;
        curr = NULL;
        temp = NULL;
        size = 0;
    }

    /*!
     * \brief Destructor de la clase LinkedList
     */
    ~LinkedList(){
        curr = first;
        nodePtr next;

        while(curr != NULL){
            next = curr->next;
            free(curr);
            curr = next;
        }
        free(first);
    }

    /*!
     * \brief Añade al final
     * \param data
     */
    void addLast(T data){
        nodePtr n = new node;
        n->index = size;
        n->next = NULL;
        n->data = data;
        if(!isEmpty()){
            curr = first;
            while(curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = n;
        }else{
            first = n;
        }
        size++;
    }

    /*!
     * \brief Obtiene la posicion dado un elemento
     * \param elem
     * \return
     */
    int getPosByElem(T elem){
        if(!isEmpty()){
            curr = first;
            while(curr->next!=NULL){
                if(curr->data == elem){
                    return curr->index;
                }
                curr = curr->next;
            }
        }else{
            return NULL;
        }
    }

    /*!
     * \brief Devuelve elemento dada posicíon
     * \param pos
     * \return
     */
    T getByPos(int pos) {
        if(first == NULL){
            std::cout<<"Lista vacía";
            return NULL;
        }
        else{
            nodePtr aux = first;
            while(aux != NULL){
                if(aux->index == pos){
                    return aux->data;
                }
                aux = aux->next;
            }
        }
        return NULL;
    }

    /*!
     * \brief Borra el ultimo nodo
     */
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
    /*!
     * \brief Inserta al inicio
     * \param data
     */
    void addFirst(T data){
        nodePtr n = new node;
        n->index = 0;
        n->data = data;
        n ->next = first;
        first = n;

        nodePtr aux = first->next;
        while(aux != NULL){
            aux->index = aux->index+1;
            aux = aux->next;
        }

        size++;
    }
    /*!
     * \brief Borra el primer nodo
     */
    void deleteFirst(){
        if (isEmpty()){
            return;
        }
        temp = first;
        first = first->next;
        delete temp;

        nodePtr aux = first->next;
        while(aux != NULL){
            aux->index = aux->index-1;
            aux = aux->next;
        }

        size--;
    }

    /*!
     * \brief Borra un nodo dada la data
     * \param data
     */
    void deleteNode(T data){
        nodePtr delPtr = NULL;
        temp = first;
        curr = first;

        if(first->data == data){
            deleteFirst();
            size--;
            return;
        }

        while(curr != NULL && curr->data != data){
            temp = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            return;
        }
        else{
            delPtr = curr;
            curr = curr->next;
            temp->next = curr;
            delete(delPtr);
            size--;
        }
    }
    /*!
     * \brief Devuelve el tamaño
     * \return
     */
    int getSize(){
        return size;
    }
    /*!
     * \brief Devuelve si la lista esta vacía
     * \return
     */
    bool isEmpty(){
        return first == NULL;
    }
    /*!
     * \brief Imprime la lista
     */
    void print(){
        curr = first;
        while(curr!=nullptr){
            std::cout << curr->data << std::endl;
            curr = curr->next;
        }
    }

    /*!
     * \brief Borra la lista
     */
    void clear(){
        curr = first;
        while(curr != NULL){
            temp = curr->next;
            delete(curr);
            curr = temp;
        }
    }
};

#endif // LINKEDLIST_
