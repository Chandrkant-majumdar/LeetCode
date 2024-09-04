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

    void f(TreeNode *root,int &cnt){
           
           if(!root) return;
           
           f(root->left,cnt);
           cnt++;
           f(root->right,cnt);
        //    return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt=0;
     f(root,cnt);
     return cnt;
        

    }
};