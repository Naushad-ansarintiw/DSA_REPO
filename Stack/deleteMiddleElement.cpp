// Aprroch: Find the size of the stack and count how much deep you are and if your count go to size/2 then delete the middle element


// S.C O(size/2);
// T.C O(size/2);


void solve(stack<int>& inputStack, int count, int size){
    // base case 
    if(count == size/2){
        inputStack.pop();
        return ;
    }

    int num = inputStack.top();
    inputStack.pop();

    // RECURSIVE CALL

    solve(inputStack, count+1,size);
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;

    solve(inputStack,count,N);
}