// Approach: Stack1 use space left side and Stack2 use space from right side in single array

#include<iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

public: 
    
    // Initialize TwoStack
    TwoStack(int s){
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in Stack 1
    void push1(int num){
        if(top2-top1 > 1){
            top1++;
            arr[top1] = num;
        }
        else {
            cout<<"Stack Overflow "<<endl;
        }
    }

    // Push in Stack 2
    void push2(int num){
        if(top2-top1 > 1){
            top2--;
            arr[top2] = num;
        }
        else {
            cout<<"Stack Overflow "<<endl;
        }
    }

    // Pop from stack1 and return popped element
    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            cout<<"Stack Underflow "<<endl;
            return -1;
        }
    }


    // Pop from stack2 and return popped element
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            cout<<"Stack Underflow "<<endl;
            return -1;
        }
    }
};



int main(){

 TwoStack st(5);

 st.push1(34);

cout<<st.pop1()<<endl;
cout<<st.pop1()<<endl;

    return 0;
}