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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        if(head->next==nullptr && n==1) return nullptr;
        ListNode *t=head;
        while(t!=nullptr){
            size++;
            t=t->next;

        }
        // cout<<size<<endl;
        n=size-n-1;
        t=head;
        if(n<0) return head->next;
        while(n--){
            t=t->next;
            //  n--;
        }
        cout<<t->val<<endl;
        // 
        t->next=t->next->next;
        // cout<<n<<" "<<t->val<<endl;
        return  head;
        
    }
};