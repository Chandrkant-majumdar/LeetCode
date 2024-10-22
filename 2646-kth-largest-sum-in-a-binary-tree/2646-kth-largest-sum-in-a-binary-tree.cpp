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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>sum;
        queue<TreeNode *>q;
        q.push(root);
        // long long ans=0;
        while(!q.empty()){
            int size=q.size();
            long long te=0;
            for(int i=0;i<size;i++){
                    TreeNode *t=q.front();
                    q.pop();

                   te+=(t->val);
                   if(t->left){
                    q.push(t->left);
                   }
                   if(t->right){
                    q.push(t->right);
                   }
            }
           sum.push_back(te);
        }
        if(sum.size()<k) return -1;
        sort(sum.begin(),sum.end(),[](long long a,long long b){
            return a>b;
        });
        return sum[k-1];
    }
};