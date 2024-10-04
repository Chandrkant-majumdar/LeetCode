class Solution {
public:
    vector<int> majorityElement1(vector<int>& nums) {
        // vector<int>ans;
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
                 int c=0;
            for(int j=i;j<n;j++){
                  if(nums[i]==nums[j]){
                    c++;
                  }
            }
            if(c>floor(n/3)){
                s.insert(nums[i]);
            }
        }
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int e1,e2;
        int n=nums.size();
        for(auto x:nums){
            if(c1==0 && x!=e2){
                e1=x;
                c1++;
            }else if(c2==0 && x!=e1){
                e2=x;
                c2++;
            }
            else if(x==e1)c1++;
            else if(x==e2)c2++;
            else{
                c1--;
                c2--;
            }
        }
       c1=0;
       c2=0;
       for(auto x:nums){
        if(x==e1) c1++;
        if(x==e2) c2++;
       }
       set<int>s;
       
       if(c1>(n/3))s.insert(e1);
       if(c2>(n/3))s.insert(e2);
       vector<int>ans(s.begin(),s.end());
        return ans;
    }
};