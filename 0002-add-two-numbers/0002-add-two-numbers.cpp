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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode=new ListNode(-1);
        ListNode* cur=dummyNode;
        int carry=0;
        while(l1 || l2){
            int sum=carry;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            carry=sum/10;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry){
            ListNode *t=new ListNode(carry);
           cur->next=t;
            // return t;
        }
        return dummyNode->next;
    }
};