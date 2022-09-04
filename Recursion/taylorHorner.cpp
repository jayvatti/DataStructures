//
// Created by Jay Vatti on 8/29/22.
#include <iostream>
#include <math.h>
/*TAYLOR SERIES - HORNER'S RULE
 *
 * e^x = 1 + x/1 + x^2/2! + x^3/3! ... n terms
 *
 * taylor(x,4) = 1 + x/1 +  x^2/2! + x^3/3! + x^4/4!
 *             = 1 + x/1 ( 1 + x/2 + x^2/3! + x^3/4!)
 *             = 1 + x/1 ( 1 + x/2 ( 1 + x/3 + x^2/4*3))
 *             = 1 + x/1 ( 1 + x/2 ( 1 + x/3 ( 1 + x/4))) // HORNER'S RULE
 *
 * TIME COMPLEXITY - ORDER OF O(n^2) // DEFAULT TAYLORS SERIES
 *                 - ORDER OF O(n)  // APPLYING HORNER's RULE
 *
 * NOTE: (x/n)*value; = (x*value/n)
 * */
float hornerLoop(int x,int n){ //EFFICIENT compared to DEFAULT TAYLOR SERIES
    float value = 1;
    while(n>0){
        value = 1 + (x*value/n);  //NOTE
        n--;
    }
    return value;
}

float taylorLoop(int x,int n);

float hornerRecursion(int x, int n){
    static float hornerSum = 1;
    if(n==0){
        return hornerSum;
    }
    else{
        hornerSum = 1 + (x*hornerSum/n); //NOTE
        return hornerRecursion(x,n-1);
    }
}
int main() {
    std::cout<< hornerRecursion(1,10)<<std::endl;
    std::cout<< taylorLoop(1,10);
}

//FLOWCHART
/*
 * hornerRecursion(x,4)
 *
 * FOR x,4
 * hornerSum = 1 + x/4
 * return hornerRecursion(x,3)
 *
 * FOR x,3
 * hornerSum = 1 + x/3 ( 1 + x/4) //since hornerSum is Static (global)
 * return hornerRecursion(x,2)
 *
 * .. so on
 *
 */
float taylorLoop(int x, int n){
    float value = 1;
    float numerator = 1;
    float denominator = 1;
    for (int i = 1; i <= n;i++){
        numerator = numerator * x;
        denominator = denominator * i;
        value = value + numerator/denominator;
    }
    return value;
}




