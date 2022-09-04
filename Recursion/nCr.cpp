//
// Created by Jay Vatti on 8/29/22.
#include <iostream>
/*
 * nCr = n!/r!(n-r)!
 *
 * Recursion USING PASCAL'S TRIANGLE
 */

int nCr(int n,int r){
    if(n == r || r ==0){
        return 1; //returns 0 if n = 0; returns 1 if n = 1;
    }
    else{
        return nCr(n-1,r-1) + nCr(n-1,r);
    }
}
int main()
{
    std::cout<<nCr(7,2);
}