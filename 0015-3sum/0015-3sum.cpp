class Solution {
public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 for(int k=j+1;k<n;k++){
                   
                    if(nums[i]+nums[j]+nums[k]==0){                        
                      vector<int> t({nums[i],nums[j],nums[k]});
                      sort(t.begin(),t.end());
                      s.insert(t);
                     }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int target=-1*(nums[i]);
            int l=i+1,r=n-1;
            while(l<r){
                   if(nums[l]+nums[r]==target){
                     vector<int>t({nums[i],nums[l],nums[r]});
                     s.insert(t);
                    //  ans.push_back({nums[i],nums[l],nums[r]});
                     l++,r--;
                   }
                   else if(nums[l]+nums[r]>target){
                    r--;
                   }else{
                    l++;
                   }
              }
            
            }
        
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};