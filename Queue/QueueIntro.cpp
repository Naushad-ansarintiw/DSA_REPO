// Implementation using array

// O(1) T.C

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:    
    Queue(){
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty(){
        if(qfront == rear)
            return true;
        else 
            return false;
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"Queue is Full"<<endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear)
            return -1;
        else 
            return arr[qfront];
    }
}


// Implementation Circular Queue

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

    public: 
     CircularQueue(int n){
        size = 1000001;
        arr = new int[size];
        front = rear = -1;
     }  

     bool enqueue(int value){
        if((front == 0 && rear = size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is Full"<<endl;
            return false;
        }
        else if(front = -1) {
            front = rear = 0;
        }
        else if(front != 0 && rear = size -1 ){
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
     } 

     int dequeue(){ 
        // to check queue is full or not
        if(front == -1 ){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ // single element is present
            front = rear = -1 ;
        }
        else if(front == size-1) {
            front = 0; // to maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
     }
};


// Implement a Dequeue

class Deque {
    int* arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear  = -1;
    }

    bool pushFront(int x){
        // check full or not
        if((front == 0 && rear == size-1)|| (rear == (front-1)%(size-1))){
            return false;
        }
        else if(front == -1)
            front = rear = 0;
        else if(front == 0 && rear != size-1)
             front = n-1;
        else    
            front--;

        arr[front] = x;
        return true;
    }

    bool pushRear(int x){
        // check full or not
        if((front == 0 && rear == size-1)|| (rear == (front-1)%(size-1))){
            return false;
        }
        else if(front == -1)
            front = rear = 0;
        else if(rear == size-1 && front != 0)
            rear = 0;
        else 
            rear++;

        arr[rear] = x;
        return true;  
        
    }

    int popRear(){
        // to check queue is full or not
        if(front == -1 ){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ // single element is present
            front = rear = -1 ;
        }
        else if(rear == 0) {
            rear = size-1; // to maintain cyclic nature
        }
        else{
            rear--;
        }
        return ans;
     }

     int getFront(){
        if(isEmpty()){
            return -1
        }
        return arr[front];
     }

     int getRear(){
        if(isEmpty()){
            return -1
        }
        return arr[rear];
     }

     bool isEmpty(){
        if(front == 1)
            return true
        else 
            return false;
     }

     bool isFull(){
        if((front == 0 && rear == size-1)|| (front != 0 && rear == (front-1)%(size-1))){
            return true;
        }  
        else 
            return false;    
     }


}