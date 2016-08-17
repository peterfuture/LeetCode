
// Source : https://leetcode.com/problems/integer-to-roman/
// Author : Peter-s

/**********************************************************************************
*
* Given an integer, convert it to a roman numeral.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char numToChar(int step) {
    switch (step) {
        case 1000:  return 'M';
        case 500:   return 'D';
        case 100:   return 'C';
        case 50:    return 'L';
        case 10:    return 'X';
        case 5:     return 'V';
        case 1:     return 'I';
        default:    return 'I';
    }
}

char* intToRoman(int num) {

    char *result = malloc(100);
    int step=1000;
    int count=0;
    char *cur = result;
    while(step>0){
        count = num/step;
        if(count == 9) {
            sprintf(cur++, "%c",numToChar(step));
            sprintf(cur++, "%c",numToChar(step*10));
            count -= 9;
        }
        if(count >=5) {
            sprintf(cur++, "%c",numToChar(step*5));
            count -= 5;
        }
        if(count == 4) {
            sprintf(cur++, "%c",numToChar(step));
            sprintf(cur++, "%c",numToChar(step*5));
            count -= 4;
        }
        while(count > 0) {
            sprintf(cur++, "%c",numToChar(step));
            count--;
        }

        num %= step;
        step /=10;
    }
    sprintf(cur, "%c",'\0');
    return result;
}


#define TEST(p) printf("input%d output:%s \n", p, intToRoman(p));

int main(int argc, char **argv)
{
    TEST(3999);
    return 0;
}