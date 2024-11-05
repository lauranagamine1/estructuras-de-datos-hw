#ifndef HW5_H
#define HW5_H

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

void add_edge(std::vector<std::vector<int>>& graph, int from, int to);

int n_vertices(std::vector<std::vector<int>> const& graph);

int n_edges(std::vector<std::vector<int>> const& graph);

std::vector<int> BFS(std::vector<std::vector<int>> const& graph, int from);

std::vector<int> DFS(std::vector<std::vector<int>> const& graph, int from);

std::vector<std::vector<int>> connected_components(
  std::vector<std::vector<int>> const& graph);

int n_connected_components(std::vector<std::vector<int>> const& graph);

#include "hw5_impl.h"

#endif
