class Solution {
public:
   bool static cmp(pair<int,int> a,pair<int,int> b){
      return a.first<b.first;
   }
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin())
        vector<pair<int,int>>t;
        for(int i=0;i<nums.size();i++){
            t.push_back({nums[i],i});
        }
        sort(t.begin(),t.end(),cmp);
        int i=0,j=nums.size()-1;
        while(i<j){
            if(t[i].first+t[j].first==target){
                return {t[i].second,t[j].second};
            }
            else if(t[i].first+t[j].first>target){
                j--;
            }else{
                i++;
            }
        }
        return {};
    }
};