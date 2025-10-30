/**
 * To call strlen function in each loop waste too much time.
 * You should declaration a variable to store length of moves, it just calls strlen function once.
 */

bool judgeCircle(char* moves) {
    int len = strlen(moves), i = 0, x = 0, y = 0;
    
    for (i = 0 ; i < len ; i++) {
        if (moves[i] == 'R') {
            x++;
        } else if (moves[i] == 'L') {
            x--;
        } else if (moves[i] == 'U') {
            y++;
        } else if (moves[i] == 'D') {
            y--;
        }
    }

    return x == 0 && y == 0;
}
