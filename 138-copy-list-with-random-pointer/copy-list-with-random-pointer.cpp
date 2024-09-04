/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head ;
        Node* temp = head ;

        Node* dummy = new Node(-1);
        Node* prev = dummy ;

        unordered_map<Node* ,Node*> mpp;
        mpp[NULL] = NULL ;
        while(temp){
           Node* curr = new Node(temp->val);
           prev->next = curr ;
           prev = curr ;
           mpp[temp] = curr ;
           temp = temp->next ;
        }

        temp = head;

        while(temp){
            mpp[temp]->random = mpp[temp->random] ; 
            temp = temp->next ;
        }

        return dummy->next ;

    }
};