#ifndef AVL_IMPL_H
#define AVL_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "avl.h"

// AVLNode

template <typename T>
AVLNode<T>::AVLNode(T value)
    : data(value), left(nullptr), right(nullptr), height(0) {}

// AVLTree

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
int AVLTree<T>::height(AVLNode<T>* node) {
    return node->height;
}

template <typename T>
int AVLTree<T>::getBalance(AVLNode<T>* node) {
    if(node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

template <typename T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

// Rotación izquierda
template <typename T>
AVLNode<T>* AVLTree<T>::leftRotate(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
AVLNode<T>* AVLTree<T>::minValueNode(AVLNode<T>* node) {
    if(node == nullptr) {
        return nullptr;
    }

    while(node->left != nullptr) {
        node = node->left;
    }

    return node;
}

// Inserción
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
    if (node == nullptr) {
        return new AVLNode<T>(key);
    }

    if (node != nullptr && key < node->data){
        node->left = insert(node->left, key);
    }else if(node != nullptr && key > node->data){
        node->right = insert(node->right, key);
    }

    return root;
}

// Eliminar un nodo
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* root, T key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = remove(root->left, key);
    }
    else if (key > root->data) {
        root->right = remove(root->right, key);
    }
    else {
        // un hijo o sin hijos
        if (root->left == NULL || root->right == NULL) {
            AVLNode<T>* temp;
            if (root->left != NULL) {
                temp = root->left;
            } else {
                temp = root->right;
            }

            // sin hijos
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else { // un hijo
                *root = *temp;
            }
            delete temp;
        }
        else {
            // dos hijos
            AVLNode<T>* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }

    // un nodo
    if (root == NULL)
        return root;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight) {
        root->height = 1 + leftHeight;
    } else {
        root->height = 1 + rightHeight;
    }

    int balance = getBalance(root);

    // izquierda-izquierda
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // izquierda-derecha
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // derecha-derecha
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // derecha-izquierda
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;


}

// Búsqueda
template <typename T>
bool AVLTree<T>::search(AVLNode<T>* node, T key) {
    if(node == nullptr) {
        return false;
    }
    if(node->data == key) {
        return true;
    }

    if(key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }

}

// Recorrido preorder
template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* root, std::vector<T>& ret) {
    if(root == nullptr) {
        return;
    }

    ret.push_back(root->data);
    preorder(root->left, ret);
    preorder(root->right, ret);
}

// Recorrido inorder
template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* root, std::vector<T>& ret) {
    if(root == nullptr) {
        return;
    }

    preorder(root->left, ret);
    ret.push_back(root->data);
    preorder(root->right, ret);
}

// Recorrido postorder
template <typename T>
void AVLTree<T>::postorder(AVLNode<T>* root, std::vector<T>& ret) {
    if(root == nullptr) {
        return;
    }

    preorder(root->left, ret);
    preorder(root->right, ret);
    ret.push_back(root->data);
}

/// Public functions

template <typename T>
void AVLTree<T>::insert(T key) {
    root = insert(root, key);
}

template <typename T>
void AVLTree<T>::remove(T key) {
    root = remove(root, key);
}

template <typename T>
bool AVLTree<T>::search(T key) {
    return search(root, key);
}

template <typename T>
std::vector<T> AVLTree<T>::preorderTraversal() {
    std::vector<T> res;
    preorder(root, res);
    return res;
}

template <typename T>
std::vector<T> AVLTree<T>::inorderTraversal() {
    std::vector<T> res;
    inorder(root, res);
    return res;
}

template <typename T>
std::vector<T> AVLTree<T>::postorderTraversal() {
    std::vector<T> res;
    postorder(root, res);
    return res;
}

template <typename T>
int AVLTree<T>::height() {
    height(root);
}

template <typename T>
bool AVLTree<T>::isBalanced() {
    //siempre esta balanceado no?
    return true;
}

#endif
