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
   bool f(TreeNode *root,long long mini,long long maxi){
    if(!root) return true;

    if(root->val>=maxi || root->val<=mini) return false;

    return f(root->left,mini,root->val) && f(root->right,root->val,maxi); 
    
   }
    void f1(TreeNode *root,vector<int>&ans){
          if(!root) return ;
          f1(root->left,ans);
          ans.push_back(root->val);
          f1(root->right,ans);

    }

    bool f3(TreeNode* root,long long mini,long long maxi){
        if(!root) return true;
        if(root->val<=mini || root->val>=maxi) return false;
        
        return f3(root->left,mini,root->val)&& f3(root->right,root->val,maxi);
    }
    
    bool isValidBST(TreeNode* root) {
        // return f(root,LLONG_MIN,LLONG_MAX);
        //-------------------------------//
        /*
        vector<int>ans;
        f1(root,ans);
        vector<int>t(ans.begin(),ans.end());
        sort(t.begin(),t.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=t[i] ) return false;
            if(i>0 && ans[i]==ans[i-1]) return false;
        }
   
        return true;
        */

        //----------------------------------------//

        return f3(root,LLONG_MIN,LLONG_MAX);


    }
};