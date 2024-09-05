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
    TreeNode *prev=NULL;
    void f(TreeNode *root){
        if(!root) return;
        f(root->right);
        f(root->left);

        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    void flatten1(TreeNode* root) {
        // f(root);
        if(!root) return;

        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur=s.top();
            s.pop();
            if(cur->right){
                s.push(cur->right);
            }
            if(cur->left){
                s.push(cur->left);
            }
            if(!s.empty()){
                cur->right=s.top();
            }
            cur->left=NULL;
        }
         
         }
         void flatten(TreeNode* root){
            if(!root) return;
             TreeNode *cur=root;
             while(cur!=NULL){
                if(cur->left){
                    TreeNode *prev=cur->left;
                    while(prev->right){
                        prev=prev->right;
                    }
                    prev->right=cur->right;
                    cur->right=cur->left;
                    cur->left=NULL;
                }
                cur=cur->right;
             }
         }
    
};