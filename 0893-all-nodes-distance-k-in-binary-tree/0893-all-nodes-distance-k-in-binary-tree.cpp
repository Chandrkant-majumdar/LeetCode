/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mp(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&pt,TreeNode * Target){
             queue<TreeNode*>q;
             q.push(root);
             while(!q.empty()){
                TreeNode *cur=q.front();
                q.pop();
                if(cur->left){
                  pt[cur->left]=cur;
                  q.push(cur->left);
                }
                if(cur->right){
                     pt[cur->right]=cur;
                  q.push(cur->right);
                }
                
                
             }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>pt;
        mp(root,pt,target);
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        int cur_l=0;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(cur_l++==k) break;
            for(int i=0;i<size;i++){
                TreeNode * cur=q.front();
                q.pop();
                if(cur->left && !vis[cur->left]){
                      q.push(cur->left);
                      vis[cur->left]=true;
                }
                if(cur->right && !vis[cur->right]){
                      q.push(cur->right); 
                       vis[cur->right]=true;
                }
                if(pt[cur] && !vis[pt[cur]]){
                    q.push(pt[cur]);
                    vis[pt[cur]]=true;
                }
            }
        }

        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;

    }
};