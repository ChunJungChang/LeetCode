#define ALPHABETSIZE 26

bool isAnagram(char* s, char* t) {
    int *alphabet = NULL, i = 0;
    bool ret = true;

    alphabet = (int*)calloc(ALPHABETSIZE, sizeof(int));

    for (i = 0; i < strlen(t); i++) {
        alphabet[t[i] - 'a'] += 1;
    }

    for (i = 0; i < strlen(s); i++) {
        alphabet[s[i] - 'a'] -= 1;
    }

    for (i = 0; i < ALPHABETSIZE; i++) {
        if (alphabet[i] != 0) {
            ret = false;
        }
    }

    return ret;
}
