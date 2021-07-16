#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
    int cnt[26];
    memset(cnt, -1, sizeof(int) * 26);
    char c;
    int index = 0;

    c = s[index];
    cnt[c - 'a'] = index;
    index++;
    c = s[index];
    while (c != '\0') {
        if (cnt[c - 'a'] == -1) {   // empty
            cnt[c - 'a'] = index;
        }
        else {
            cnt[c - 'a'] = -2;  // dup
        }
        index++;
        c = s[index];
    }
    int res = index;
    int flags = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > -1) {
            flags = 1;
            if (res > cnt[i]) {
                res = cnt[i];
            }
        }
    }
    if (flags) return res;
    else return -1;
}

int main() {
    char s[] = "leetcode";
    printf("%d", firstUniqChar(s));
}