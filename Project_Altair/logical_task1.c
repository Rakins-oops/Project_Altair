#include <stdbool.h>
#include <stdio.h>

#define Vertices 7
#define EdgesCount 7

bool graph[Vertices][Vertices];

void initializeGraph() {
    for (int i = 0; i < Vertices; i++) {
        for (int j = 0; j < Vertices; j++) {
            graph[i][j] = false;
        }
    }
}

void addEdge(int src, int dest) {
    graph[src][dest] = true;
    graph[dest][src] = true;
}

bool isPathExist(int v, bool visited[], int count) {
    if (count == Vertices) {
        return true;
    }

    visited[v] = true;

    for (int i = 0; i < Vertices; i++) {
        if (graph[v][i] && !visited[i]) {
            if (isPathExist(i, visited, count + 1)) {
                return true;
            }
        }
    }

    visited[v] = false;
    return false;
}

bool hasValidPath() {
    for (int i = 0; i < Vertices; i++) {
        bool visited[Vertices] = { false };
        if (isPathExist(i, visited, 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    initializeGraph();
    int edges[EdgesCount][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 6}, {6, 3}};

    for (int i = 0; i < EdgesCount; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        addEdge(src, dest);
    }

    bool result = hasValidPath();
    printf("Output: %s\n", result ? "true" : "false");

    return 0;
}