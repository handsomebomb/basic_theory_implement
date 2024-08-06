/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_STRLEN 20
void chkPattern(char* str, int* res){
    int len = strlen(str);
    int hash = 1;
    for(int i=0; i<len; i++){
        if(res[i]==0) res[i] = hash;
        else continue;
        for(int j=i+1; j<len; j++){
            if(str[i]==str[j]){
                res[j] = hash;
            }
        }
        ++hash;
    }
}
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    int len = strlen(pattern);
    int pat_hash[MAX_STRLEN] = {0};
    chkPattern(pattern, &pat_hash);
    char** res = (char**)calloc(wordsSize, sizeof(char*));
    int cnt = 0;
    for(int w=0; w<wordsSize; w++){
        char* word = words[w];
        int word_hash[MAX_STRLEN] = {0};
        chkPattern(word, &word_hash);
        for(int i=0; i<len; i++){
            if(pat_hash[i]!=word_hash[i]) break;
            if(i==(len-1)) res[cnt++] = word;
        }
    }
    *returnSize = cnt;
    return res;
}