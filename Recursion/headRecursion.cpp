#include <iostream>
// HEAD RECURSION
/*
 * Head Recursion -> Recursions whose value is to be used after the recursion is done.
 *
 * Head Recursions mostly do not have anything above the recursive statement.
 *
 * You cannot convert it into a loop by looking at Head Recursion. Conversion to a loop is a bit difficult.
 */

void func(int n){ //LOOPS
    int i = 1;
    while(i <= n){
        std::cout<<n;
        i++;
    }
}

void func1(int n){ // HEAD RECURSION
    if(n>0){
        func1(n-1);
        std::cout<<n<<std::endl;
    }
}

int main() {
    func1(4);
}
