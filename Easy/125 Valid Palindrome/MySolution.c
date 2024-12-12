bool isPalindrome(char* s) {
    char *t = NULL;
    int i = 0, j = 0;
    bool ret = true;

    t = (char*)calloc(strlen(s) + 1, sizeof(char));

    for (i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            t[j] = s[i];
            j++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            t[j] = s[i] + 32;
            j++;
        } else if (s[i] >= '0' && s[i] <= '9') {
            t[j] = s[i];
            j++;   
        }
    }
    
    j = strlen(t);
    if (j <= 1) {
        return ret;
    } else {
        j -= 1;
    }
    
    for (i = 0; i <= j / 2; i++) {
        if (t[i] != t[j - i]) {
            ret = false;
        }
    }

    return ret;
}
