class Solution {
public:
    int findPeakElement1(vector<int>& a) {
        int n=a.size();
        if(n==1) return 0;
        if(a[0]>a[1]) return 0;
        if(a[n-1]>a[n-2]) return n-1;
        for(int i=1;i<=n-2;i++){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                return i;
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        if(n==1) return 0;
        if(a[0]>a[1]) return 0;
        if(a[n-1]>a[n-2]) return n-1;
       int l=1,h=n-2;
       while(l<=h){
        int m=(l+h)/2;
        if(a[m]>a[m-1] && a[m]>a[m+1]){
            return m;
        }
        if(a[m-1]<a[m]){
            l=m+1;
        }else{
            h=m-1;
        }
       }

       return -1;
    }
};