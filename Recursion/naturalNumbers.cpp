#include <iostream>
#include <math.h>
/* Sum of N Natural Numbers
 * 1 + 2 + ...... (n-1) + n
 * sum(n) = sum(n-1) + n
 *
 * ARITHMETIC PROGRESSION FORMULA: n(n + 1)/2
 * */
int sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return sum(n-1) + n; //TIME COMPLEXITY - ORDER OF (N)
        //SPACE - Order of O(n)
    }
}
int arithmeticSum(int n){
    return n*(n+1)/2;  //TIME COMPLEXITY - ORDER OF O(1)
}
int main() {
   std::cout<< sum(3);
}
