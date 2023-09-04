// T.C O(n^2)
// S.C O(n)

void sortInsert(stack<int>& s, int num){
      // base case
      if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
      }

      int n = s.top();
      s.pop();

      // recursive call
      sortInsert(s,num);
      s.push(n);
}

void sortStack(stack<int>& stack){
    // base case
    if(stack.empty()){
        return; 
    }

   int num = stack.top();
   stack.pop();

   // recursive call
   sortStack(stack); 

   sortInsert(stack,num);
}