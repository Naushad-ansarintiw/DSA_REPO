// T.C O(n)
// S.C O(n)
queue<int> rev(queue<int> q){
    // step 1: put all element in stack from queue
    stack<int> s;

    while(!q.empty()) {
        int element =  q.front();
        q.pop();
        s.push(element);
    }

    // step2: put all element in queue from stack

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return queue;
}