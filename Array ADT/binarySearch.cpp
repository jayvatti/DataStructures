
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <vector>

struct Array
{
    int* A;
    int size;  //max size
    int length;//used size
    //remember that size > length
};

//for binary Search, Array should be sorted.
/*
 * calculate the mid based on low and high.
 * if the value is less than mid -> high = mid -1
 * if the value is greater than mid -> low = mid + 1;
 * repeat until low <=high;
 */

//TIME COMPLEXITY:
/*
 * BEST CASE -> O(n)
 * WORST CASE -> O(log (base 2) n) //including if the element isn't found
 */

int binarySearchIteration(struct Array arr, int value){
    int low = 0;
    int high = arr.length-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(value == arr.A[mid]){
            return mid;
        }
        else if (value < arr.A[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1; //if value not found
}
int binarySearchRecursion(int arr[], int low, int high, int value)
{
    int mid = 0;
    if(low <= high)
    {
        mid = (low + high)/2;
        if (arr[mid] == value) {
            return mid;
        } else if(arr[mid] > value) {
            return binarySearchRecursion(arr,low,mid-1,value);
        } else if(arr[mid] < value){
            return binarySearchRecursion(arr,mid+1,high,value);
        }
    }
    return -1;
}

int main(){
    Array arr;
    arr.size = 5;
    arr.A = new int[arr.size];
    arr.length = 5;

    std::cout<<"Enter elements in the Array:"<<std::endl;
    for (int i = 0; i < arr.length; i++){
        std::cin >> arr.A[i];
    }
    std::cout<<"Binary Search I:"<<binarySearchIteration(arr,4)<<std::endl;
    std::cout<<"Binary Search R2:"<<binarySearchRecursion(arr.A,0,4,4)<<std::endl;
}
