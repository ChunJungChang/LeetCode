/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {
    int i = 0, cnt = 0, retsize = 0;
    char *tmp = NULL, *space = " ", *dot = '.', *dom = NULL;
    char *res[300];
    char **ret = &res[0];
    
    for (i = 0 ; i < cpdomainsSize ; i++) {
        tmp = strtok(cpdomains[i], space);
        if (tmp) {
            cnt = atoi(tmp);
            printf ("num: %d\n", cnt);
        }
        
        tmp = strtok (NULL, space);
        if (tmp) {
            printf ("dom: %s\n", tmp);
            
            /*
             * Compare all temporarily result,
             * each temporarily result likes "900 mail.com" or "900 com",
             * if find it then add cnt to temporarily result,
             * if not find any then use malloc
             */
            /*
            for (i = 0 ; i < retsize ; i++) {

            }
            */
        }
    }
    
    returnSize = &retsize;
    return &ret;
}
