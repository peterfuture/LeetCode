
// Source : https://leetcode.com/problems/valid-parentheses/
// Author : Peter-s

/**********************************************************************************
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*
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
        case '[': return ']';
        case '{': return '}';
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

#define TEST(p) printf("input%s output:%d \n", p, isValid(p));

int main(int argc, char **argv)
{
    TEST("(){}");
    TEST("([])");
    return 0;
}