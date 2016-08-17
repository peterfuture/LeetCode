
// Source : https://leetcode.com/problems/roman-to-integer/
// Author : Peter-s

/**********************************************************************************
*
* Given a roman numeral, convert it to an integer.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int charToInt(char c) {
    switch (c) {
        case 'M': return 1000;
        case 'D': return 500;;
        case 'C': return 100;
        case 'L': return 50;;
        case 'X': return 10;;
        case 'V': return 5;
        case 'I': return 1;
        default:  return 0;
    }
}

int romanToInt(char* s) {

    int cur=0,next=0;
    int result = 0;

    while(s) {
        cur = charToInt(*s);
        if(cur==0)
            break;
        next = charToInt(*(s+1));
        if(next > cur) {
            result = result+next-cur;
            s+=2;
            continue;
        }
        result += cur;
        s++;
    }
    return result;
}

#define TEST(p) printf("input%s output:%d \n", p, romanToInt(p));

int main(int argc, char **argv)
{
    TEST("MCMXCVI");
    return 0;
}