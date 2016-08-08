// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Peter-s

/**********************************************************************************
*
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findPalindrome(char *s, int left, int right) {
    int count = 0;
    int n = strlen(s);
    while (left>=0 && right<=n-1 && s[left] == s[right]) {
        left--;
        right++;
    }
    //printf("left:%d right:%d n:%d\n", left, right, n);
    return right-left-1;
}

char* longestPalindrome(char* s) {
    
    if(!s) return NULL;
    if(strlen(s)==1) return s;
    
    int n = strlen(s);
    int maxlen=0;
    char *maxpos=s;
    int len=0;
    int i = 0;
    for (i=0; i<n-1; i++) {
        //if(n-i < maxlen)
        //    break;
        len = findPalindrome(s, i, i);
        if (len > maxlen){
            maxlen = len;
            maxpos = s+i-len/2;
            //printf("found one. i:%d len:%d \n", i, len);
        }
        len = findPalindrome(s, i, i+1);
        if (len > maxlen){
            maxlen = len;
            if(len<=2) maxpos = s+i;
            else maxpos = s+i-len/2+1;
            //printf("found one. i:%d len:%d \n", i, len);
        } 
    }

    char *result = malloc(maxlen + 1);
    memcpy(result, maxpos, maxlen);
    result[maxlen] = '\0';
    printf("Found pos:%d len:%d string:%s\n", (int)(maxpos-s), maxlen, result);
    return result;
}
int main(int argc, char const *argv[])
{
    char *string = "dddddddd";
    char *result = longestPalindrome(string);
    printf("result:%s \n", result);
    return 0;
}