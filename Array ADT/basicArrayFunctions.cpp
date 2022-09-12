
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

int sum(int A[], int index){
    if(index < 0){
        return 0;
    }
    return sum(A, index -1) + A[index];

}
int get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}
void set(struct Array *arr, int index, int value){
    if(index >= 0 && index < arr->length){
       arr->A[index] = value ;
    }
}
int max(struct Array arr){
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if(max < arr.A[i]){
            max = arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr){
    int min = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if(min > arr.A[i]){
            min = arr.A[i];
        }
    }
    return min;
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
    std::cout<<"SUM:"<<sum(arr.A,4)<<std::endl;
    std::cout<<"MIN:"<<min(arr)<<std::endl;
    std::cout<<"MAX:"<<max(arr)<<std::endl;
    set(&arr,4,12);
    std::cout<<"GET:"<<get(arr,4)<<std::endl;



}