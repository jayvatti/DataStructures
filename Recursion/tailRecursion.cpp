#include <iostream>
// TAIL RECURSION
/*
 * Tail Recursion -> recursions at the end of the function
 * The value returned by the recursion isn't used anywhere.
 * Tail Recursions can be easily converted to loops
 *
 * Tail Recursions and loops take the same time.
 * Tail Recursions, Loops -> O(n) -> Time Complexity
 *
 * Tail Recursions -> O(n) -> Space Complexity -> Due to the use of Stack Memory 
 * Loops           -> O(1) -> Space Complexity
 *
 * Therefore, Loops are space efficient. Many Compilers try to convert Tail Recursions to loops.
 */
void func(int n){ //LOOPS
    while(n > 0){
        std::cout<<n;
        n--;
    }
}

void func1(int n){ // TAIL RECURSION
    if(n>0){
        std::cout<<n<<std::endl;
        func1(n-1);
    }
}

int main() {
    func1(4);
}
