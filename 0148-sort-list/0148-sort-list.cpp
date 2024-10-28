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
    ListNode* sortList(ListNode* head) {
        vector<int>ans;
        ListNode *t=head;
        while(t!=nullptr){
            ans.push_back(t->val);
            t=t->next;
        }
        sort(ans.begin(),ans.end());
        t=head;
        int i=0;
        while(t!=nullptr){
            t->val=(ans[i++]);
            t=t->next;
        }
        return head;
        
    }
};