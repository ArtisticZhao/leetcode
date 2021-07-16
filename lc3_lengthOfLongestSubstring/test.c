#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int index = 0;
    bool char_cnt[26] = {0};
    int max = 0;
    while(true){
        if(s[index] == '\0'){
            break;
        }else{
            int temp = 0;
            int c_index = index;
            while(true){
                if((char_cnt[s[c_index]-'a']==0) && (s[c_index]!='\0')){
                    // not appear
                    char_cnt[s[c_index]-'a'] = true;
                    c_index++;
                    temp++;
                }else{
                    // dup
                    memset(char_cnt, 0, sizeof(char_cnt));
                    if(temp>max){
                        max = temp;
                    }
                    break;
                }
            }
        }
        index++;
    }
    return max;
}

int main(int argc, char *argv[])
{
    int a = lengthOfLongestSubstring("abcabcd");
    printf("%d\n", a);
    printf("%d", sizeof(bool));
    return 0;
}
