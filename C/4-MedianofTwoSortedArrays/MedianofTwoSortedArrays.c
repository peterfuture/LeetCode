// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Peter-s

/**********************************************************************************
*
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
* The median is 2.0
*
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
* The median is (2 + 3)/2 = 2.5
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchbin(int A[], int low, int high, int key)
{
    int mid = 0;
    if(key < A[low])
        return low-1;
    if(key > A[high])
        return high;
    while(low <= high) {
        mid = (low+high)/2;
        if(A[mid] == key)
            return mid;
        else if(key > A[mid]) 
            low = mid+1;
        else
            high = mid-1;
        //printf("%d-%d-%d \n", low,mid,high);
    }
    return low-1;
}

//A[1->m] B[1->n]
double findMedianSortedArrays(int* A, int m, int* B, int n) {

    //special case
    if(m==0 && n==0) 
        return 0.0;
    if(m==0) 
        return n%2==1 ? B[n/2] : (B[n/2-1] + B[n/2])/2.0;
    if(n==0) 
        return m%2==1 ? A[m/2] : (A[m/2-1] + A[m/2])/2.0;
    
    double result1;
    double result2;

    int min1 = 0;
    int max1 = m-1;
    int mid1 = max1/2;

    int min2 = 0;
    int max2 = n-1;
    int mid2 = max2/2;

    int target1 = ((m+n)%2==1)?(m+n)/2:(m+n)/2-1;
    int target2 = ((m+n)%2==1)?target1:target1+1;
    //printf("m:%d n:%d target1:%d target2:%d\n", m, n, target1, target2);

    if(B[0] >= A[m-1]) {
        if(m-1 >= target1)
            result1 = A[target1];
        else
            result1 = B[target1-m];
        if(m-1 >= target2)
            result2 = A[target2];
        else
            result2 = B[target2-m];
        return (result1+result2)/2;
    }
    
    if(A[0] >= B[n-1]) {
        if(n-1 >= target1)
            result1 = B[target1];
        else
            result1 = A[target1-n];
        if(n-1 >= target2)
            result2 = B[target2];
        else
            result2 = A[target2-n];
        return (result1+result2)/2;
    }

    while(1) {

        //printf("loop:%d %d %d %d %d %d %d \n", i++, min1, mid1, max1, min2, mid2, max2);
        if(min1 > max1) {
            if(min1 > 0)
                mid1 = min1 = min1 - 1;
            else
                mid1 = min1;
            break;
        }
        mid1 = (min1+max1)/2;
        // check break condition
        mid2 = searchbin(B, min2, max2, A[mid1]);
        if(mid1+mid2+1 == target1) {
            break;
        }
        if(mid1+mid2+1 > target1) {
            max1 = mid1-1;
            max2 = mid2;
        } else if(mid1+mid2+1 < target1) {
            min1 = mid1 + 1;
            min2 = mid2;
        }
        
    }

    // construct result
    //printf("construct result mid1:%d\n", mid1);
    mid2 = searchbin(B, min2, max2, A[mid1]);
    if(mid1+mid2+1 == target1) {
        if(mid2 < 0)
            result1 = A[mid1];
        else
            result1 = (A[mid1] >= B[mid2])?A[mid1]:B[mid2];

    } else if(mid1+mid2+1 < target1) {
        // Find target1
        while(1) {
            if(mid1+mid2+1 == target1) {
                result1 = (A[mid1] >= B[mid2])?A[mid1]:B[mid2];
                break;
            } else if(mid1+mid2+1 < target1)
                mid2++;
        }

    } else {
        // A[0] is too bigger
        result1 = B[target1];
        mid2 = target1;
        mid1 = -1;
    }

    if(target1 == target2)
        return result1;

    if(mid1 < m-1)
        mid1++;
    else {
        result2 = B[mid2+1];
        return (result1+result2)/2;
    }
    if(mid2 < n-1)
        mid2++;
    else {
        result2 = A[mid1];
        return (result1+result2)/2;
    }
    result2 = (A[mid1] <= B[mid2])?A[mid1]:B[mid2];
    return (result1+result2)/2;
}

int main(int argc, char const *argv[])
{
    int array1[] = {1,4};
    int array2[] = {2,3};
    double  result = findMedianSortedArrays(array1,2, array2, 2);
    //int pos = searchbin(array2, 0, 3, 9);
    printf("result:%f \n", result);
    return 0;
}