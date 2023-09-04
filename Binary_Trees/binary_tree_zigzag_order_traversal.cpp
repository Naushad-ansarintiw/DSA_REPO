#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};


node* buildTree(node* root) {

    cout<<" Enter the data: " <<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left"<<endl;
    root->left = buildTree(root->left);

    cout<< "Enter data for inserting in right "<<endl;
    root->right = buildTree(root->right);

    return root;
    

}

vector<vector<int>> levelOrderTraversalzigZag(node* root){
    queue<node*> q;
    vector<vector<int>> vec;
    vector<int> ans;
    q.push(root);
    q.push(NULL);
    int cnt = 0;

    while (!q.empty())
    {
        node* temp = q.front(); 
        q.pop();

        if(temp == NULL) { // purana level complete traverse ho chuka hai

            if(cnt %2 == 0){
                for(int i = 0 ;i<ans.size()/2; i++){
                    swap(ans[i], ans[ans.size()-i-1]);
                }
                vec.push_back(ans);
                ans.clear();
            }
            else{
                vec.push_back(ans);
                ans.clear();          
            }
            cnt++;
            if(!q.empty()){ // queue still has somwechild nodes
                q.push(NULL);
            }

        }
        else {
            ans.push_back(temp->data);
            if(temp->right){
                q.push(temp->right);
            }
    
            if(temp->left){
                q.push(temp->left);
            }
        }

    }
    return vec;

}

int main(){
     
     node* root = NULL;
     vector<vector<int>> ans;
     
     // Creating a Tree
     root = buildTree(root);
     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

     // level order
    ans= levelOrderTraversalzigZag(root);
    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
return 0;
}