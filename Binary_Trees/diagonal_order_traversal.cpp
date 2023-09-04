#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};


Node* buildTree(Node* root) {

    cout<<" Enter the data: " <<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left"<<endl;
    root->left = buildTree(root->left);

    cout<< "Enter data for inserting in right "<<endl;
    root->right = buildTree(root->right);

    return root;
    

}

void buildFromLevelOrder(Node* &root){
    queue<Node* > q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left Node for: " <<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right Node for: " <<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }


    }
}

vector<int> diagonal(Node *root)
{
    map<int, map<int, vector<int> > > Nodes;
    queue<pair<Node*, pair<int,int> > > q;

    vector<int> ans;

    if(root == NULL)
        return ans;
        
    q.push(make_pair(root, make_pair(0,0)));

    while (!q.empty())
    {
        pair<Node*, pair<int,int> > temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        Nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd+1, lvl+1)));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd, lvl+1)));
        }
    }

    for(auto i : Nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}


int main(){
     
     Node* root = NULL;
     
     // Creating a Tree
    //  root = buildTree(root);
     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     buildFromLevelOrder(root);

    vector<int> ans;

    ans = diagonal(root);

    for(auto i: ans){
        cout<<i<<" ";
    }
   
return 0;
}