/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head ;
        ListNode* prev = NULL;
        while(temp){
            ListNode* var = temp ;
            temp = temp->next ;
            var->next = prev ;
            prev = var ;
        }

        return prev;
    }
};