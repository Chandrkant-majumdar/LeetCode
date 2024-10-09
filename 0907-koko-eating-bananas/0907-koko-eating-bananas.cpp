class Solution {
public:
   long long f(vector<int>& p, int h){
   long long ans=0;
    for(int i=0;i<p.size();i++){
        ans+=ceil((double)p[i]/(double)h);
    }
    return ans;
   }
    int minEatingSpeed1(vector<int>& p, int h) {
        
        int maxi=INT_MIN;
        for(auto x:p){
            maxi=max(maxi,x);
        }
        for(int i=1;i<=maxi;i++){
            long long hour=f(p,i);
            if(hour<=(long long)h){
                return i;
            }
        }
         return -1;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        
        int maxi=INT_MIN;
        for(auto x:p){
            maxi=max(maxi,x);
        }
        int l=1,hi=maxi;
      
            while(l<=hi){
                int m=(l+hi)/2;
            long long hour=f(p,m);
            // if(hour==(long long)h){
            //     return m;
            // }
            if(hour<=(long long)h){
                hi=m-1;
            }else{
                l=m+1;
               
            }
        }
         return l;
    }
};