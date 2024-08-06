#define INF INT_MAX

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    // Step 1: Initialize the distance matrix
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    // Step 2: Fill initial distances from edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        dist[u][v] = weight;
        dist[v][u] = weight;
    }
    // Step 3: Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Step 4: Count reachable cities for each city
    int min_count = INF;
    int result_city = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }
        // Step 5: Determine the city with the smallest number of neighbors
        if (count <= min_count) {
            min_count = count;
            result_city = i;
        }
    }
    return result_city;
}