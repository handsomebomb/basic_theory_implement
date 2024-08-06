bool isAnagram(char * s, char * t){
    int idx = 0;
    int base = 'a';
    int count[26] = {0};
    while(s[idx]!='\0' && t[idx]!='\0'){
        ++count[s[idx]-base];
        --count[t[idx++]-base];
    }
    if((s[idx]!='\0')^(t[idx]!='\0')) return false;
    for(int i=0; i<26; i++) {
        if(count[i]!=0) return false;
    }
    return true;
}