#include <stdio.h>
#include <stdbool.h>
#define Vertices 7

int graph[Vertices][Vertices] = {
    {0, 1, 4, 0, 0, 0, 0},
    {1, 0, 2, 0, 0, 0, 0},
    {4, 2, 0, 5, 0, 0, 0},
    {0, 0, 5, 0, 3, 0, 0},
    {0, 0, 0, 3, 0, 6, 0},
    {0, 0, 0, 0, 6, 0, 7},
    {0, 0, 0, 0, 0, 7, 0}
};

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < Vertices; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    int dist[Vertices];
    bool sptSet[Vertices];
    
    for (int i = 0; i < Vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < Vertices - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < Vertices; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < Vertices; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    dijkstra(0);
    return 0;
}
