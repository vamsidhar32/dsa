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
private:
    ListNode* reversee(ListNode* temp){
        ListNode* prev = NULL ;
        while(temp ){
            ListNode* front = temp->next ;
            temp->next = prev;
            prev = temp ;
            temp = front ;
        }
        return prev ;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head ->next == NULL){
            return true ;
        }
        ListNode* temp = head ;
        ListNode* fast = head ;
        ListNode* slow = head ;
        fast = fast->next->next ;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = reversee(slow->next);

        while(newhead){
            if(newhead->val != temp->val){
                return false;
            }
            newhead = newhead->next ;
            temp = temp->next ;
        }
        return true ;
    }
};