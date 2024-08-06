void reverseString(char* s, int sSize){
    for(int i=0; i*2<sSize-1; i++){
        s[i] = s[sSize-i-1]+s[i];
        s[sSize-i-1] = s[i]-s[sSize-i-1];
        s[i] = s[i]-s[sSize-i-1];
    }
}