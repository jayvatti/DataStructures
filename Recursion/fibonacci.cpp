//
// Created by Jay Vatti on 8/29/22.
#include <iostream>
/*
 * FIBONACCI SERIES
 *
 * fibonacci(n) = fibonacci(n-1) + fibonacci(n-2) for n > 1
 * 0 for n = 0
 * 1 for n = 1
 *
 * MEMOIZATION: storing the result of the function calls so that they can be utilized again to avoid excessive calls.
 */

int fibonacci(int n){
    if(n <=1){
        return n; //returns 0 if n = 0; returns 1 if n = 1;
    }
    else{
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

int fibonacciLoop(int n){
    int sum;
    int zero = 0;
    int one = 1;
    for(int i = 2 ;i <= n; i++){
        sum = zero + one;
        zero = one;
        one = sum;
    }
    return sum;
}

int fiboCache[20];
int fibonacciMemoization(int n) {
    if (n <= 1) {
        fiboCache[n] = n;
        return n;
    }
    else {
        if (fiboCache[n - 2] == -1) {
            fiboCache[n - 2] = fibonacciMemoization(n - 2);
        }
        if (fiboCache[n - 1] == -1) {
            fiboCache[n - 1] = fibonacciMemoization(n - 1);
        }

        fiboCache[n] = fiboCache[n - 2] + fiboCache[n - 1];
        return fiboCache[n - 2] + fiboCache[n - 1];

    }
}
int main()
{
    std::cout << fibonacci(7) << std::endl;
    std::cout << fibonacciLoop(7) << std::endl;

    for (int n = 0; n < 20; n++) {
        fiboCache[n] = -1;
    }
    std::cout << fibonacciMemoization(18) << std::endl;
}