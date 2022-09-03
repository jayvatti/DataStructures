#include <iostream>
/* N Factorial
 * 6! = 6 x 5 x 4 x 3 x 2 x 1 = 720
 * n! = n x (n-1)!
 *
 * */
int factorial(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*factorial(n-1) ; //TIME COMPLEXITY - ORDER OF (N)
        //SPACE - Order of O(n)
    }
}

int main() {
   std::cout<< factorial(6);
}
