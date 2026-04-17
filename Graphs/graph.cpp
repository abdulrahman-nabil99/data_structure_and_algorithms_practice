#include <iostream>
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

void breadth_first_search(int** graph, int n, int start) {
    bool* visited = new bool[n] { false };

    LinkedListQueue<int> q;

    visited[start] = true;
    q.enqueue(start);

    int current;
    while (q.dequeue(current)) {
        std::cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.enqueue(i);
            }
        }
    }

    delete[] visited;
}

void depth_first_search(int** graph, int n, int start) {
    bool* visited = new bool[n] { false };

    LinkedListStack<int> s;
    s.push(start);

    int current;
    while (s.pop(current)) {

        if (visited[current])
            continue;

        visited[current] = true;
        std::cout << current << " ";

        // push neighbors (reverse order for consistent output)
        for (int i = n - 1; i >= 0; i--) {
            if (graph[current][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }

    delete[] visited;
}
void print_graph(int** graph, int n) {
    std::cout << "Adjacency Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }
}
int main() {
    int n = 7;

    int** graph = new int* [n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n] {0};

    // edges (0-based index)
    graph[1][2] = graph[2][1] = 1; // 1-2
    graph[1][3] = graph[3][1] = 1; // 1-3
    graph[2][4] = graph[4][2] = 1; // 2-4
    graph[3][4] = graph[4][3] = 1; // 3-4
    graph[4][5] = graph[5][4] = 1; // 4-5
    graph[4][6] = graph[6][4] = 1; // 4-6

    print_graph(graph, n);
    std::cout << "\nBFS: ";
    breadth_first_search(graph, n, 3);
    std::cout << "\nDFS: ";
    depth_first_search(graph, n, 3);
    // cleanup
    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}