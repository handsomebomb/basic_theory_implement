int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    return ((edges[0][0]==edges[1][0]) || (edges[0][0]==edges[1][1]))?edges[0][0]:edges[0][1];
}