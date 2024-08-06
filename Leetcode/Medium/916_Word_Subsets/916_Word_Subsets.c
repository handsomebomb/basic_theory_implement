/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** wordSubsets(char ** words1, int words1Size, char ** words2, int words2Size, int* returnSize){
    int alpha_word2[26] = {0};
    for(int i=0; i<words2Size; i++){
        char* word2 = words2[i];
        int j = 0;
        int tmp[26] = {0};
        while(word2[j]!='\0'){
            tmp[(word2[j++]-'a')]++;
        }
        for(int k=0; k<26; k++){
            if(tmp[k]>alpha_word2[k]) alpha_word2[k] = tmp[k];
        }
    }
    char** res = (char**)calloc(words1Size, sizeof(char*));
    int cnt = 0;
    for(int i=0; i<words1Size; i++){
        char* word1 = words1[i];
        int alpha_word1[26] = {0};
        int j = 0;
        while(word1[j]!='\0'){
            alpha_word1[(word1[j++]-'a')]++;
        }
        for(int k=0; k<26; k++){
            if(alpha_word1[k]<alpha_word2[k]) break;
            if(k==25) res[cnt++] = word1;
        }
    }
    *returnSize = cnt;
    return res;
}