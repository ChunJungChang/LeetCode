

bool isValid(char * s){
    char *brackets_record = NULL;
    int s_len = 0, i = 0, j = 0;
    bool ret = true;
    
    s_len = strlen(s);
    if (s_len == 0) {
        goto exit;
    }
    brackets_record = malloc(s_len * sizeof(char));
    
    for (i = 0; i < s_len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            brackets_record[j++] = s[i];
        } else {
            if (--j < 0) {
                ret = false;
                goto exit;
            }
            
            if (s[i] == ')' && brackets_record[j] != '(') {
                ret =  false;
                goto exit;
            } else if (s[i] == '}' && brackets_record[j] != '{') {
                ret =  false;
                goto exit;
            } else if (s[i] == ']' && brackets_record[j] != '[') {
                ret = false;
                goto exit;
            }
        }
    }
    
    if (j != 0) {
        ret = false;
    }
exit:
    free(brackets_record);
    return ret;
}
