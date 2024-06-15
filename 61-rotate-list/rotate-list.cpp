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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head ;
        int count = 1 ;
        while(temp->next){
            count++;
            temp = temp->next ;
        }
        temp->next = head;
        cout << temp->next->val <<" ";
        ListNode* temp2 = head;
        ListNode* prev = head;

        k = k % count ;
        for(int i =0 ; i<count-k;i++){
            prev = temp2 ;
            temp2 = temp2->next;
        }

        prev->next = NULL;
        return temp2;
    }
};