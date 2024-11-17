/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
       TreeNode *cur=root;
       while(cur){
        if(!cur->left){
            ans.push_back(cur->val);
            cur=cur->right;
        }else{
            TreeNode *t=cur->left;
            while(t->right && t->right!=cur){
                t=t->right;
            }
            if(!t->right){
                t->right=cur;
                cur=cur->left;
            }else{
                t->right=nullptr;
                ans.push_back(cur->val);
                
                cur=cur->right;
            }
        }
       }
        return ans;
    }
     void helper(TreeNode* root,vector<int>&ans){
        if(!root) return;
        helper(root->left,ans);
        ans.push_back(root->val);
         helper(root->right,ans);

     }
    vector<int> inorderTraversal1(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        helper(root,ans);
        return ans;
    }
};