#include <stdio.h>

int adj[10][10], visited[10], n;

void dfs(int start) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++) {
        if (adj[start][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    n = 5;

    // Sample graph
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    printf("DFS starting from node 0: ");
    dfs(0);
    return 0;
}
