void update(int* tree, int index, int value, int length) {
    index++;
    while (index < length) {
        tree[index] += value;
        index += index & (-index);
    }
}

int query(int* tree, int index) {
    int sum = 0;
    index++;
    while (index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

int numTeams(int* rating, int ratingSize) {
    if (ratingSize < 3) return 0;

    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < ratingSize; i++) {
        if (rating[i] < min) min = rating[i];
        if (rating[i] > max) max = rating[i];
    }

    int length = max - min + 2;
    int* leftTree = (int*)calloc(length, sizeof(int));
    int* rightTree = (int*)calloc(length, sizeof(int));

    for (int i = 0; i < ratingSize; i++) {
        update(rightTree, rating[i] - min, 1, length);
    }

    int count = 0;
    for (int i = 0; i < ratingSize; i++) {
        update(rightTree, rating[i] - min, -1, length);

        int lessLeft = query(leftTree, rating[i] - min - 1);
        int greaterLeft = i - lessLeft;

        int lessRight = query(rightTree, rating[i] - min - 1);
        int greaterRight = (ratingSize - i - 1) - lessRight;

        count += lessLeft * greaterRight + greaterLeft * lessRight;

        update(leftTree, rating[i] - min, 1, length);
    }

    free(leftTree);
    free(rightTree);

    return count;
}