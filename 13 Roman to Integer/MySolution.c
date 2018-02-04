int romanToInt(char* s) {
    int i, pre = 0, tmp = 0, result = 0;
        
    for (i = 0;i < strlen(s);i++) {
        switch(s[i])
        {
            case 'I': //1
                tmp = 1;
                break;
            case 'V': //5;
                tmp = 5;
                break;
            case 'X': //10
                tmp = 10;
                break;
            case 'L': //50
                tmp = 50;
                break;
            case 'C': //100
                tmp = 100;
                break;
            case 'D': //500
                tmp = 500;
                break;
            case 'M': //1000
                tmp = 1000;
                break;
            default:
                break;
        }
        if (pre != 0 && pre < tmp)
            result = result - pre + tmp - pre;
        else
            result += tmp;
        pre = tmp;
    }
    return result;
}
