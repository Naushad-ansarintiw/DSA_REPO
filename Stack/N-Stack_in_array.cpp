// T.C O(1)
// S.C O(s+n)


class NStack {
    int* arr;
    int* top;
    int* next;

    int n,s;

    int freespot;

public:     
    // Initailize your data Structure
    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];

        next = new int[s];

        // top initialise
        for(int i=0; i<n; i++){
            top[i] = -1;
        }

        // next intialize
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        // update last index value to -1
        next[s-1] = -1;

        // initialize freespot
        freespot = 0;
    }

    // Push operation 
    bool push(int x, int m){
        // check for overflow

        if(freespot == -1){
            return false;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert element into array
        arr[index] = x;

        // uodate next;
        next[index] = top[m-1];

        // update top

        top[m-1] = index;

        return true;
    }

    // pop operation 
    int pop(int m){
        // check underflow condition
        if(top[m-1] == -1){
            return -1;
        }

        // just reverse the push operation

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];

    }
}