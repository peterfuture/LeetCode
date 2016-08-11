// Source : https://leetcode.com/problems/palindrome-number/
// Author : Peter-s

/**********************************************************************************
*
* Determine whether an integer is a palindrome. Do this without extra space.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int reverse(int x) {
    int result = 0;
    while(x) {
        result = result*10 + x%10;
        x/=10;
    }
    return result;
}

bool isPalindrome(int x) {
    if(x<0) return 0;
    if(x==reverse(x))
        return 1;
    return 0;
}

#define TEST(n) printf("input:%d output:%d \n", n, isPalindrome(n));

int main(int argc, char **argv)
{
    TEST(12312321);
    return 0;
}