
// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : Peter-s

/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i=0;
    int j=0;

    if(!strs || !strs[0]) return "";
    for(i=0;strs[0][i] != '\0'; i++) {
        for(j=1; j<strsSize;j++) {
            if(strs[j][i]  == '\0' || strs[j][i] - strs[0][i] != 0)
                goto end;
        }
    }
    // construct result
    end:
    if(i==0) return "";

    char *result = malloc(i+1);
    memcpy(result, strs[0], i);
    result[i] = '\0';
    return result;
}


#define TEST(p, s) printf("output:%s \n", longestCommonPrefix(p, s));

int main(int argc, char **argv)
{
    char *s[] = {"aba", "ababb", "abc"};
    TEST(s,3);
    return 0;
}