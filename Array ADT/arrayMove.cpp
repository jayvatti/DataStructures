
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
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x= *y;
    *y = temp;
}
void reverse(struct Array *arr){
    for(int i = 0, j = arr->length - 1; i < j ; i++, j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}
void showArray(struct Array arr) {
    std::cout << "The elements are:" << std::endl;
    for (int i = 0; i < arr.size; i++) {
        std::cout << arr.A[i] <<",";
    }
}
void insertSorted(struct Array *arr,int value){
    int i = arr->length - 1;
    while(arr->A[i] > value){
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
}
void negativeAndPositiveSplit(struct Array *arr){
    int i = 0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >= 0)j--;
        if(i < j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
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
    negativeAndPositiveSplit(&arr);
    showArray(arr);




}