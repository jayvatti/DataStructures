#include <iostream>

//DIAGONAL MATRICES
/*
 * Only has diagonal elements
 * Example:
 * M =
 * [ 1 0 0 0 0
 *   0 1 0 0 0
 *   0 0 1 0 0
 *   0 0 0 1 0
 *   0 0 0 0 1 ] is a diagonal matrix; where M is a 5x5 matrix
 *
 *   Definition:
 *   1 -> M[i][j] = 0 ; i != j;
 *   2 -> M[i][j] = n ; where i == j; where n is an element;
 *
 *   Memory:
 *   Efficient to store in single dimensional array if other indexes are of no use
 */
struct Matrix{
    int n;
    int diagonolMatrix[5];
};
void set(struct Matrix *dMatrix,int i, int j, int value){
    //i and j -> rows and columns of "diagonalMatrix"
    if(i==j){
        dMatrix->diagonolMatrix[i-1] = value;
    }
}
int get(struct Matrix *dMatrix,int i, int j){
    if(i==j){
        return dMatrix->diagonolMatrix[i-1];
    }
    else{
        return 0;
    }
}
void display(struct Matrix dMatrix){
    for(int i = 1; i <= dMatrix.n; i++){

        for(int j = 1; j <= dMatrix.n; j++){
                if(i==j){
                    std::cout<<dMatrix.diagonolMatrix[i-1]<<" ";
                }
                else{
                    std::cout<<"0 ";
                }
        }
        std::cout<<std::endl;
    }
}
int main(){
    struct Matrix dMatrix;
    dMatrix.n = 5;
    set(&dMatrix,1,1,1);
    set(&dMatrix,2,2,2);
    set(&dMatrix,3,3,3);
    set(&dMatrix,4,4,4);
    set(&dMatrix,5,5,5);
    display(dMatrix);
    std::cout<<"At 5,5:"<<get(&dMatrix,5,5)<<std::endl;

}