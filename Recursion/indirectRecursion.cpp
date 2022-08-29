#include <iostream>
// INDIRECT RECURSION
/* Indirect Recursion -> Calling Recursive Functions in a circular Order.
 * A -> B. B -> C. C -> A. ( A,B,C are Recursive Functions)
 * If one of the Recursive Function Fails, then it'll return to the starting call
 *
 * NOTE: USE FUNCTION PROTOTYPES
 */
void funcA(int n);
void funcB(int n){ // INDIRECT RECURSION
    if(n>1){
        std::cout<<n<<std::endl;
        funcA(n/2);
    }
};
void funcA(int n){ //
    if(n>0){
        std::cout<<n<<std::endl;
        funcB(n-1);
    }
};


int main() {
    funcA(3); //
}
