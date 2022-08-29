#include <iostream>
/*
 * Loops only have ascending Phase.
 * Recursions have an ascending and descending Phase.
 */
// TRACING TREE RECURSION

void func1(int n){ // RETURN PHASE or ASCENDING or TAIL RECURSION
    if(n>0){
        std::cout<< n; // Executes at calling time
        func1(n-1);
    }
}; // OUTPUT: 4 3 2 1

void func(int n){//CALLING PHASE or DESCENDING or NON-TAIL RECURSION
    if(n>0){
        func(n-1);
        std::cout<<n; // Executes at return time
    }
}; // OUTPUT: 1 2 3 4

int main() {
    func1(4);
    func(4);
}









