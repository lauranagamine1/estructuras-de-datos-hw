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

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

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
        return new TreeNode(key);
    }

    if (node != nullptr && key < node->val){
        node->left = insertIntoBST(root->left, key);
    }else if(node != nullptr && key > node->val){
        node->right = insertIntoBST(node->right, key);
    }

    return root;
}

// Eliminar un nodo
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* root, T key) {
  // COMPLETE HERE
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
  // COMPLETE HERE
}

template <typename T>
void AVLTree<T>::remove(T key) {
  // COMPLETE HERE
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
