int minimumDeletions(char* s) {
    int del = 0, b_cnt = 0;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]=='b')
            b_cnt++;
        else if(b_cnt)
        {
            del++;
            b_cnt--;
        }
    }
    return del;
}