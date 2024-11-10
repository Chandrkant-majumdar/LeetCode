class Solution {
public:
int maxProfit(vector<int>& p) {
        int ans=0;
        int n=p.size();
        int buy=1e9;
        for(int i=0;i<n;i++){
            buy=min(buy,p[i]);
            ans=max(ans,p[i]-buy);
        }
       
        return ans;
    }
    int maxProfit1(vector<int>& p) {
        int ans=0;
        int n=p.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,p[j]-p[i]);
            }
        }
        return ans;
    }
};