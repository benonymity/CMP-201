//
// By Benjamin Bassett (benonymity) on 4.16.24
//
// For CMP-201 with Dr. Seiffert at Hillsdale College
// https://github.com/benonymity/CMP-201
//

#include <iostream>
#include <vector>

class Graph {
  public:
    // Constructor
    Graph() {}

    // Add an edge
    void add_edge(int x, int y, int v) {
        int new_size = std::max(x, y) + 1;
        if (new_size > graph.size()) {
            // Resize each row
            for (auto& row : graph) {
                row.resize(new_size, false);
            }
            // Resize the graph to the new size
            graph.resize(new_size, std::vector<int>(new_size, 0));
        }
        graph[x][y] = v;
    }

    // Remove an edge
    void remove_edge(int x, int y, int v) {
        graph[x][y] = 0;
    }

    // Depth-first search
    void dfs(int start) {
        std::vector<bool> visited(graph.size(), false);
        // Start DFS from the start node, initial call with no parent edge value
        dfsRecursive(start, visited, -1);
    }

    // Depth-first search recursive helper
    void dfsRecursive(int node, std::vector<bool>& visited, int incomingValue) {
        visited[node] = true;
        // Print node and value of the provided edge
        if (incomingValue != -1) {
            std::cout << "Node " << node << " via edge value " << incomingValue << std::endl;
        } else {
            // Print start node
            std::cout << "Start Node " << node << std::endl;
        }

        // Visit all nearby nodes
        for (int i = 0; i < graph[node].size(); i++) {
            if (graph[node][i] != 0 && !visited[i]) {  // Check if there's a valid edge
                dfsRecursive(i, visited, graph[node][i]);
            }
        }
    }

    // Print the graph
    void print() {
        for (auto& row : graph) {
            for (auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
  private:
    // The graph
    std::vector<std::vector<int>> graph;
};

int main() {
    // Initialize the graph
    Graph graph;

    // Add some edges
    graph.add_edge(0, 1, 50);
    graph.add_edge(0, 2, 100);
    graph.add_edge(1, 1, 90);
    graph.add_edge(2, 0, 60);
    graph.add_edge(2, 3, 43);
    graph.add_edge(3, 3, 17);

    // Print the graph
    graph.print();
    std::cout << std::endl;

    // Do a depth-first search
    graph.dfs(0);
}