/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int num, int* returnSize) {
    int leds = num, hourleds = 0, minleds = 0, hidxmax = 5, midxmax = 20, i = 0, j = 0;
    char tmp[6] = {0};
    char *hour[4][5] = {{"0"},
                        {"1", "2", "4", "8"},
                        {"3", "5", "6", "9", "10"},
                        {"7", "11"}};
    char *min[6][20] = {{"00"},
                        {"01", "02", "04", "08", "16", "32"},
                        {"03", "05", "06", "09", "10", "12", "17", "18",
                         "20", "24", "33", "34", "36", "40", "48"},
                        {"07", "11", "13", "14", "19", "21", "22", "25",
                         "26", "28", "35", "37", "38", "41", "42", "44",
                         "49", "50", "52", "56"},
                        {"15", "23", "27", "29", "30", "39", "43", "45",
                         "46", "51", "53", "54", "57", "58"},
                        {"31", "47", "55", "59"}};
    int arrSize = 0;
    char *res[24 * 60];
    char **ret = &res[0];

    for (hourleds = 0 ; (hourleds <= leds && hourleds <= 4) ; hourleds++) {
        minleds = leds - hourleds;
        if (hourleds >= 4 || minleds >= 6) {
            continue;
        }
        for (i = 0 ; i < hidxmax ; i++) {
            for (j = 0 ; j < midxmax ; j++) {
                if (hour[hourleds][i] != NULL && min[minleds][j] != NULL) {
                    strcat(tmp, hour[hourleds][i]);
                    strcat(tmp, ":");
                    strcat(tmp, min[minleds][j]);
                    res[arrSize] = malloc(sizeof(tmp));
                    strcpy(res[arrSize], tmp);
                    arrSize++;
                    tmp[0] = '\0';
                }
            }
        }
    }
    
    *returnSize = arrSize;
    return ret;
}
