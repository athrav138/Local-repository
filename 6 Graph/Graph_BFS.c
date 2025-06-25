#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int adj[SIZE][SIZE], visited[SIZE], queue[SIZE];
int front = 0, rear = -1;

void bfs(int start, int n) {
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n = 5;

    // Sample graph
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    printf("BFS starting from node 0: ");
    bfs(0, n);
    return 0;
}
