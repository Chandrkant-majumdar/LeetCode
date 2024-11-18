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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>m;
        vector<vector<int>>ans;
        while(!q.empty()){
            auto t=q.front();
            TreeNode *node=t.first;
            int y=t.second.first;
            int x=t.second.second;
            q.pop();
            if(node->left){
                q.push({node->left,{y-1,x+1}});
            }
            if(node->right){
                 q.push({node->right,{y+1,x+1}});
            }
            m[y][x].insert(node->val);
           
        }
        for(auto x:m){
            // sort(x.second.begin(),x.second.end());
            auto t=x.second;
            vector<int>te;
           for(auto y:t){
            //   cout<<y.first<<" "<<y.second;
            te.insert(te.end(),y.second.begin(),y.second.end());

           }

              ans.push_back(te);
        }
        return ans;
    }
};