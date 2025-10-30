char* reverseString(char* s) {
    int i = 0, j = strlen(s) - 1, s_len = strlen(s);
    char tmp, *ret = NULL;
    
    if (!s) {
        return ret;
    }
    
    ret = (char *)malloc(sizeof(char) * (s_len + 1));
    strncpy(ret, s, s_len);

    for (i = 0 ; i < s_len ; i++, j--) {
        if (i < j) {
            tmp = ret[i];
            //printf("tmp: %c, ", tmp);
            ret[i] = ret[j];
            //printf("ret[i]: %c, ", ret[i]);
            ret[j] = tmp;
            //printf("ret[j]: %c\n", ret[j]);
        }
    }
    ret[s_len] = '\0';
    
    return ret;
}
