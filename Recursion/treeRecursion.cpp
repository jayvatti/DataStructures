#include <iostream>
// TREE RECURSION
/* Tree Recursion -> A recursive function calling itself more than one time.
 * Time Complexity for func1 -> O(2^n) // DEPENDS on the Recursive Function. Changes for Every Tree Function accordingly
 * Space Complexity -> Height of the Tree. O(n). (Mostly consistent for most of the Tree Recursions because after one activation call is deleted, another one replaces it)
 */


void func1(int n){ // TREE RECURSION
    if(n>0){
        std::cout<<n<<std::endl;
        func1(n-1);
        func1(n-1);
    }
}

int main() {
    func1(3); // 15 calls -> 15 ACTIVATION RECORDS (Can be calculated by drawing the TREE)

    //CALLS -> no of functions needed to be executed. (Including the fail scenario for n = 0);
}
