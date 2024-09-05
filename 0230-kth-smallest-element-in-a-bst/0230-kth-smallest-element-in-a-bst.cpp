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
    // int f()
    void f1(TreeNode* root,int &c,int &k,int &ans){
           if(!root) return ;
           f1(root->left,c,k,ans);
           c++;
           if(c==k) ans=root->val;
           f1(root->right,c,k,ans);
    }
    void f2(TreeNode* root,vector<int>&ans){
        if(!root) return ;

        f2(root->left,ans);
        ans.push_back(root->val);
        f2(root->right,ans);
    }

    void f(TreeNode *root,int &c,int &t,int &k){
        if(!root) return;

        f(root->left,c,t,k);
        c++;
        if(c==k){
             t=root->val;
             return;
        }
        f(root->right,c,t,k);
    }

    int kthSmallest(TreeNode* root, int k) {

        vector<int>ans;

          int c=0,t;

         f(root,c,t,k);

         return t;

        
    }
};