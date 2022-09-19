#include <iostream>

class Node{
public:
    int data;
    Node *next;

    void createLinkedList(int array[],int n);
    void display(Node *p);
    Node* search(Node *p, int value);
    Node* recursiveSearch(Node *p, int value);

    //IMPROVING SEARCH:
    Node* searchTransposition(Node *p, int value);
    void checkSearch(Node *p);

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
Node* Node::search(Node *p, int value) {
    while(p!=NULL){
        if(value == p->data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node *Node::recursiveSearch(Node *p, int value) {
    if(p != NULL){
        if(value == p->data){
            return p;
        }
        return recursiveSearch(p->next,value);
    }
    return NULL;
}

Node * Node::searchTransposition(Node *p, int value) {
    Node *previousNode = NULL;//previousNode for the element found; (previousNode of the (Node where the value == p->data)
    //Previous Node -> P -> p->next; //sample structure
    while(p!= NULL){
        if(value == p->data){
            previousNode->next = p->next; //assigning the previous node to the Next Node
            //previousNode -> p->next

            p->next = first;
            first = p;
            return p;
        }
        previousNode = p;
        p = p->next;
    }
}
void checkSearch(Node *p) {
    if(p){
        std::cout<<"Value is Found:"<<p->data<<std::endl;
    }
    else{
        std::cout<<"Value NOT FOUND!!"<<std::endl;
    }
}
int main(){
    int array[] = {1,2,3,5,4};
    Node *p;
    p->createLinkedList(array,5);

    Node *search;
    search = p->search(first,7);
    std::cout<<"Search 7:";
    checkSearch(search);
    std::cout<<std::endl;

    std::cout<<"Recursive Search 5:";
    search = p->recursiveSearch(first,5);
    checkSearch(search);
    std::cout<<std::endl;

    std::cout<<"Search Transposition 5:";
    search = p->searchTransposition(first,5);
    checkSearch(search);
    std::cout<<std::endl;

    p->display(first);



}