typedef struct _table
{
    int cnt;
    int idx[50000];
}table;

int numMatchingSubseq(char * s, char ** words, int wordsSize){
    // 'a' = 97
    table appear[26] = {-1};
    for(int alpha = 0; alpha<26; alpha++)
    {
        appear[alpha].cnt = 0;
    }
    int i=0;
    while(*(s+i)!='\0')
    {
        appear[*(s+i)-97].idx[(appear[*(s+i)-97].cnt)] = i;
        ++(appear[*(s+i)-97].cnt);
        i++;
    }
    //printf("%d %d\n", appear[4].cnt, appear[4].idx[0]);
    //printf("%d %d\n", appear[4].cnt, appear[4].idx[1]);
    int res = 0;
    for(int w=0; w<wordsSize; w++)
    {
        char* word = words[w];
        int last = -1;
        int i = 0;
        int j = 0;
        bool flag = 0;
        while(*(word+i)!='\0')
        {
            flag = 1;
            for(j=0; j<appear[*(word+i)-97].cnt; j++)
            {
                if(appear[*(word+i)-97].idx[j]>last)
                {
                    last = appear[*(word+i)-97].idx[j];
                    i++;
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }
        if(*(word+i)=='\0') res++;
    }
    
    return res;
}