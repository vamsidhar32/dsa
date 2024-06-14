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
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* prev = node ;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next ;

            int temp2 = temp->val;
            temp->val = prev->val;
            prev->val = temp2;

            
        }
        prev->next = NULL ;
        delete(temp);
    }
};