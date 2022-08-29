#include <iostream>
// LINEAR RECURSION
/*
 * Has Head Recursion and Tail Recursion.
 * Only has one Recursion statement in the function
 */


void func1(int n){ // LINEAR RECURSION
    if(n>0){
        std::cout<<n<<std::endl;
        func1(n-1);
        std::cout<<n<<std::endl;
    }
}

int main() {
    func1(4);
}
