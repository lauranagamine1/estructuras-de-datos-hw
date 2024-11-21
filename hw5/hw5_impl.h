#ifndef HW5_IMPL_H
#define HW5_IMPL_H

#include <string>
#include <vector>
#include <stack>
#include <queue>

#include "hw5.h"

void add_edge(std::vector<std::vector<int>>& graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

int n_vertices(std::vector<std::vector<int>> const& graph) {
  return graph.size();
}

int n_edges(const std::vector<std::vector<int>>& graph) {
  int edges = 0;

  for (int i = 0; i < graph.size(); i++) {
    for (int neighbor : graph[i]) {
      if (i < neighbor) {
        edges++;
      }
    }
  }

  return edges;
}


std::vector<int> BFS(const std::vector<std::vector<int>>& graph, int from) {
  std::vector<int> ret;
  std::queue<int> queue;
  std::unordered_set<int> visited;

  queue.push(from);
  visited.insert(from);

  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();
    ret.push_back(current);

    for (int neighbor : graph[current]) {
      if (visited.find(neighbor) == visited.end()) {
        queue.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }

  return ret;
}

std::vector<int> DFS(std::vector<std::vector<int>> const& graph, int from) {
  std::vector<int> ret;
  std::stack<int> stack;
  std::unordered_set<int> visited;

  stack.push(from);
  visited.insert(from);

  while (!stack.empty()) {
    int current = stack.top();
    stack.pop();
    ret.push_back(current);

    for (int neighbor : graph[current]) {
      if (visited.find(neighbor) == visited.end()) {
        stack.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }

  return ret;
}

std::vector<std::vector<int>> connected_components(const std::vector<std::vector<int>>& graph) {
  std::vector<std::vector<int>> ret;
  std::vector<bool> visited(graph.size(), false);

  auto bfs = [&](int start) -> std::vector<int> {
    std::vector<int> component;
    std::queue<int> to_visit;
    to_visit.push(start);
    visited[start] = true;

    while (!to_visit.empty()) {
      int current = to_visit.front();
      to_visit.pop();
      component.push_back(current);

      for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          to_visit.push(neighbor);
        }
      }
    }

    return component;
  };

  for (int i = 0; i < graph.size(); ++i) {
    if (!visited[i]) {
      ret.push_back(bfs(i));
    }
  }

  return ret;
}

int n_connected_components(std::vector<std::vector<int>> const& graph) {
  int n_components = 0;
  std::vector<bool> visited(graph.size(), false);

  auto bfs = [&](int start) {
    std::queue<int> to_visit;
    to_visit.push(start);
    visited[start] = true;

    while (!to_visit.empty()) {
      int current = to_visit.front();
      to_visit.pop();

      for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          to_visit.push(neighbor);
        }
      }
    }
  };

  for (int i = 0; i < graph.size(); ++i) {
    if (!visited[i]) {
      bfs(i);
      n_components++;
    }
  }

  return n_components;
}

#endif
