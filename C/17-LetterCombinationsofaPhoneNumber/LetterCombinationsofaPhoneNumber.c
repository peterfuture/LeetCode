
// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Peter-s

/**********************************************************************************
*
* Given a digit string, return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void recurse_process(char *s, char *digits, char ***result, int *num)
{
    static int Len[10] = {1,1,3,3,3,3,3,4,3,4};
    static char *String[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(*digits == '\0') {
        (*num)++;
        *result = realloc(*result, (size_t)(*num * sizeof(long)));
        (*result)[*num-1] = s;
        return;
    }

    int i=0;
    int index=*digits - '0';
    int slen = (!s)?0:strlen(s);
    for(i=0;i<Len[index];i++) {
        char *tmp = malloc(slen+2);
        memcpy(tmp, s, slen);
        tmp[slen] = String[index][i];
        tmp[slen+1] = '\0';
        recurse_process(tmp, digits+1, result, num);
    }
    if(s)
        free(s);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char **result = NULL;
    *returnSize=0;
    if(!digits || strlen(digits)==0) return NULL;
    int num = 0;
    recurse_process(NULL, digits, &result, &num);
    
#if 0
    printf("num:%d \n", num);
    int i=0;
    for(i=0;i<num;i++)
        printf("out:%s \n", result[i]);
#endif

    *returnSize = num;
    return result;
}

#define TEST(p,q) printf("input%s output:%p \n", p, letterCombinations(p,q));

int main(int argc, char **argv)
{
    int ret=0;
    TEST("2", &ret);
    TEST("22", &ret);
    //TEST("333", &ret);
    return 0;
}