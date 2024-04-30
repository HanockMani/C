#include <stdio.h>
#define m 10

void bfs(int graph[m][m], int visited[m], int queue[m], int n, int start) {
    int front = 0, rear = -1;
    int i, current;
   
queue[++rear] = start;
    visited[start] = 1;
   
     while (front <= rear) {
        current = queue[front++];
        printf("%d ", current);
       
        for (i = 0; i <=n; ++i) {
       
            if (!visited[i] && graph[current][i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int graph[m][m], visited[m], queue[m];
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
   
    printf("BFS traversal starting from node %d: ", start);
   
    bfs(graph, visited, queue, n, start);
   
    printf("\n");
   
    return 0;
}
