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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a set for O(1) average time complexity lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        ListNode dummy(0);  // Dummy node to handle edge cases more easily
        dummy.next = head;
        ListNode *prev = &dummy;

        while (prev->next != nullptr) {
            if (numSet.find(prev->next->val) != numSet.end()) {
                ListNode* temp = prev->next;
                prev->next = prev->next->next;
                delete temp;  // Free the memory of the removed node
            } else {
                prev = prev->next;
            }
        }

        return dummy.next;
    }
};