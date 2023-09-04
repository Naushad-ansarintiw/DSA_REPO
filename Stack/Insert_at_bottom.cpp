// Approch: first pop out the top and call recursive function when stack is empty the push the element and when backtrack push the remaining element

// T.C O(size of Stack)
// S.C O(size of Stack)

void solve(stack<int>& s, int x){
    // base case
    if(s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();

    // Recursive call
    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x){
    solve(myStack, x);
    return myStack;
}