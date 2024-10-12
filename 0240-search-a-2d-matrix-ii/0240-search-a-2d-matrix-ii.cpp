class Solution {
public:

    bool searchMatrix(vector<vector<int>>& ma, int target) {
         int n=ma.size();
        int m=ma[0].size();
             int r=0,c=m-1;
             while(r<n && c>=0){
                if(ma[r][c]==target) return true;
                else if(ma[r][c]>target) c--;
                else r++;
             }

             return false;
        
    }









//============================================================//
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