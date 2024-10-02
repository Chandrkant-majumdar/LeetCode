class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0;
        int n=p.size();
        int mini=p[0];
        int maxi=0;
        for(int i=1;i<p.size();i++){
            maxi=max(maxi,p[i]-mini);
           mini=min(mini,p[i]);
        }
        return maxi;
    }
};