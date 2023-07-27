#include <stdio.h>
#include <stdbool.h>
#define Vertices 7
#define EdgesCount 7

struct Edge {
    int src, dest, weight;
};

struct Edge edges[EdgesCount] = {
    {0, 1, 1},
    {1, 2, 2},
    {2, 0, 4},
    {3, 4, 5},
    {4, 5, 3},
    {5, 6, 6},
    {6, 3, 7}
};

void bellmanFord(int src) {
    int dist[Vertices];
    
    for (int i = 0; i < Vertices; i++) {
        dist[i] = INT_MAX;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < Vertices - 1; count++) {
        for (int i = 0; i < EdgesCount; i++) {
            int u = edges[i].src;
            int v = edges[i].dest;
            int weight = edges[i].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < Vertices; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    bellmanFord(0);
    return 0;
}