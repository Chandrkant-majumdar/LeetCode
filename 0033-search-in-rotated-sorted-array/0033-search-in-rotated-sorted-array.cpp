class Solution {
public:
    int search(vector<int>& a, int x) {
        int l=0,h=a.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(a[mid]==x) return mid;
            if(a[l]<=a[mid]){
                if(a[l]<=x && x<=a[mid]){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(a[mid]<=x && x<=a[h]){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};