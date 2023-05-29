#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeNextArray(const char* pattern, int patternLength, int* next) {
    int length = 0;
    next[0] = 0;
    int i = 1;

    while (i < patternLength) {
        if (pattern[i] == pattern[length]) {
            length++;
            next[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = next[length - 1];
            } else {
                next[i] = 0;
                i++;
            }
        }
    }
}

void removeSubstring(char* s, const char* t) {
    int sLength = strlen(s);
    int tLength = strlen(t);
    int* next = (int*)malloc(sizeof(int) * tLength);

    computeNextArray(t, tLength, next);

    int i = 0; // 字符串s的索引
    int j = 0; // 字符串t的索引

    while (i < sLength) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }

        if (j == tLength) {
            // 若找到匹配, 则从s中移除子串
            memmove(&s[i - j], &s[i], sLength - i + 1);
            sLength -= j;
            i = i - j;
            j = 0;
        } else if (i < sLength && s[i] != t[j]) {
            if (j != 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
    }

    free(next);
}

int main() {
    char s[] = "abcdefg";
    char t[] = "def";

    printf("  原始的字符串: %s\n", s);
    removeSubstring(s, t);
    printf("修改后的字符串: %s\n", s);

    return 0;
}
