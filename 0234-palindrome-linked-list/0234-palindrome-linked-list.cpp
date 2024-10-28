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
    
    ListNode* rev(ListNode *head){
        ListNode *p=NULL,*cur=head,*front;
        while(cur!=nullptr){
            front=cur->next;
            cur->next=p;
            p=cur;
            cur=front;
            
        }
        return p;
    }
   
    bool isPalindrome(ListNode* head) {
      ListNode *slow=head,*fast=head,*t1;
      while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
      }
    //   cout<<slow->val<<" "<<slow->next->val<<endl;
      t1=rev(slow->next);
      slow->next=nullptr;
      slow=head;
      while(t1!=nullptr && slow!=nullptr ){
        if(t1->val!=slow->val) return false;
        t1=t1->next;
        slow=slow->next;
      }
            // cout<<t1->next->val<<endl;

       return true;
    }
    bool isPalindrome1(ListNode* head) {
        ListNode *t=head;
        stack<int>s;
        while(t!=nullptr){
            s.push(t->val);
            t=t->next;

        }
        t=head;
        while(t!=nullptr){
            if(t->val!=s.top()){
                return false;
            }
            s.pop();
            t=t->next;
        }
        return true;

    }
};