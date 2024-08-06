char* reverseParentheses(char* s) {
    int n = strlen(s);
    int* index_pairs = (int*)malloc(n * sizeof(int));
    int* stack_start_ind = (int*)malloc(n * sizeof(int));
    int stack_top = -1;

    for (int char_ind = 0; char_ind < n; ++char_ind) {
        char char_s = s[char_ind];
        if (char_s == '(') {
            stack_start_ind[++stack_top] = char_ind;
        } else if (char_s == ')') {
            int start_ind = stack_start_ind[stack_top--];
            index_pairs[char_ind] = start_ind;
            index_pairs[start_ind] = char_ind;
        }
    }

    char* res = (char*)malloc((n + 1) * sizeof(char));
    int cur_ind = 0;
    int cur_dir = 1;
    int res_len = 0;

    while (cur_ind < n) {
        char char_s = s[cur_ind];
        if (char_s == '(' || char_s == ')') {
            cur_ind = index_pairs[cur_ind];
            cur_dir *= -1;
        } else {
            res[res_len++] = s[cur_ind];
        }
        cur_ind += cur_dir;
    }

    res[res_len] = '\0';
    free(index_pairs);
    free(stack_start_ind);
    return res;
}