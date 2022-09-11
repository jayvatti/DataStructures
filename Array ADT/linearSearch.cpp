
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

    /*  Q)if length > size:
     *  Ans) C and C++ compilers will not check the boundaries of array. They only check the segment(block of memory given to a program)
        If your program access location outside segment then it will give an error. Programmer should check the boundary of array.
     */
};
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x= *y;
    *y = temp;
}
int linearSearch(struct Array *arr,int value){
    for(int i = 0;i<(arr->length);i++){
        if(value == (arr->A[i])){
            return i;
        }
    }
    return -1;
}
int transpositionSearch(struct Array *arr, int value){
    // the items in the array do not have the same index after every single search.
    // you bring the index of the searched item one index closer every time you search //swap the found-index with the index before it
    for(int i = 0;i<(arr->length);i++){
        if(value == (arr->A[i])){
            swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}
int movetoFront(struct Array *arr, int value){
    // the items in the array do not have the same index after every single search.
    // you bring the index of the item to the start after searching // swap with the found-index with the index at the start
    for(int i = 0;i<(arr->length);i++){
        if(value == (arr->A[i])){
            swap(&arr->A[i],&arr->A[0]);
            return 0;
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
    std::cout<<"Linear Search:"<<linearSearch(&arr,5);

}