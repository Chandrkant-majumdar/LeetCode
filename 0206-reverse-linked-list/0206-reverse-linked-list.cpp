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
    ListNode * f(ListNode *head){
        if(!head || head->next== nullptr) return head;

        ListNode *Nhead=f(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=nullptr;
        return Nhead;
    }
    ListNode* reverseList(ListNode* head) {
        return f(head);
    }
    ListNode* reverseList1(ListNode* head) {
        if(!head) return head;
        ListNode *prev=NULL,*cur=head;
        while(cur->next!=NULL){
            ListNode *front=cur->next;
            cur->next=prev;
            prev=cur;
            cur=front;
        }
        cur->next=prev;
        return cur;
    }
};