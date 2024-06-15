class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int flag1 = 0,flag2=0 ;
        while (temp1 != temp2) {
            

            if(temp1 == NULL&& flag1 == 0) {temp1 = headB; flag1 =1;continue;} 
            
            
            if(temp2 == NULL && flag2 ==0) {temp2 = headA; flag2 = 1; continue;}

            temp2 = temp2->next;
            temp1 = temp1->next;
        }

        return temp1;
    }
};
