#include <iostream>

class Node{
public:
    int data;
    Node *next;

    void createLinkedList(int array[],int n);
    void display(Node *p);

    void recursiveDisplay(Node *p);
    void reverseDisplayRecursive(Node *p);

    int length(Node *p);
    int lengthRecursive(Node *p);

    int sum(Node *p);
    int recursiveSum(Node *p);

    int max(Node *p);
    int recursiveMax(Node *p);
} *first = NULL;

void Node::createLinkedList(int array[], int n) {
    Node *temp, *last;
    first = new Node;
    first->data = array[0];
    first->next = NULL;
    last = first; // first and last have the same node;

    for(int i = 1; i < n ; i++){
        temp = new Node;
        temp->data = array[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void Node::display(Node *p) {
    while(p!=NULL){
        std::cout<<p->data<<std::endl;
        p = p->next;
    }
}
int Node::length(Node *p){
    int len = 0;
    while(p!=NULL){
        p = p->next;
        len++;
    }
    return len;
}
int Node::lengthRecursive(Node *p) {
    if(p==NULL){
        return 0;
    }
    return lengthRecursive(p->next) + 1;
    /* ANOTHER WAY:
     * if(p!=NULL){
     *      return lengthRecursive(p->next) + 1;
     * }
     * return 0;
     *
     * ANOTHER WAY:
     * if(p){ //will be true if p is pointing; if p == NULL then it's false
     *      return lengthRecursive(p->next) + 1;
     * }
     * return 0;
     */
}
int Node::sum(Node *p) {
    int sum = 0;
    while(p!= NULL){
        sum+= p->data;
        p = p->next;
    }
    return sum;
}
int Node::recursiveSum(Node *p) {
    if(p!=NULL){
        return p->data + recursiveSum(p->next);
    }
    return 0;
}

int Node::max(Node *p){
    int max = INT_MIN;
    while(p!=NULL){
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Node::recursiveMax(Node *p) {
    static int maxRecursive = INT_MIN;
    if(p!=NULL){
        maxRecursive = recursiveMax(p->next);
        if(maxRecursive > p->data){
            return maxRecursive;
        }
        return p->data;
    }
    return maxRecursive;
}



/*
 * Recursion Display:
 * Time = n + 1 // + 1 because of the fail case
 * Space = n + 1 // + 1 because of the NULL pointer
 */
void Node::recursiveDisplay(Node *p) {
    if(p!=NULL){
        std::cout<<p->data<<std::endl;
        recursiveDisplay(p->next);
    }
}
void Node::reverseDisplayRecursive(Node *p){
    if(p!= NULL){
        reverseDisplayRecursive(p->next);
        std::cout<<p->data<<std::endl;
    }
}
int main(){
    int array[] = {1,2,3,5,4};
    Node *p;
    p->createLinkedList(array,5);
    p->display(first);

    std::cout<<std::endl;

    std::cout<<"first:"<<&first<<std::endl;
    std::cout<<"    p:"<<p<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Length: "<<p->length(first)<<std::endl;
    std::cout<<"Length Recursive: "<<p->lengthRecursive(first)<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Sum: "<<p->sum(first)<<std::endl;
    std::cout<<"Sum Recursive : "<<p->recursiveSum(first)<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Max: "<<p->max(first)<<std::endl;
    std::cout<<"Max Recursive: "<<p->recursiveMax(first)<<std::endl;


    std::cout<<std::endl;
    std::cout<<"Recursive Display:"<<std::endl;
    p->recursiveDisplay(first);

    std::cout<<std::endl;
    std::cout<<"Recursive Reverse Display:"<<std::endl;
    p->reverseDisplayRecursive(first);


}