// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Peter-s

/**********************************************************************************
*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int rows) {

    int n = strlen(s);
    if(rows <= 1 || rows >= n) return s;
    
    int count[rows];
    memset(count,0,sizeof(count));
    char rows_result[rows][n/2+1];
    int step=0;
    int direct=1;
    int i=0, j=0;
    for(i=0;i<n;i++) {
        rows_result[step][count[step]++] = s[i];
        if(step == rows-1) direct=-1;
        if(step == 0) direct=1;
        step += direct;
    }

    char *result = malloc(n+1);
    int cusor=0;
    // construct result
    for(i=0;i<rows;i++) {
        memcpy(result+cusor, rows_result[i], count[i]);
        cusor+=count[i];
    }
    result[n] = '\0';
    return result;
}

int main(int argc, char const *argv[])
{
    char *string = "ABC";
    char *result = convert(string, 2);
    printf("result:%s \n", result);
    return 0;
}