#include <stdio.h>
#define Vertices 4

int graph[Vertices][Vertices] = {
    {0, 5, INT_MAX, 10},
    {INT_MAX, 0, 3, INT_MAX},
    {INT_MAX, INT_MAX, 0, 1},
    {INT_MAX, INT_MAX, INT_MAX, 0}
};

void floydWarshall() {
    int dist[Vertices][Vertices];
    
    for (int i = 0; i < Vertices; i++) {
        for (int j = 0; j < Vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    for (int k = 0; k < Vertices; k++) {
        for (int i = 0; i < Vertices; i++) {
            for (int j = 0; j < Vertices; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < Vertices; i++) {
        for (int j = 0; j < Vertices; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    floydWarshall();
    return 0;
}
