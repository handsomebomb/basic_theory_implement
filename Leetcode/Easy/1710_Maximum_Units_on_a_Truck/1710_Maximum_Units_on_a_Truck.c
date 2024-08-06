int partition(int** boxTypes, int left, int right)
{
    int i =left;
    for(int j=left; j<right; j++)
    {
        if(boxTypes[j][1]>boxTypes[right][1])
        {
            if(i!=j)
            {
                boxTypes[i][1] ^= boxTypes[j][1];
                boxTypes[j][1] ^= boxTypes[i][1];
                boxTypes[i][1] ^= boxTypes[j][1];
                boxTypes[i][0] ^= boxTypes[j][0];
                boxTypes[j][0] ^= boxTypes[i][0];
                boxTypes[i][0] ^= boxTypes[j][0];
            }
            i++;
        }
    }
    if(i!=right)
    {
        boxTypes[i][1] ^= boxTypes[right][1];
        boxTypes[right][1] ^= boxTypes[i][1];
        boxTypes[i][1] ^= boxTypes[right][1];
        boxTypes[i][0] ^= boxTypes[right][0];
        boxTypes[right][0] ^= boxTypes[i][0];
        boxTypes[i][0] ^= boxTypes[right][0];
    }
    return i;
}

void QuickSort(int** boxTypes, int left, int right)
{
    if(left<right)
    {
        int standard = partition(boxTypes, left, right);
        QuickSort(boxTypes, left, standard-1);
        QuickSort(boxTypes, standard+1, right);
    }
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    int retUnit = 0;
    QuickSort(boxTypes, 0, boxTypesSize-1);
    
    for(int i=0; i<boxTypesSize; i++)
    {
        if(boxTypes[i][0]>truckSize)
        {
            retUnit += (truckSize*boxTypes[i][1]);
            break;
        }
        else
        {
            retUnit += (boxTypes[i][0]*boxTypes[i][1]);
            truckSize -= boxTypes[i][0];
        }
    }
    return retUnit;
}