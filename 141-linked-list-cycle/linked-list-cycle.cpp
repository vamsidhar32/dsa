/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false ;
        }
        unordered_set<ListNode*>set;
        ListNode* temp = head ;
        while(temp){
            if(set.find(temp) == set.end()){
                set.insert(temp);
            }
            else return temp; 
            temp = temp->next ;
        }
        return false ;
    }

};