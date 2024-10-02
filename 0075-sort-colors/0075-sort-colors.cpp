class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     vector<int>a(3,0);
    //     for(auto x:nums){
    //         a[x]++;
    //     }
    //     for(int i=0;i<a[0];i++){
    //         nums[i]=0;
    //     }
    //     for(int i=a[0];i<a[0]+a[1];i++){
    //         nums[i]=1;
    //     }
    //     for(int i=a[0]+a[1];i<a[0]+a[1]+a[2];i++){
    //         nums[i]=2;
    //     }
    // }
        void sortColors(vector<int>& nums) {
            int l=0,m=0,h=nums.size()-1;
            while(m<=h){
                if(nums[m]==0){
                    swap(nums[l],nums[m]);
                    l++;
                    m++;

                }
                else if(nums[m]==1) m++;
                else{
                    swap(nums[m],nums[h]);
                    // m++;
                    h--;
                }
            }

       }
};