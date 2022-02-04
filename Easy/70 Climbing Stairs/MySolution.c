

int climbStairs(int n){
    int stepArr[46] = {0}, ret = 0, i = 0;
    
    stepArr[0] = 0;
    stepArr[1] = 1;
    stepArr[2] = 2;
    
    for (i = 3; i <= n; i++) {
        stepArr[i] = stepArr[i-1] + stepArr[i-2];
    }
    
    ret = stepArr[n];
    return ret;
}
