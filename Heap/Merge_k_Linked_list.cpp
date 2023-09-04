// T.C O(n*klogk)
// S.C O(k)

class compare {
    public:
        bool operator()(Node<int>* a, Node<int>* b){
            return a->data > b->data;
        }
};



Node<int>* mergeKLists(vector<Node<int>*> &listArray){
    priority_queue<Node<int>*, vector<Node<int>*>, compare > minHeap;

    int k = listArray.size();

    // step1: Put all first K elemnet in heap

    if(k==0)
        return NULL;
    
    for(int i=0; i<k; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node<int>* head = NULL;
    Node<int>* tail = NULL;


    while(!minHeap.empty())
    {
        Node<int>* top = minHeap.top();
        minHeap.pop();

        if(head == NULL){
            // answer LL is empty
            head = top;
            tail = top;

            if(head -> next != NULL){
                minHeap.push(head->next);
            }
        }
        else {
            // insert at Linked List
            tail->next = top;
            tail = top;
            if(tail->next != NULL){
                minHeap.push(tail->next);
            }
        }
    }
    return head;
}