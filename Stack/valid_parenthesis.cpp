// Approch : for every opening bracket there is closing bracket so push the opening bracket into stack and if closing braket occurs then check if opening bracket present or not corresponding to closing bracket if present then pop out and at the end if stack is empty then valid paranthesis


bool matches(char top , char ch){
    if((ch == ')' && top == '(') ||
       (ch == ']' && top == '[') ||
       (ch == '}' && top == '{')){
        return true;
       }
    else {
        return false;
    }
}


bool isValidParenthesis(string expression){
    stack<char> s;

    for(int i = 0 ; i<expression.length(); i++){
        char ch = expression[i];

        // if opening bracket, stack push
        // if close bracket, stacktop check and pop

        if (ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else {
            // for closing bracket
            if(!s.empty()){
                char top = s.top();
                if(matches(top,ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else {
        return false;
    }
}