class Solution {
public:
    int singleNonDuplicate1(vector<int>& nums) {
        int ans=0;
        for(auto x:nums){
            ans=ans^x;

        }
        return ans;
    }
     int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        int l=0,h=a.size()-1;
        if(n==1) return a[0];
        // if(n==2) {
            if(a[0]!=a[1]) return a[0];
            if(a[n-2]!=a[n-1]) return a[n-1];
        
            
        // if()
        while(l<=h){
            int m=(l+h)/2;
            if(a[m-1]!=a[m] && a[m]!=a[m+1]) return a[m];
            
            if((m%2==0 && a[m]==a[m+1]) || (m%2!=0 && a[m]==a[m-1])){
                l=m+1;
            }else{
                h=m-1;
            }

        }
        return -1;
    }
};