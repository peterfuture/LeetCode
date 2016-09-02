// Source : https://leetcode.com/problems/divide-two-integers/
// Author : Peter-s

/**********************************************************************************
*
* Divide two integers without using multiplication, division and mod operator.
*
* If it is overflow, return MAX_INT.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INT_MAX  ((int)(~0U>>1))
#define INT_MIN (-INT_MAX -1)
int divide(int A, int B) {
    
    int flags = ((A>0&&B>0) || (A<0&&B<0))?1:-1;
    int out = 0;

    // Handle Special Case
    if(B == 0) return INT_MAX;
    if(A==B) return 1;
    if(B == 1) return A;
    if(B == -1) return (A==INT_MIN)?INT_MAX:-A;
    if(B==INT_MIN) return 0;
    if(A==INT_MIN) {
        A += (flags==1)?-B:B;
        out++;
    }

    A = abs(A);
    B = abs(B);
    int shift = 0;
    while(A>=B) {
        shift = 0;
        while(A>=B<<shift) {
            shift++;
            if(B >= INT_MAX/2 || B<<shift >=INT_MAX/2)
                break;
        }
        if(shift == 0)
            break;
        shift--;
        out += (int)pow(2,shift);
        A -= B<<shift;
    }
    return (flags==1)?out:-out;
}

#define TEST(p,q) printf("input%d %d output:%d \n", p,q,divide(p,q));

int main(int argc, char **argv)
{
    TEST(1,2);
    TEST(100,2);
    TEST(-1,1);
    TEST(-2147483648,2);
    TEST(1100540749,-1090366779)
    return 0;
}
