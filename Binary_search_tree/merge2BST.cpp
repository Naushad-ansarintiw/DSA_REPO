// Approach1: Take inorder of both bst tress and then use merge 2 sorted arrray concept to get 3rd sorted array now convert inorder to BST

// T.C O(m+n)
// S.C O(m+n)

void inorder(Node* root, vector<int> &in){
    // base case 
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* inorderToBST(int s, int e, vector<int> &in){
    // base case 
    if(s>e)
        return NULL;

    int mid = (s+((e-s)/2));
    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s,mid-1, in);
    root->right = inorderToBST(mid+1, e, in);
    return root;
}

vector<int> mergeArray(vector<int> a, vector<int> b){
    vector<int> ans(a.size() + b.size());
    int i=0,j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j++];
        }
    }
    while(i<a.size()){
        ans[k++] = a[i++];
    }
    while(j<b.size()){
        ans[k++] = b[j++];
    }
    return ans;
}


Node* mergeBST(Node* root1, Node* root2){
    // step 1: store inorder
    vector<int> bst1,bs2;
    inorder(root1, bst1); 
    inorder(root2, bst2); 

    // step2: merge both sorted array
    vector<int> mergedArray = mergeArrays(bst1, bst2);

    // step3: used merged inorder array to build BST
    int s=0, e= mergeArray.size()-1;
    return inorderToBST(s,e, mergedArray);
}

// Approch 2: Convert given tree into sorted Linked List without uses extraSpace Now merge 2 Sorted Linked List , convert final sorted Linked list into BST

// T.C O(m+n)
// S.C O(h1 + h2)


void convertIntoSortedDLL(Node* root, Node* &head){
    // base case
    if(root == NULL){
        return ;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if(head != NULL)
        head -> left = root;

    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node* mergeLinkedList(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head->data < head2->data){
            if(head == NULL){
                head =head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else {
                tail -> right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
    }

    while(head2 != NULL){
                tail -> right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;    
    }
}

int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedLLToBST(Node* &head, int n){
    // base case 
    if(n <= 0 || head == NULL){
        return NULL;
    }

    Node* left = sortedLLToBST(head, n/2);

    Node* root = head;
    root->left = left;

    head = head->next;

    root->right = sortedLLToBST(head, n-n/2-1);
    return root;

}

Node* mergeBST(Node* root1, Node* root2){
    // step 1: Flatten a Linked list
    Node* head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;

    // step2: merge sorted Linked List
     Node* head = mergeLinkedList(head1,head2);

     // step: convert SLL into BST

     return sortedLLToBST(head, countNodes(head));

}