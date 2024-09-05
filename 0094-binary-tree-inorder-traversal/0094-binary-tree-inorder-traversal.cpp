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

    void f(vector<int>&v,TreeNode*  root){
        if(root==nullptr) return;
       
        f(v,root->left);
         v.push_back(root->val);
         f(v,root->right);
    }
    
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int>ans;
        TreeNode *t=root;
        while(t!=nullptr){
            if(t->left==nullptr){
                
                ans.push_back(t->val);
                t=t->right;
            }else{
                TreeNode *prev=t->left;
                while(prev->right && prev->right!=t){
                    prev=prev->right;
                }

                if(prev->right==nullptr){
                    prev->right=t;
                    t=t->left;
                }else{
                    prev->right=nullptr;
                    ans.push_back(t->val);
                    t=t->right;
                }
            }
        }
        // f(ans,root);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>ans;
       TreeNode *cur=root;
       if(!root) return {};
       while(cur!=NULL){
        if(cur->left==NULL){
            ans.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode* prev=cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
               
            }
            
            if(prev->right==NULL){
                
                 prev->right=cur;
                 cur=cur->left;               

            }else{
                prev->right=NULL;
                ans.push_back(cur->val);

                cur=cur->right;
            }
           
        }
       }
       return ans;
    }
};