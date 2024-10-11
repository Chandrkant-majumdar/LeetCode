class Solution {
public:
     
    int pos(vector<int>& nums, int k,int th){
        int c=1,sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum+nums[i]<=th){
                  sum=sum+nums[i];
            }else{
                c++;
                sum=nums[i];
            }
        }
        return c;
    }
        int splitArray(vector<int>& nums, int k) {
        int l=INT_MIN,h=0;
        for(auto x:nums){
            l=max(l,x);
            h+=x;
        }
        if(k>nums.size()) return -1;
        while(l<=h){
            int m=(l+h)/2;
            int par=pos(nums,k,m);
            if(par>k){
                l=m+1;
            }else{
                h=m-1;
            }
        }

        return l;
    }
    int splitArray1(vector<int>& nums, int k) {
        int l=INT_MIN,h=0;
        for(auto x:nums){
            l=max(l,x);
            h+=x;
        }
        if(k>nums.size()) return -1;
        for(int i=l;i<=h;i++){
            int par=pos(nums,k,i);
            if(par<=k) return i;

        }
        return -1;
    }
};