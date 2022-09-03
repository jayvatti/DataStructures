//
// Created by Jay Vatti on 8/29/22.
#include <iostream>

/*EXPONENTS
 * 2^4 = 2 x 2 x 2 x 2
 * exponent(m,n) = m * exponent(m,n-1).
 * If n == 0; return 1
 *
 *ALTERNATE METHOD
 * EVEN: 2^8 = (2^2)^4 - less recursions
 * ODD:  2^9 = 2 * (2^2)^4
 * */
int exponent(int m,int n){
    if(n==0){
        return 1;
    }
    else{
        return m* exponent(m,n-1); // TIME COMPLEXITY -
    }
}
int power(int m,int n){
    if(n==0){
        return 1;
    }
    else if(n%2 == 0){
        return power(m*m,n/2);
    }
    else{
        return m* power(m*m,(n-1)/2);
    }
}
int main() {
    std::cout<<power(2,9)<<std::endl;
}
//FLOWCHART OF power(2,9)
/*
 * power(2,9)
 * 2 * power(2*2, (9-1)/2 = 4)
 *     power(2*2, (9-1)/2 = 4) = power(2^2 * 2^2, 2)
 *                               power(2^2 * 2^2, 2) = power((2^2 * 2^2) * (2^2 * 2^2) , 1)
 *                                                     power(2^8 , 1) = 2^8 * power(2^8 * 2^8,0)   //ODD
 *                                                                            power(2^16,0) = 1
 */
