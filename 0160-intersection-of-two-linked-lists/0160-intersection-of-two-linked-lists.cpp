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
    int getDif(ListNode *h1,ListNode *h2){
        int l1=0,l2=0;
        while(h1 || h2){
            if(h1){
                l1++;
                h1=h1->next;
            }
            if(h2){
                l2++;
                h2=h2->next;
            }
        }

        return l1-l2;
    }
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
            int d=getDif(h1,h2);
            if(d<0){
                while(d++){
                    h2=h2->next;
                }
            }else{
                while(d--){
                    h1=h1->next;
                }
            }
            while(h1){
                if(h1==h2) return h1;
                h1=h1->next;
                h2=h2->next;
            }

            return nullptr;
      
    }
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        set<ListNode *> s;
        ListNode *t1=headA,*t2=headB;
        while(t1){
            s.insert(t1);
            t1=t1->next;
        }
        while(t2){
            if(s.find(t2)!=s.end()){
                return t2;
            }
            t2=t2->next;
        }
        return nullptr;
    }
};