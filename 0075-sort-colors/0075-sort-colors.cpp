class Solution {
public:
 void sortColors(vector<int>& nums) {
    int s=0,m=0,l=nums.size()-1;
    while(m<=l){
        if(nums[m]==1) m++;
        else if(nums[m]==0){
            swap(nums[s++],nums[m++]);
        }else{
            swap(nums[m],nums[l--]);
        }
    }

 }
    void sortColors1(vector<int>& nums) {
        int z=0,o=0,t=0;
         for(auto x:nums){
            if(x==0) z++;
            else if(x==1) o++;
            else t++;
         }
         for(int i=0;i<z;i++){
            nums[i]=0;
         }
         for(int i=z;i<z+o;i++){
            nums[i]=1;
         }
         for(int i=o+z;i<o+z+t;i++){
            nums[i]=2;
         }
    }
};