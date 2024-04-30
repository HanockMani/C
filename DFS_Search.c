#include <stdio.h>
#define m 10

void dfs(int graph[m][m], int visited[m], int n, int current) {
    int i;
    printf("%d ", current);
    visited[current] = 1;

    for (i = 0; i < n+1; ++i) {
        if (!visited[i] && graph[current][i]) {
            dfs(graph, visited, n, i);
        }
    }
}

int main() {
    int graph[m][m], visited[m];
    int i, j, n, edges, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i <=n; ++i) {
        visited[i] = 0;
        for (j = 0; j <=n; ++j)
            graph[i][j] = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (from to): \n");
    for (i = 0; i < edges; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);

        graph[from][to] = graph[to][from] = 1;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal starting from node %d: ", start);

    dfs(graph, visited, n, start);

    printf("\n");

    return 0;
}
