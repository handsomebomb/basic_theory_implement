int minOperations(char** logs, int logsSize) {
    int layer = 0;
    for(int i=0; i<logsSize; i++)
    {
        if(logs[i][0]=='.')
        {
            if((logs[i][1]=='.') && (layer>0))
                --layer;
        }
        else
            ++layer;
    }
    return layer;
}