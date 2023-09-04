#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node* next;
};

// Creating a new Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

map<int,bool> visited;

/* Function to remove duplicates from a
   unsorted linked list */
Node* removeDuplicates( Node* &head)
{
     // If empty LL
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    visited[curr->data] = true;

    while(curr!=NULL && curr->next != NULL){
        if(curr->next != NULL && visited[curr->next->data] == true){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;

            curr->next = next_next;
            delete(nodeToDelete);
            // cout<<curr->next->data<<endl;
        }
        else  // Not equal
        {
        //    cout<<"2"<<endl;
        // cout<<"Hello ";
           curr = curr->next;
           visited[curr->data] = true;
        }
    // cout<<endl;
    }

return head;

}



/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Driver code
int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    Node *head = newNode(12);

    head->next = newNode(11);
    head->next->next = newNode(12);
    head->next->next->next = newNode(21);
    head->next->next->next->next = newNode(41);
    head->next->next->next->next->next = newNode(43);
    head->next->next->next->next->next->next = newNode(21);

    cout << "Linked list before removing duplicates " << endl;
    printList(head);

   Node* ans = removeDuplicates(head);

//    for(auto it : visited){
//     cout<<it.first<<" "<<it.second<<endl;
//    }

        cout << "Linked list after removing duplicates " << endl;
    printList(ans);

    return 0;
}