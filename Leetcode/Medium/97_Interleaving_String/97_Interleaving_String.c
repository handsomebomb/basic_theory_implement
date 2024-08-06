bool isInterleave(char * s1, char * s2, char * s3){
    int len1, len2, len3;
    for(len1 = 0; *(s1+len1)!='\0'; len1++){}
    for(len2 = 0; *(s2+len2)!='\0'; len2++){}
    for(len3 = 0; *(s3+len3)!='\0'; len3++){}

    if((len1+len2)!=len3) return false;
    
    bool table[len2+1];
    for(int row = 0; row<=len1; row++)
    {
        for(int col = 0; col<=len2; col++)
        {
            if((row==0) && (col==0))
                table[col] = true;
            else if(row==0)
                table[col] = table[col-1] && (*(s2+col-1)==*(s3+row+col-1));
            else if(col==0)
                table[col] = table[col] && (*(s1+row-1)==*(s3+row+col-1));
            else
                table[col] = (table[col-1] && (*(s2+col-1)==*(s3+row+col-1))) || (table[col] && (*(s1+row-1)==*(s3+row+col-1)));
        }
    }
    return table[len2];
}
/*
bool isInterleave(char * s1, char * s2, char * s3){
    int len1, len2, len3;
    for(len1 = 0; *(s1+len1)!='\0'; len1++){}
    for(len2 = 0; *(s2+len2)!='\0'; len2++){}
    for(len3 = 0; *(s3+len3)!='\0'; len3++){}

    if((len1+len2)!=len3) return false;
    
    bool table[len1+1][len2+1];
    for(int row = 0; row<=len1; row++)
    {
        for(int col = 0; col<=len2; col++)
        {
            if((row==0) && (col==0))
                table[row][col] = true;
            else if(row==0)
                table[row][col] = table[row][col-1] && (*(s2+col-1)==*(s3+row+col-1));
            else if(col==0)
                table[row][col] = table[row-1][col] && (*(s1+row-1)==*(s3+row+col-1));
            else
                table[row][col] = (table[row][col-1] && (*(s2+col-1)==*(s3+row+col-1))) || (table[row-1][col] && (*(s1+row-1)==*(s3+row+col-1)));
        }
    }
    return table[len1][len2];
}*/