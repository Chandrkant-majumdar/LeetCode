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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*>q;
        q.push(root);
        bool left=false;
        vector<vector<int>> ans;
        while(!q.empty()){
            int size=q.size();
            vector<int>t;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
                if(left){
                    t.insert(t.begin(),node->val);
                }else{
                    t.push_back(node->val);
                }              

            }
            left=(!left);
            ans.push_back(t);
        }

        return ans;
    }
};