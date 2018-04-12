#define NUM_ALPHABET 26
#define MAX_MORSE_LEN 26
#define WORDS_ARR_LEN 100
#define MAX_MORSE_STR_LEN 49

int uniqueMorseRepresentations(char** words, int wordsSize) {
    int i = 0, j = 0, ascii = 0, res = 0, test = 0;
    char morse[NUM_ALPHABET][MAX_MORSE_LEN] = 
                        {".-","-...","-.-.","-..",".",
                        "..-.","--.","....","..",".---",
                        "-.-",".-..","--","-.","---",
                        ".--.","--.-",".-.","...","-",
                        "..-","...-",".--","-..-","-.--",
                        "--.."};
    char tmp[MAX_MORSE_STR_LEN] = {};
    char tra[WORDS_ARR_LEN][MAX_MORSE_STR_LEN] = {};

    for (i = 0 ; i < wordsSize ; i++) {
        for (j = 0 ; j < strlen(*(words + i)) ; j++) {
            ascii = (int)*(*(words + i) + j) - 97;
            strncat(tmp, morse[ascii], strlen(morse[ascii]));
        }
        printf("tmp: %s; ", tmp);

        for (j = 0 ; j < sizeof(tra) / MAX_MORSE_STR_LEN ; j++) {
            if (!strcmp(tra[j], "")) {
                strncpy(tra[j], tmp, strlen(tmp));
                res++;
                break;
            } else if (!strncmp(tra[j], tmp, MAX_MORSE_STR_LEN)) {
                break;
            }
        }
        
        memset(tmp, 0, strlen(tmp));
    }

    return res;
}
