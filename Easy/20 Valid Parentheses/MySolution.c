

bool isValid(char * s){
    char brackets_record[10000] = {0};
    int len = 0, i = 0, j = 0;
    
    len = strlen(s);
    
    for (i = 0; i < len; i++) {
        if (s[i] == '(' ||
            s[i] == '{' ||
            s[i] == '[') {
            brackets_record[j++] = s[i];
        } else if (s[i] == ')') {
            if (--j < 0 || brackets_record[j] != '(') {
                return false;
            }
        } else if (s[i] == '}') {
            if (--j < 0 || brackets_record[j] != '{') {
                return false;
            }
        } else if (s[i] == ']') {
            if (--j < 0 || brackets_record[j] != '[') {
                return false;
            }
        }
    }
    
    if (j != 0) {
        return false;
    }
    
    return true;
}
