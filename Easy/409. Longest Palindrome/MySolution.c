int longestPalindrome(char* s) {
    int s_len = strlen(s) + 1;
    int i = 0, palin_len = 0;
    char s_tmp[s_len];
    int lower_alphabet[26] = {0}, upper_alphabet[26] = {0};
    int max_odd = 0;
    
    snprintf(s_tmp, s_len, "%s", s);
    for (i = 0 ; i < s_len ; i++) {
        if (s_tmp[i] >= 'A' && s_tmp[i] <= 'Z') {
            upper_alphabet[s_tmp[i] - 'A']++;
        } else if (s_tmp[i] >= 'a' && s_tmp[i] <= 'z') {
            lower_alphabet[s_tmp[i] - 'a']++;
        }
    }

    for (i = 0 ; i < 26 ; i++) {
        if (upper_alphabet[i] % 2 == 0) {
            palin_len += upper_alphabet[i];
        } else if (upper_alphabet[i] % 2 == 1 && upper_alphabet[i] >= max_odd) {
            max_odd = upper_alphabet[i];
        }
    }
    for (i = 0 ; i < 26 ; i++) {
        if (lower_alphabet[i] % 2 == 0) {
            palin_len += lower_alphabet[i];
        } else if (lower_alphabet[i] % 2 == 1 && lower_alphabet[i] >= max_odd) {
            max_odd = lower_alphabet[i];
        }
    }
    
    if (max_odd == 1) {
        palin_len += 1;
    } else if (max_odd > 1) {
        for (i = 0 ; i < 26 ; i++) {
            if (upper_alphabet[i] % 2 == 1) {
                palin_len = palin_len + upper_alphabet[i] - 1;
            }
            if (lower_alphabet[i] % 2 == 1) {
                palin_len = palin_len + lower_alphabet[i] - 1;
            }
        }
        palin_len = palin_len - (max_odd - 1) + max_odd;
    }
    
    return palin_len;
}
