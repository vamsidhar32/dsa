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
        ListNode* temp = node ;
        ListNode* prev = node ;

        while(temp->next){
            prev = temp ;
            temp = temp->next ;


            int value = temp->val ;
            temp->val = prev->val;
            prev->val = value ;
        }

        prev->next = NULL ;
        delete(temp);

    }
};