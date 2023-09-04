class Solution {
    public:
        Node* clone(Node* head){

            // step1: make a deep copy
            Node* iter =  head;
            Node* front = head;

            while(iter != NULL){
                front = iter->next;
                Node* copy = new Node(iter->val); // creating deep copy
                iter->next = copy;
                copy->next = front;
                iter = front;
            }

            // step2: copy a random pointer 

            iter = head;
            while(iter != NULL){
                if(iter->random != NULL){
                    iter->next->random = iter->random->next;
                }
                else iter->next->random = NULL;

                iter = iter->next->next;
            }

            // step3: seperate original list and deep copy list

            iter = head;
            Node* psedoHead = new Node(0);
            Node* copy = psedoHead;
            while(iter != NULL){
                front = iter->next->next;
                copy->next = iter->next;
                iter->next = front;
                copy = copy->next;
                iter = front;
            }

            return psedoHead->next;
            

        }
};