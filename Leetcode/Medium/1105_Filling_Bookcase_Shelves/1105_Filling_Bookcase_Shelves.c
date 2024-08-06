int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth) {
    int* dp = (int*)malloc((booksSize + 1) * sizeof(int));
    dp[0] = 0;

    for (int i = 1; i <= booksSize; i++) {
        int min = dp[i - 1] + books[i - 1][1];
        int height = books[i - 1][1];
        int width = books[i - 1][0];
        int j = i - 2;
        while (j >= 0 && width + books[j][0] <= shelfWidth) {
            width += books[j][0];
            height = (height > books[j][1]) ? height : books[j][1];
            min = (min < height + dp[j]) ? min : height + dp[j];
            --j;
        }
        dp[i] = min;
    }

    int result = dp[booksSize];
    free(dp);
    return result;
}