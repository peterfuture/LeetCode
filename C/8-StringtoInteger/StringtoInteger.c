// Source : https://leetcode.com/problems/reverse-integer/
// Author : Peter-s

/**********************************************************************************
*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
*
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)

int myAtoi(char* s) {

    if(!s) return 0;
    int i=0;
    int ret = 0;

    for(;isspace(*s);s++);
    int flag = 1;
    if (*s=='-' || *s=='+') {
        flag = (*s=='-')?-1:1;
        s++;
    }

    for(;isdigit(*s);s++){
        int digit = *s - '0';
        if(flag > 0 && ret > (INT_MAX-digit)/10)
            return INT_MAX;
        else if(flag < 0 && -ret < (INT_MIN+digit)/10)
            return INT_MIN;
        ret = ret*10+digit;
    }

    return ret*flag;
}

#define TEST(s) printf("input:%s output:%d \n", s, myAtoi(s));

int main(int argc, char **argv)
{
    TEST("");
    TEST("   -04f");
    TEST("2147483648");
    TEST("-2147483649");
    TEST("-1");
    TEST(" b11228552307");
    TEST("     010");
    TEST("9223372036854775809");
    TEST("      -11919730356x");
    TEST("    -00134");
    return 0;
}