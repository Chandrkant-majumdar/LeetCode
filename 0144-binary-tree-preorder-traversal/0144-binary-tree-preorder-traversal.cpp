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
    void f(vector<int>&v,TreeNode* root){
        if(root==nullptr) return;
        v.push_back(root->val);
        f(v,root->left);
                f(v,root->right);

    }
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int>ans;
        // f(ans,root);
        // return ans;
        if(!root) return ans;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode *t=s.top();
            ans.push_back(t->val);
            s.pop();
            if(t->right!=nullptr){
                s.push(t->right);
            }
            if(t->left!=nullptr){
                s.push(t->left);
            }
        }
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int>ans;
        TreeNode *cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
               TreeNode *prev=cur->left;
               while(prev->right!=NULL && prev->right!=cur){
                   prev=prev->right;
               }

               if(prev->right==NULL){
                  prev->right=cur;
                  ans.push_back(cur->val);
                  cur=cur->left;
               }
               else{
                prev->right=NULL;
                cur=cur->right;
               }




            }
        }
        return ans;
    }
};