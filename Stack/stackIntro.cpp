#include <iostream>
using namespace std;


class StackArray {
    // properties 
       public: 
            int *arr;
            int top;
            int size;

    // operation
       StackArray(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
       } 

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else {
            cout<< "Stack Overflow "<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<< "Stack Underflow "<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else {
            cout<<"Stack is empty "<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else {
            return false;
        }
    }

};

// Creating a Node

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

};

class StackLinkedList {

    public:
        Node* top;
        StackLinkedList(){
            top = NULL;
        }

        void push(int data){
            // Create new node temp and allocate memory in heap
            Node* temp = new Node(data);

            if(!temp){
                cout<<"Stack Overflow "<<endl;
                exit(1);
            }

            temp -> next = top ;

            top = temp;
        }

        int isEmpty(){
            if(top == NULL){
                cout<<"stack is Empty "<<endl;
                return 1;
            }
            else {
                return 0;
            }
        }

        int pop(){

            if(isEmpty()){
                cout<<"Stack is EmptY"<<endl;
                return -1;
            }
            else {
                int ans = top->data;
                Node* deleteNode = top;

                top = top->next;

                delete(deleteNode);

                return ans;
            }

        }

        int peek(){
            if(!isEmpty()){
                return top->data;
            }
            else {
                return -1;
            }
        }


};


int main(){

    // Using array
    StackArray st(5);

    st.push(22);
    st.push(43);
    st.push(44);

    cout<< st.peek()<<endl;

    st.pop();

    cout<< st.peek()<<endl;
    st.pop();

    cout<< st.peek()<<endl;
    st.pop();

    cout<< st.peek()<<endl;

    

    // Using Linked list;

    StackLinkedList st;

    st.push(43);
    st.pop();
    cout<<st.peek()<<endl;
   

     
return 0;
}