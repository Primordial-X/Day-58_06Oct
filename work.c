#include <stdio.h>
#include <string.h>

//Q108: Write a Program to take an integer array nums. 
//Print an array answer such that answer[i] is equal to the product 
//of all the elements of nums except nums[i]. 
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

/*
Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]

*/

int main() {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int answer[n];

    // Initialize the answer array with 1s
    for (int i = 0; i < n; i++) {
        answer[i] = 1;
    }

    // Calculate the product of all elements to the left of each index
    int left_product = 1;
    for (int i = 0; i < n; i++) {
        answer[i] *= left_product;
        left_product *= nums[i];
    }

    // Calculate the product of all elements to the right of each index
    int right_product = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= right_product;
        right_product *= nums[i];
    }

    // Print the result
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", answer[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}