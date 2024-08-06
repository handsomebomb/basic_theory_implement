int firstUniqChar(char * s){
    int amount[52] = {0};
    int res;
    for(int i=0; *(s+i); ++i) {
        if (!amount[*(s+i)%26]) {
            amount[*(s+i)%26+26] = i; 
            res = i;
        }
        ++amount[*(s+i)%26];
    }
    for(int j=0; j<26; ++j) {
        if (amount[j]==1 && amount[j+26]<res) res = amount[j+26];
    }
    if (amount[*(s+res)%26]==1) return res;
    else return -1;
}