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
int h(TreeNode *root){
        if(!root) return 0;
        int lh=h(root->left);
        if(lh==-1) return -1;
        int rh=h(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        return h(root)!=-1;

       
    }


//------------------------------------------------//
    int h1(TreeNode *root){
        if(!root) return 0;
        int lh=h(root->left);
        int rh=h(root->right);
        return 1+max(lh,rh);
    }
    bool isBalanced1(TreeNode* root) {
        if(!root) return true;
        int lh=h(root->left);
        int rh=h(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;

        return false;
    }
};