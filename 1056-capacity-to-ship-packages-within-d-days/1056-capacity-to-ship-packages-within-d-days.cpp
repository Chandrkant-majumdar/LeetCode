class Solution {
public:
   bool pos(vector<int>& w, int d,int c){
       int  load=0, day=1;
       for(auto x:w){
        if(load+x>c){
            day++;
            load=x;
        }else{
            load+=x;
        }        

       }
       return day<=d;
   }
    int shipWithinDays1(vector<int>& w, int d) {
        int l=1,r=0,maxi=INT_MIN;
        for(auto x:w){
            r+=x;
            maxi=max(maxi,x);
        }
        for(int i=maxi;i<=r;i++){
            if(pos(w,d,i)) return i;
        }
        return r;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l=1,r=0,maxi=INT_MIN;
        for(auto x:w){
            r+=x;
            maxi=max(maxi,x);
        }
        l=maxi;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(w,d,mid)) r=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
};