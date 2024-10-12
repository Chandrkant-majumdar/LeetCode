class Solution {
public:


bool searchMatrix(vector<vector<int>>& ma, int target) {
        int n=ma.size();
        int m=ma[0].size();

       int l=0,h=n*m-1;
       while(l<=h){
        int mid=(l+h)>>1;
        int r=(mid/m);
        int c=(mid%m);
        if(ma[r][c]==target) return true;
        if(ma[r][c]>target) h=mid-1;
        else l=mid+1;
       }
       return false;
    }















//-----------------------------------------------------//
    bool check(vector<int>& ma, int target){
          int l=0,h=ma.size()-1;
          while(l<=h){
            int m=(l+h)>>1;
            if(ma[m]==target) return true;
            else if(ma[m]>target){
                h=m-1;
            }else{
                l=m+1;
            }
          }

        return false;
    }
    bool searchMatrix1(vector<vector<int>>& ma, int target) {
        int n=ma.size();
        int m=ma[0].size();

        for(auto x:ma){
            if(check(x,target)) return true;
        }




        return false;
    }
};