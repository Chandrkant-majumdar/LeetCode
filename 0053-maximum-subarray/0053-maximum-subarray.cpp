class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
         int sum=0;
        for(int i=0;i<n;i++){
            
            // for(int j=i;j<n;j++){
               
                // for(int k=i;k<=j;k++){
                    sum+=nums[i];
                     maxi=max(sum,maxi);
                    if(sum<0){
                        sum=0;
                    }
                // }
                
            // }
           

        }
        return maxi;
    }
};