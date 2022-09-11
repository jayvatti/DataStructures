
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <vector>

class Array{ //autocalls the destructor 
private:
    int* A;
    int size;  //max size
    int length;//used size
    //remember that size > length

    /*  Q)if length > size:
    *  Ans) C and C++ compilers will not check the boundaries of array. They only check the segment(block of memory given to a program)
       If your program access location outside segment then it will give an error. Programmer should check the boundary of array.
    */

public:
    Array(int size){
        this->size = size;
        A = new int [size];
    }
    void createArray(){
        std::cout << "Enter number of elements: " <<std::endl;
        std::cin>> length;
        std::cout << "Enter the elements: " << std::endl;
        for (int i = 0; i < length; i++){
            std::cout << "Array element: " << i << " = " << std::flush;
            std::cin >> A[i];
        }
    }

    void showArray(){
        std::cout<<"Array Printed:"<<std::endl;
        for (int i = 0; i < length; i++){
            std::cout << A[i] << " ";
        }
    }

    ~Array(){
        delete[] A;
        std::cout<< "Destroyed the Array" << std::endl;
    }
};

int main() {
    Array arr(10);
    arr.createArray();
    arr.showArray();
}
