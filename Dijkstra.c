#include<stdio.h>
#include<limits.h>

#define Nov 6

void AddEdge(int G[][Nov], int i, int j, int w) {
    G[i][j] = w;
    G[j][i] = w;
}

int minDis(int dis[], int vis[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < Nov; i++) {
        if (!vis[i] && dis[i] < min) {
            min = dis[i];
            min_index = i;
        }
    }
    return min_index;
}

void printPath(int parent[], int v) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }
    printPath(parent, parent[v]);
    printf(" -> %d", v);
}

void dijkstra(int G[][Nov], int source) {

    int dis[Nov];
    int visited[Nov] = {0};
    int parent[Nov];

    for (int i = 0; i < Nov; i++) {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }

    dis[source] = 0;

    for (int c = 0; c < Nov - 1; c++) {

        int u = minDis(dis, visited);

        if (u == -1) break;  

        visited[u] = 1;

        for (int v = 0; v < Nov; v++) {

            if (!visited[v] &&
                G[u][v] > 0 &&
                dis[u] != INT_MAX &&
                dis[u] + G[u][v] < dis[v]) {

                dis[v] = dis[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    //  print distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < Nov; i++) {
        printf("%d \t %d\n", i, dis[i]);
    }

    //   print paths
    printf("\nShortest Paths from Source %d:\n", source);
    for (int i = 0; i < Nov; i++) {
        printf("%d -> %d : ", source, i);
        if (dis[i] == INT_MAX) {
            printf("No path");
        } else {
            printPath(parent, i);
        }
        printf("\n");
    }
}

void printG(int G[][Nov]) {
    for (int i = 0; i < Nov; i++) {
        for (int j = 0; j < Nov; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int G[Nov][Nov] = {0};

    AddEdge(G, 0, 1, 1);
    AddEdge(G, 0, 2, 6);
    AddEdge(G, 1, 3, 4);
    AddEdge(G, 1, 4, 1);
    AddEdge(G, 2, 4, 1);
    AddEdge(G, 4, 5, 1);

    printG(G);

    dijkstra(G, 0);

    return 0;
}