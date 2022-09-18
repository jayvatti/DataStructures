#include <iostream>

class DiagonolMatrix{
private:
    int n;
    int *diagonolMatrixArray;
public:
    DiagonolMatrix(int n){
        this->n = n;
        diagonolMatrixArray = new int[n];
    }
    void set(int i, int j, int value){
        if(i==j){ //other optional conditionals -> i and j <= n etc...
            diagonolMatrixArray[i-1] = value;
        }
    }
    int get(int i, int j){
        if(i==j){
            return diagonolMatrixArray[i-1];
        }
        else{
            return 0;
        }
    }
    void display(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i==j){
                    std::cout<<diagonolMatrixArray[i-1]<<" ";
                }
                else{
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
    }
    ~DiagonolMatrix(){
        delete[] diagonolMatrixArray;
    }
};
int main(){
    DiagonolMatrix d1(5);
    d1.set(1,1,1);
    d1.set(2,2,2);
    d1.set(3,3,3);
    d1.set(4,4,4);
    d1.set(5,5,5);
    d1.display();
}