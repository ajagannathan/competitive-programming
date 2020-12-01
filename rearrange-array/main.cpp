//Given an array of integers, rearrange the array such that every second element
//of the array is greater than its left and right elements. Assume no duplicate
//elements are present in the array
//
//for eg. Input : {1,2,3,4,5,6,7}
//        Output : {1,3,2,5,4,7,6}
//for eg. Input : {9,6,8,3,7}
//        Output : {6,9,3,8,7}
//for eg. Input : {6,9,2,5,1,4}
//        Output : {6,9,2,5,1,4}

#include "header.h"
#define ARRAY_SIZE 5

void rearrange(int *arr)
{
    for (size_t i = 0; i < (ARRAY_SIZE - 2); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        if (arr[i + 1] < arr[i + 2])
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i + 2];
            arr[i + 2] = temp;
        }
    }
}

int main()
{
    int a[ARRAY_SIZE] = {9, 6, 8, 3, 7};
    rearrange(a);
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << a[i] << " ";
    }
}