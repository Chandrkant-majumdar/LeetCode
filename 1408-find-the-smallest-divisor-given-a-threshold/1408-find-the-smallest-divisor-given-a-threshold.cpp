class Solution {
public:
    int pos(vector<int>& a,int d, int th){
        int sum=0;
        for(auto x:a){
            sum+=ceil((double)x/(double)d);
        }
        return sum<=th;
    }
    int smallestDivisor1(vector<int>& a, int th) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto x:a){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        for(int i=1;i<=maxi;i++){
            if(pos(a,i,th)) return i;
        }

        return maxi;
    }
    int smallestDivisor(vector<int>& a, int th) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto x:a){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        int l=1,h=maxi;
        while(l<=h){
            int mid=(l+h)/2;
            if(pos(a,mid,th)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
       return l;
    }
};