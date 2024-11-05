#ifndef HW4_H
#define HW4_H

/*******************************************************************************

MODIFIQUE ESTE ARCHIVO Y LA CORRESPONDIENTE IMPLEMENTACIÓN A SU GUSTO.


Los tests que se usarán para calificar esta tarea serán los provistos en el
archivo de tests y muchos otros. El archivo de tests se incluye solo a modo
de referencia, pero no es una version completa de los tests que serán
utilizados.

Todas las funciones listadas en este archivo serán testeadas por el corrector
automático, con el mismo prototipo mostrado en este archivo.

*******************************************************************************/

#include <vector>
#include <string>

std::vector<int> stringMatch_naive(std::string const& text,
                                   std::string const& pattern);

std::vector<int> stringMatch_RabinKarp(std::string const& text,
                                       std::string const& pattern);

std::vector<int> stringMatch_KnuthMorrisPratt(std::string const& text,
                                              std::string const& pattern);

#include "hw4_impl.h"

#endif
