int maxFrequencyElements(int* nums, int numsSize) {
    int freqs[100] = {0};
    int max_freqs = 0;
    int total_freq = 0;
    for(int i=0; i<numsSize; i++)
    {
        freqs[nums[i]-1]++;
        if(freqs[nums[i]-1]>max_freqs)
        {
            max_freqs = freqs[nums[i]-1];
            total_freq = max_freqs;
        }
        else if(freqs[nums[i]-1]==max_freqs)
            total_freq += max_freqs;
    }
    return total_freq;
}