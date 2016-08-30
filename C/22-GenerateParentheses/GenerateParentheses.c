
// Source : https://leetcode.com/problems/generate-parentheses/
// Author : Peter-s

/**********************************************************************************
*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*
* For example, given n = 3, a solution set is:
*
* [
*  "((()))",
*  "(()())",
*  "(())()",
*  "()(())",
*  "()()()"
* ]
* Subscribe to see which companies asked this question
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char next(char c) {
    switch(c) {
        case '(': return ')';
        //case '[': return ']';
        //case '{': return '}';
        default: return '\0';
    }
}

bool isValid(char* s) {
    
    if(*s == '\0')
        return true;
    
    int len = strlen(s);
    char result[len];
    int num = 1;
    result[0] = *s;
    s++;
    while(*s != '\0') {
        if(next(result[num-1]) == *s)
            num--;
        else
            result[num++] = *s;
        s++;
    }

    return num == 0;
}

static void recurse(char *s, int left, int right, int *num, int n, char ***result)
{
    //printf("left:%d right:%d \n", left, right);
    if(left == 0  && right == 0) {
        if(isValid(s) == 0) {
            free(s);
            return;
        }
        // construct result
        (*num)++;
        *result = (char **)realloc(*result, *num * sizeof(char *));
        s[n] = '\0';
        (*result)[*num-1] = s;
        printf("out:%s num:%d\n", s, *num);
        return;
    }

    if(left > 0 && right > 0) {
        char *s1 = malloc(n+1);
        if(s)
            memcpy(s1, s, n);
        s1[n-left-right] = '(';
        recurse(s1, left-1,right, num, n, result);

        char *s2 = malloc(n+1);
        if(s)
            memcpy(s2, s, n);
        s2[n-left-right] = ')';
        recurse(s2, left,right-1, num, n, result);
        if(s)
            free(s);
        return;
    }

    if(left > 0) {
        s[n-left-right] = '(';
        recurse(s, left-1,right, num, n, result);
        return;
    }
    if(right > 0) {
        s[n-left-right] = ')';
        recurse(s, left,right-1, num, n, result);
        return;
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char **result=NULL;
    int num=0;
    recurse(NULL, n, n, &num, 2*n, &result);
    *returnSize = num;
    int i=0;
    #if 0
    for(i=0;i<num;i++)
        printf("%s \n", result[i]);
    #endif
    return result;
}

int main(int argc, char **argv)
{
    int ret = 0;
    generateParenthesis(1,&ret);
    return 0;
}
