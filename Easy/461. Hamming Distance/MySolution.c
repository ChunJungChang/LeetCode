int hammingDistance(int x, int y) {
    int tmp = 0, cnt = 0;
    
    tmp = x ^ y;
    while (tmp != 0) {
        tmp &= (tmp - 1);
        cnt++;
    }
        
    return cnt;
}
