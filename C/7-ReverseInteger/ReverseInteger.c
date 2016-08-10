// Source : https://leetcode.com/problems/reverse-integer/
// Author : Peter-s

/**********************************************************************************
*
* Reverse digits of an integer.
* Example1: x = 123, return 321
* Example2: x = -123, return -321
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INT_MAX        ((int)(~0U>>1))
int reverse(int x) {

    int flag = (x>0)?1:-1;
    int value=abs(x);
    int64_t result = 0;
    while(value>0) {
        result = result*10 + value%10;
        value /= 10;
    }
    if(result > INT_MAX)
        result = 0;
    //printf("after reverse:%lld \n", result*flag);
    return (int)result*flag;
}

int main(int argc, char const *argv[])
{
    int value = 1534236469;
    int result = reverse(value);
    printf("result:%d \n", result);
    return 0;
}