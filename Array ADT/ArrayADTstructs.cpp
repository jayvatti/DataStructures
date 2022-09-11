
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <vector>

struct Array
{
    int* A;
    int size;
    int length;
};
void showArray(struct Array arr) {
    std::cout << "The elements are:" << std::endl;
    for (int i = 0; i < arr.length; i++) {
    std::cout << arr.A[i] <<"";
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
    showArray(arr);
}