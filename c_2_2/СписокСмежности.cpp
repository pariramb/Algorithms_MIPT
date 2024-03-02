#include <iostream>
#include <vector>

void AddEdge(std::vector<std::vector<int>>& graph, const size_t node1, const size_t node2) {
  graph[node1].push_back(node2);
  graph[node2].push_back(node1);
}

void Vertex(std::vector<std::vector<int>>& graph, const size_t node) {
  for (size_t i = 0, count = graph[node].size(); i < count; i++) {
    std::cout << graph[node][i] << ' ';
  }
  std::cout << '\n';
}

void CommandsResult(std::vector<std::vector<int>>& graph, const size_t count_operationts) {
  int command;
  int node1;
  int node2;
  for (size_t i = 0; i < count_operationts; ++i) {
    std::cin >> command;
    if (command == 1) {
      std::cin >> node1;
      std::cin >> node2;
      AddEdge(graph, node1, node2);
    } else {
      std::cin >> node1;
      Vertex(graph, node1);
    }
  }
}

int main() {
  size_t count_vertexes;
  size_t count_operationts;
  std::cin >> count_vertexes;
  std::cin >> count_operationts;
  std::vector<std::vector<int>> graph;
  graph.resize(count_vertexes + 1);
  CommandsResult(graph, count_operationts);
  return 0;
}
