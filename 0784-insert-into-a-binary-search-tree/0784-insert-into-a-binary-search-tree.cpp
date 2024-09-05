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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *cur=root;
        TreeNode *t=new TreeNode(val);
        if(!root) return t;
        while(cur){
            if(val>cur->val){
                if(cur->right)
                cur=cur->right;
                else{
                   cur->right=t;
                   break;
                }
                
            }else{
                if(cur->left)
                cur=cur->left;
                else{
                    cur->left=t;
                    break;
                }
            }
        }
       return root; // if()
    }
};