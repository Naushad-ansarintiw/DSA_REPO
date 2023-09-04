// T.C O(n*kLogK)
// S.C O(n*k)

class node {
    public:
      int data;
      int i;
      int j;  
    
    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};


vector<int> mergeKSortedkArraysays(vector<vector<int>>&kkArraysays, int k){
    priority_queue<node* , vector<node*> , compare > mini;

    // step 1: saare kArraysays k first element insert karna hoi

    for(int i=0; i<k; i++){
        node* tmp = new node(kArrays[i][0], i, 0);
        mini.push();
    }

    // step2:
    vector<int> ans; 
    while(mini.size()>0){
    node* tmp = mini.top();

        ans.push_back(tmp->data);
        mini.pop();

        int i = tmp->i;
        int j =tmp->j;

        if(j+1 < kkArraysays[i].size()){
        node* next = new node(kArrays[i][j+1], i, j+1);
        mini.push(next);
        }
    }

    return ans;
}