#ifndef HW3_H
#define HW3_H

/*******************************************************************************

MODIFIQUE ESTE ARCHIVO Y LA CORRESPONDIENTE IMPLEMENTACIÓN A SU GUSTO.


Los tests que se usarán para calificar esta tarea serán los provistos en el
archivo de tests y muchos otros. El archivo de tests se incluye solo a modo
de referencia, pero no es una version completa de los tests que serán
utilizados.

Todas las funciones listadas en este archivo serán testeadas por el corrector
automático, con el mismo prototipo mostrado en este archivo.

*******************************************************************************/

template <typename T>
struct Node {
    T val;
    Node* left;
    Node* right;

    Node(T val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
struct BST {
    Node<T>* root;

    BST();

    void destructorAux(Node<T>* node);

    ~BST();

    Node<T>* insertAux(T const& value, Node<T>* node);

    void insert(T const& value);

    bool searchAux(T const& value, Node<T>* node) const;

    bool search(T const& value) const;

    Node<T>* removeAux(T const& value, Node<T>* node);

    void remove(T const& value);

    int sizeAux(Node<T>* node) const;

    size_t size() const;

    T findMin() const;

    T findMax() const;

    bool isEmpty() const;

    void clear();
};

#include "hw3_impl.h"

#endif
