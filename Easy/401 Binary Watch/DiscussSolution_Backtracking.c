/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int led_hour[] = {1, 2, 4, 8};
int led_hour_size;
int led_min[] = {1, 2, 4, 8, 16, 32};
int led_min_size;
int led_size;
int size;
char** ret;

void insert(int hour, int min) {
    char* tmp = malloc(sizeof(char) * 6);
    if (min < 10) {
        sprintf(tmp, "%d:0%d", hour, min);
    } else {
        sprintf(tmp, "%d:%d", hour, min);
    }
    ret[size++] = tmp;
}

void backtracking(int num, int hour, int min, int idx, int count) {
    if (count == num) {
        insert(hour, min);
        return;
    }
    for (int i = idx ; i < led_size ; i++) {
        if (i < led_hour_size) {
            if (hour + led_hour[i] > 11) {
                continue;
            } else {
                hour += led_hour[i];
            }
        } else {
            if (min + led_min[i - led_hour_size] > 59) {
                continue;
            } else {
                min += led_min[i - led_hour_size];
            }
        }
        backtracking(num, hour, min, i + 1, count + 1);
        if (i < led_hour_size) {
            hour -= led_hour[i];
        } else {
            min -= led_min[i - led_hour_size];
        }
    }
}

char** readBinaryWatch(int num, int* returnSize) {
    led_hour_size = sizeof(led_hour) / sizeof(led_hour[0]);
    led_min_size = sizeof(led_min) / sizeof(led_min[0]);
    led_size = led_hour_size + led_min_size;
    size = 0;
    ret = malloc(sizeof(char *) * pow(2, 10));
    backtracking(num, 0, 0, 0, 0);
    *returnSize = size;
    return ret;
}
