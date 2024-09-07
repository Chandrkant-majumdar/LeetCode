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
class BSTItr{

    public:
    stack<TreeNode *> s;
    bool rev=true;
    BSTItr(TreeNode *root,bool isRev){
        rev=isRev;
        pushAll(root);
    }
    void pushAll(TreeNode *root){
           while(root){
            s.push(root);
            if(rev){
                root=root->right;
            }else{
                root=root->left;
            }
           }
    }

    int next(){
        TreeNode *t=s.top();
        s.pop();
        if(rev){
            pushAll(t->left);
        }else{
            pushAll(t->right);
        }
        return t->val;
    }
    bool hasNext(){
        return !s.empty();
    }


};
class Solution {
public:

  //    Method 1
  /*
    void f(TreeNode *root,vector<int>&ans){
        if(!root) return;
        f(root->left,ans);
        ans.push_back(root->val);
        f(root->right,ans);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        f(root,ans);
        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]==k) return true;
            else if(ans[i]+ans[j]<k){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
    */
    //   Method 2

    /*------------------------------------------------------*/

     bool findTarget(TreeNode* root, int k) {

    if(!root) return false;

    BSTItr l(root,false);
    BSTItr r(root,true);

    int i=l.next();
    int j=r.next();
    
    while(i<j){
        int sum=(i+j);
        if(sum==k) return true;
        else if(sum<k){
            i=l.next();
            
        }else{
            j=r.next();
        }
    }
       
       return false;

     }

};