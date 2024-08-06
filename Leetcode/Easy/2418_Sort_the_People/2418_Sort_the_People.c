/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void min_heapify(char **res, int *heights, int root, int size)
{
    int smallest = root;
    int left  = (root<<1)+1;
    int right = (root<<1)+2;

    if(left<size && heights[left]<heights[smallest])
        smallest = left;
    if(right<size && heights[right]<heights[smallest])
        smallest = right;
    if(smallest != root)
    {
        char *tmp = res[root];
        res[root] = res[smallest];
        res[smallest] = tmp;
        int tmp_h = heights[root];
        heights[root] = heights[smallest];
        heights[smallest] = tmp_h;

        min_heapify(res, heights, smallest, size);
    }
}

void heap_sort(char **res, int *heights, int size)
{
    for(int i=((size>>1)-1); i>=0; i--)
        min_heapify(res, heights, i, size);
    for(int i=size-1; i>0; i--)
    {
        char *tmp = res[0];
        res[0] = res[i];
        res[i] = tmp;
        int tmp_h = heights[0];
        heights[0] = heights[i];
        heights[i] = heights[0];

        min_heapify(res, heights, 0, i);
    }
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    //char **res = (char **)malloc(sizeof(char *)*heightsSize);
    heap_sort(names, heights, heightsSize);
    *returnSize = heightsSize;
    return names;
}