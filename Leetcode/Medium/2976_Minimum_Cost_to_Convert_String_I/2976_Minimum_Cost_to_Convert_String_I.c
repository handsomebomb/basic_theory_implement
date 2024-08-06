#define min(a,b) ((a)<(b))?(a):(b)

long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    int adjacency[26][26];
    long long res = 0;

    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
            adjacency[i][j] = -1;

    for(int i=0; i<originalSize; i++)
    {
        if(adjacency[original[i]-'a'][changed[i]-'a']==-1)
            adjacency[original[i]-'a'][changed[i]-'a'] = cost[i];
        else
            adjacency[original[i]-'a'][changed[i]-'a'] = min(cost[i], adjacency[original[i]-'a'][changed[i]-'a']);
    }
    for(int t=0; t<26; t++)
    {
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                if(i==j)
                    adjacency[i][j] = 0;
                else if(adjacency[i][t]!=-1 && adjacency[t][j]!=-1)
                {
                    if(adjacency[i][j]==-1)
                        adjacency[i][j] = adjacency[i][t] + adjacency[t][j];
                    else
                        adjacency[i][j] = min(adjacency[i][j], (adjacency[i][t] + adjacency[t][j]));
                }
            }
        }
    }
    int size_src = 0;
    while(*(source+size_src)!='\0')
        size_src++;

    for(int i=0; i<size_src; i++)
    {
        if(adjacency[source[i]-'a'][target[i]-'a'] == -1)
            return -1;
        res += adjacency[source[i]-'a'][target[i]-'a'];
    }
    return res;
}