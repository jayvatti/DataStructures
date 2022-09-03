//
// Created by Jay Vatti on 8/29/22.
#include <iostream>
int func1(int n){ // RECURSION WITHOUT STATIC VARIABLES
    if(n>0){
        return func1(n-1) + n;
    }
    return 0;
};

int func(int n){ // RECURSION WITH STATIC VARIABLE //SQUARING THE NUMBER
    static int x = 0;
    if(n>0){
        x++;
        return func(n-1) + x;
    }
    return 0;
}
int main() {
    std::cout<<func1(5)<<std::endl;

    std::cout<<func(11)<<std::endl;// Since func has a static variable, it acts as a global variable.
    // You can use a global variable too (Outside func, int x = 0;)
}
