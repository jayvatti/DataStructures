//
// Created by Jay Vatti on 8/29/22.
#include <iostream>
#include <math.h>

/*TAYLOR SERIES
 *
 * */
float taylor(int x,int n){ //EFFICIENT
    static float power = 1,factorial = 1; //power,factorial = 1 doesn't work
    float value;
    if(n == 0){
        return 1;
    }
    else{
        value = taylor(x,n-1);
        power = power *x;
        factorial = factorial * n;
        return value + power/factorial;

    }

}
int factorial(int n);
float taylor2(int x, int n);
int main() {
    std::cout<< taylor(1,10)<<std::endl;
    std::cout<< taylor2(1,10);

}
//TAYLOR FLOWCHART:
/*
 * taylor(x,4) = taylor(x,3) + x^4/4!
 *               taylor(x,3) = taylor(x,2) + x^3/3!
 *                             taylor(x,2) = taylor(x,1) + x^2/2!
 *                                           taylor(x,1) = taylor(x,0) + x
 *                                                         taylor(x,0) = 1
 * Static Variables : Power, Factorial (Default Value 1)
 * Value = taylor(x,1 - 1)     = 1 (for taylor(x,1)), because n == 0
 * Power = Power * x           = x (for taylor(x,1))  //STATIC
 * Factorial = Factorial * n   = 1 (for taylor(x,1))  //STATIC
 * Value = Value + Power/Factorial
 *
 * taylor(x,2)
 * Value = taylor(x,1)         = 1 + x
 * Power                       = x*x
 * Factorial                   = 1 * 2
 * Value                       = 1 + x + x*x/2*1
 *
 * ...so on
 */


//ALTERNATE - BRUTE FORCE RECURSION
int factorial(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*factorial(n-1) ; //TIME COMPLEXITY - ORDER OF (N)
        //SPACE - Order of O(n)
    }
}
float taylor2(int x, int n){
    if (n==0){
        return 1;
    }
    else{
        return (pow(x,n)/factorial(n)) + taylor2(pow(x,n-1),n-1);
    }
}
