

char findTheDifference(char * s, char * t) {
    int xor = 0,i = 0;
    char ret = '\0';
    
    while (s[i] != '\0') {
        xor ^= s[i];
        i++;
    }
    
    i = 0;
    while (t[i] != '\0') {
        xor ^= t[i];
        i++;
    }
    
    ret = (char)xor;
    return ret;
}
