#ifndef HW2_H
#define HW2_H

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
struct Heap {
    bool minHeap;

    Heap(bool isMinHeap = true);

    void insert(T const& element);

    T extractTop();

    T peek() const;

    size_t size() const;

    bool isEmpty() const;

    void clear();
};

#include "hw2_impl.h"

#endif
