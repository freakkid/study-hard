void get_next(string T, int *next) {
    int i = 1, j = 0;　// i是当前next下标, j是字符串前缀的下标，匹配到哪个字符了
    next[1] = 0;
    // T[0] = len(T) - 1;
    while (i < T[0]) {
        // j == 0什么也没有匹配到；
        // T[i] == T[j],当前的字符和前缀某字符匹配
        if (j == 0) {
            ++i; // 向右移动一位
            ++j;
            next[i] = j; // 匹配到那个字符串的下标j
        }
        // j !=  0，T[i] ！= T[j],当前的字符和前缀某字符不匹配
        // 所以j要回退
        else
            j = next[j];
    }
}

