// Source : https://leetcode.com/problems/regular-expression-matching/
// Author : Peter-s

/**********************************************************************************
*
* Implement regular expression matching with support for '.' and '*'.
*
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
*
*The matching should cover the entire input string (not partial).
*
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
*
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool isMatch(char* s, char* p) {

    int m = strlen(s);
    int n = strlen(p);
    int i=0,j=0;

    if(*s!='\0' && *p=='\0')
        return 0;
    if(*s == '\0') {
        if(*p == '\0')
            return 1;
        else if(*(p+1) == '*')
            return isMatch(s, p+2);
        else
            return 0;
    } else {
        if(*s == *p || *p == '.') {
            if(*(p+1) == '*'){
                if(isMatch(s+1, p) == 0)
                    return isMatch(s, p+2);
                else
                    return 1;
            }
            else
                return isMatch(s+1, p+1);
        } else {
            if(*(p+1) == '*')
                return isMatch(s, p+2);
            else
                return 0;
        }
    }
}

#define TEST(s,p) printf("input[s:%s p:%s] output:%d \n", s, p, isMatch(s,p));

int main(int argc, char **argv)
{
    TEST("abc", "c*a*b*c");
    TEST("abcd", "d*");
    
    TEST("ab", ".*");
    TEST("ab", ".*c");
    return 0;
}