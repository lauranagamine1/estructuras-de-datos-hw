#ifndef HW3_IMPL_H
#define HW3_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw3.h"

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
void BST<T>::destructorAux(Node<T>* node) {
    if(node == nullptr) {
        return;
    }

    destructorAux(node->left);
    destructorAux(node->right);
    delete node;
}

template <typename T>
BST<T>::~BST() {
    //hacemos un dfs postorder para eliminar los hijos y luego el nodo actual
    destructorAux(root);
}

template <typename T>
Node<T>* BST<T>::insertAux(T const& value, Node<T>* node) {
    if(node == nullptr) {
        return new Node<T>(value);
    }

    if(value < node->val) {
        node->left = insertAux(value, node->left);
    } else {
        node->right = insertAux(value, node->right);
    }

    return node;

}

template <typename T>
void BST<T>::insert(T const& value) {
    root = insertAux(value, root);
}

template <typename T>
bool BST<T>::searchAux(T const& value, Node<T>* node) const {
    if(node == nullptr) {
        return false;
    }
    if(value == node->val) {
        return true;
    }
    if(value < node->val) {
        return searchAux(value, node->left);
    } else {
        return searchAux(value, node->right);
    }
}

template <typename T>
bool BST<T>::search(T const& value) const {
    return searchAux(value, root);
}

template <typename T>
Node<T>* BST<T>::removeAux(T const& value, Node<T>* node) {
    if(node == nullptr) {
        return nullptr;
    }
    if(value == node->val) {
        if(node->left != nullptr && node->right != nullptr) {
            //Tiene dos hijos

            //Obtenemos el menor hijo de la derecha
            Node<T>* temp = node->right;
            if(temp->left != nullptr) {
                while (temp->left->left != nullptr) {
                    temp = temp->left;
                }

                Node<T>* newParent = temp->left;

                temp->left = newParent->right;

                newParent->left = node->left;
                newParent->right = node->right;

                delete node;
                return newParent;
            } else {
                Node<T>* newParent = temp;

                newParent->left = node->left;
                delete node;
                return newParent;
            }

        } else if(node->left != nullptr) {
            //Solo tiene hijo izquierdo
            Node<T>* newParent = node->left;
            delete node;
            return newParent;

        } else if(node->right != nullptr) {
            //Solo tiene hijo derecho
            Node<T>* newParent = node->right;
            delete node;
            return newParent;
        } else {
            //No tiene hijos
            delete node;
            return nullptr;
        }
    }
    if(value < node->val) {
        node->left = removeAux(value, node->left);
    } else {
        node->right = removeAux(value, node->right);
    }
}

template <typename T>
void BST<T>::remove(T const& value) {
    root = removeAux(value, root);
}

template <typename T>
int BST<T>::sizeAux(Node<T>* node) const {
    if(node == nullptr) {
        return 0;
    }

    return sizeAux(node->left) + sizeAux(node->right) + 1;
}

template <typename T>
size_t BST<T>::size() const {
    return sizeAux(root);
}

template <typename T>
T BST<T>::findMin() const {
    Node<T>* temp = root;

    if(temp == nullptr) {
        return T{0};
    }

    while(temp->left != nullptr) {
        temp = temp->left;
    }

    return temp->val;
}

template <typename T>
T BST<T>::findMax() const {
    Node<T>* temp = root;

    if(temp == nullptr) {
        return T{0};
    }

    while(temp->right != nullptr) {
        temp = temp->right;
    }

    return temp->val;
}

template <typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::clear() {
    destructorAux(root);
    root = nullptr;
}


#endif
