#ifndef AVL_H
#define AVL_H

/*******************************************************************************

MODIFIQUE ESTE ARCHIVO Y LA CORRESPONDIENTE IMPLEMENTACIÓN A SU GUSTO.


La interfaz publica de AVLTree expuesta en este archivo será testeada. Pueden
incluirse mas funciones, pero al menos las listadas aquí deberán implementarse.

Los tests que se usarán para calificar esta tarea serán los provistos en el
archivo de tests y muchos otros, similares a esos.

La interfaz privada se incluye solo a modo de sugerencia. Lo que será testeado
será la interfaz pública.

*******************************************************************************/

template <typename T>
struct AVLNode {
  T data;
  AVLNode* left;
  AVLNode* right;
  int height;
  AVLNode(T value);
};

template <typename T>
class AVLTree {
 private:
  AVLNode<T>* root;

  int height(AVLNode<T>* node);
  int getBalance(AVLNode<T>* node);

  AVLNode<T>* rightRotate(AVLNode<T>* y);
  AVLNode<T>* leftRotate(AVLNode<T>* x);

  AVLNode<T>* minValueNode(AVLNode<T>* node);

  AVLNode<T>* insert(AVLNode<T>* node, T key);
  AVLNode<T>* remove(AVLNode<T>* root, T key);
  bool search(AVLNode<T>* node, T key);

  void preorder(AVLNode<T>* root, std::vector<T>& ret);
  void inorder(AVLNode<T>* root, std::vector<T>& ret);
  void postorder(AVLNode<T>* root, std::vector<T>& ret);

 public:
  AVLTree();

  void insert(T key);
  void remove(T key);
  bool search(T key);
  std::vector<T> preorderTraversal();
  std::vector<T> inorderTraversal();
  std::vector<T> postorderTraversal();
  int height();
  bool isBalanced();
};

#include "avl_impl.h"

#endif
