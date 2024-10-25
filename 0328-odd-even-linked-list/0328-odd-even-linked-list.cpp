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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *od=nullptr,*ev=nullptr,*t=head,*ans1,*ans2;
        if(!head) return head;
        int i=0;
        while(t!=nullptr){
            if(i%2!=0){
                if(!ev){
                    
                    ev=new ListNode(t->val);
                    ans1=ev;
                    
                }else{
                    ev->next=new ListNode(t->val);
                    ev=ev->next;
                }
            }else{
                if(!od){
                    od=new ListNode(t->val);
                    ans2=od;
                }else{
                    od->next=new ListNode(t->val);
                    od=od->next;
                }
            }
            t=t->next;
            i++;
        }

        head=ans2;
        od->next=ans1;
        return head;

    }
};