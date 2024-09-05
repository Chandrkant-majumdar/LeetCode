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
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        map<int,int>m;
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;
        }
        TreeNode *root=f(pr,0,pr.size()-1,in,0,in.size()-1,m);
        return root;
    }
    TreeNode* f(vector<int>&pr,int ps,int pe,vector<int>&in,int is,int ie,map<int,int>&m){
        if(ps>pe || is>ie) return NULL;

        TreeNode *root=new TreeNode(pr[ps]);
        int t=m[root->val];
        int nl=t-is;
        root->left=f(pr,ps+1,ps+nl,in,is,t-1,m);
        root->right=f(pr,ps+nl+1,pe,in,t+1,ie,m);
        return root;
    }
};