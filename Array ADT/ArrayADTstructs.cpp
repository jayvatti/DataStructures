
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
void showArray(struct Array arr) {
    std::cout << "The elements are:" << std::endl;
    for (int i = 0; i < arr.length; i++) {
        std::cout << arr.A[i] <<",";
    }
}
void append(struct Array *arr, int value){ //*arr because arr is getting modified
    if((arr->length) < (arr->size)){
        arr->A[arr->length++] = value;
    }
}
void insert(struct Array *arr,int index,int value){
    if(index>=0 && index<=(arr->length)){
        for(int i = arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = value;
        arr->length++;
    }
}
int remove(struct Array *arr, int index){//deletes that index value and the index //values shift one index before
    if(index> 0 && index < arr->length){
        int deletedValue = arr->A[index];
        for(int i = index; i<(arr->length-1);i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return deletedValue;
    }
    return 0;

}
int main(){
    Array arr;
    arr.size = 5;
    arr.A = new int[arr.size];
    arr.length = 3;

    std::cout<<"Enter elements in the Array:"<<std::endl;
    for (int i = 0; i < arr.length; i++){
        std::cin >> arr.A[i];
    }
    append(&arr,15);
    insert(&arr,3,11);
    remove(&arr,4);
    showArray(arr);

    std::cout<<"Array Length:"<<arr.length;
}
