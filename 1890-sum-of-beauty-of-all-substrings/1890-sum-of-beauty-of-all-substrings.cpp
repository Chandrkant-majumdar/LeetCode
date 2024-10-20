class Solution {
public:
   int f(vector<int>&h){
        
        int maxi=INT_MIN,mini=INT_MAX;
        for(auto x:h){
            if(x!=0)
            maxi=max(x,maxi);
            if(x!=0)
            mini=min(x,mini);
        }
        return maxi-mini;
   }
    int beautySum(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
             string t="";
             vector<int>h(26,0);
            for(int j=i;j<n;j++){
               
                // for(int k=i;k<=j;k++){
                     t+=s[j];
                     h[s[j]-'a']++;
                // }
                //  int te=f(t);
                 ans+=f(h);
            }
        }
        return ans;

    }
};