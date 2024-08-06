bool checker(int* matchsticks, int matchsticksSize, int stick_idx, int* sides){
    if(stick_idx==matchsticksSize)
    {
        if(sides[0] | sides[1] | sides[2] | sides[3]) return false;
        else return true;
    }
    
    for(int i=0; i<4; i++)
    {
        if(matchsticks[stick_idx]>sides[i]) continue;
        sides[i] -= matchsticks[stick_idx];
        if(checker(matchsticks, matchsticksSize, stick_idx+1, sides)) return true; 
        sides[i] += matchsticks[stick_idx];
    }
    return false;
}

bool makesquare(int* matchsticks, int matchsticksSize){
    if(matchsticksSize<4) return false;
    int sum = 0;
    for(int i=0; i<matchsticksSize; i++){ sum+=matchsticks[i]; }
    if(sum%4) return false;
    
    int side = sum/4;
    int sides[4] = {side, side, side, side};
    
    return checker(matchsticks, matchsticksSize, 0, sides);
}