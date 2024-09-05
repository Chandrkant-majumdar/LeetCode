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

    TreeNode* f(vector<int>&in ,int is,int ie,vector<int>&po,int ps,int pe, map<int,int>&m){
        if(is>ie || ps>pe) return nullptr;

        TreeNode *root=new TreeNode(po[pe]);
        int ir=m[root->val];
        int nl=ir-is;
        root->left=f(in,is,ir-1,po,ps,ps+nl-1,m);
        root->right=f(in,ir+1,ie,po,ps+nl,pe-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        map<int,int>m;
        for(int i=0;i<in.size();i++){
            m[in[i]]=i;

        }
        TreeNode* root=f(in,0,in.size()-1,po,0,po.size()-1,m);
        return root;
    }

};