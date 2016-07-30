// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Peter-s

/**********************************************************************************
*
* Given a string, find the length of the longest substring without repeating characters.
* Examples:
* Given "abcabcbb", the answer is "abc", which the length is 3.
* Given "bbbbb", the answer is "b", with the length of 1.
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_ARRAY_LEN 127
int lengthOfLongestSubstring(char* s) {
   
    int len = strlen(s);
    int repeat[CHAR_ARRAY_LEN];
    int longest = 0;
    int max_len = 0;
    int max_pos = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int next;
    if(len <= 1)
        return len;
    memset(repeat, 0, CHAR_ARRAY_LEN * sizeof(int));

    for(; i < len;) {
        // skip if no longer than former
        if(i+longest > len)
            break;
        repeat[s[i]] = i + 1;
        longest = 1;
        j = i+1;
repeat:
        for(; j < len; j++) {
            if(repeat[s[j]] == 0) {
                longest++;
                repeat[s[j]] = j + 1;
            } else {
                break;
            }
        }
        
        if(max_len < longest) {
            max_len = longest;
            max_pos = i;
        }

        if(j >= len)
            break;
        
        // clear middle statu
        next = repeat[s[j]];
        for(k = i; k < next; k++)
            repeat[s[k]] = 0;
        // update i
        i = next;
        longest = j-i;
        goto repeat;
    }
    printf("maxlen:%d maxpos:%d sub:%s \n", max_len, max_pos, &s[max_pos]);
    return max_len;
}

int main(int argc, char const *argv[])
{
    char *s = "pwwkew";
    //char *s = "abcabcbb";
    //char *s = "au";
    printf("parse string:%s \n", s);
    lengthOfLongestSubstring(s);
    return 0;
}
