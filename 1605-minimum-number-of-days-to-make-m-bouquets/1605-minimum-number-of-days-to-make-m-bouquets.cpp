class Solution {
public:
    bool pos(vector<int>& bd, int m, int k,int d){
        int c=0,b=0;
        for(int i=0;i<bd.size();i++){
            if(d>=bd[i]){
                c++;
            }else{
                b+=(c/k);
                c=0;
            }
        }
        b+=(c/k);
        if(b>=m) return true;
        return false;
    }
    int minDays1(vector<int>& bd, int m, int k) {
        int mini=INT_MAX,maxi=INT_MIN;
        int n=bd.size();
        if(m*k>n) return -1;
        for(auto x:bd){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        for(int i=mini;i<=maxi;i++){
           if(pos(bd,m,k,i)) return i;
        }
        return maxi;
    }
    int minDays(vector<int>& bd, int m, int k) {
        long long mini=LLONG_MAX,maxi=LLONG_MIN;
        int n=bd.size();
        if((long long)m*k>n) return -1;
        for(auto x:bd){
            mini=min(mini,(long long)x);
            maxi=max(maxi,(long long)x);
        }
        int l=mini,h=maxi;
        while(l<=h){
            int mid=(l+h)/2;
            if(pos(bd,m,k,mid)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};