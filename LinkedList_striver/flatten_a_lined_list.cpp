class Solution {
    private:
        Node* mergeTwoLists(Node* a, Node* b){
            Node* temp = new Node(0);
            Node* res = temp;

            while(a != NULL && b != NULL){
                if(a->data < b->data){
                    temp->bottom = a;
                    temp = temp->bottom;
                    a = a->bottom;
                }
                else {
                    temp->bottom = b;
                    temp = temp->bottom;
                    b = b->bottom;
                }
            }

            // if element are remeaingin in any LL then simply copy them
            if(a) temp->bottom = a;
            else temp->bottom = b;
            
            return res->bottom;
        }

    public:
        Node* flatten(Node* root){
            if(root == NULL || root->next == NULL) return root;

            // recur for list on right
            root->next = flatten(root->next);

            // now merge
            root = mergeTwoLists(root, root->next);

            return root;
        }
};