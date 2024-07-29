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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != tempB) {
            tempA = (tempA == nullptr) ? headB : tempA->next;
            tempB = (tempB == nullptr) ? headA : tempB->next;
        }

        return tempA; // tempA and tempB are either both nullptr (no intersection) or both point to the intersection node.
    }
};
