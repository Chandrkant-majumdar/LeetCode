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
    bool hasCycle(ListNode *head){
        ListNode *slow=head,*fast=head;
        if(!head) return false;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
    bool hasCycle1(ListNode *head) {
        set<ListNode *>s;
        if(!head) return false;
        while(head!=nullptr){
            if(s.find(head)!=s.end()) return true;
            s.insert(head);
            head=head->next;
        }
        return false;
    }
};