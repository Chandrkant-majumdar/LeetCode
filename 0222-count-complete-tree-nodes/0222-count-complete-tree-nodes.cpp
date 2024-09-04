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

    // void f(TreeNode *root,int &cnt){
           
    //        if(!root) return;
           
    //        f(root->left,cnt);
    //        cnt++;
    //        f(root->right,cnt);
    //     //    return cnt;
    // }
    int f(TreeNode *root){
        if(!root) return 0;
        int l=lh(root);
        int r=rh(root);

        if(l==r){
            return (1<<l)-1;
        }

        
        return 1+f(root->left)+f(root->right);

    }
    int lh(TreeNode *root){
        // if(!root) return 0;
         int c=0;
        while(root){
            c++;
            root=root->left;
        }
        return c;

    }
    int rh(TreeNode *root){
        // if(!root) return 0;
         int c=0;
        while(root){
            c++;
            root=root->right;
        }
        return c;

    }
    int countNodes(TreeNode* root) {
        // if(!root) return 0;
        // int cnt=0;
     return f(root);
    //  return cnt;
        

    }
};