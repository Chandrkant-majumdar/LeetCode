class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int maxi=INT_MIN,mini=p[0];
        for(int i=1;i<n;i++){
            int t=p[i]-mini;
            mini=min(p[i],mini);
            maxi=max(maxi,t);
        }

        if(maxi<0) return 0;
        return maxi;
    }
};