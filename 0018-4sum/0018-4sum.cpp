class Solution {
public:
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                        // int sum=0;
                    for(int l=k+1;l<n;l++){
                    
                        // for(int m=k;m<=l;m++){
                        //      sum+=nums[m];
                        // }
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k]+nums[l];
                        if(sum==target){
                            vector<int>t({nums[i],nums[j],nums[k],nums[l]});
                            sort(t.begin(),t.end());
                           s.insert(t);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long>st;
                for(int k=j+1;k<n;k++){
                        // int sum=0;
                  
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        long long nt=target-sum;
                        if(st.find(nt)!=st.end()){
                            vector<int>t({nums[i],nums[j],nums[k],static_cast<int>(nt)});
                            sort(t.begin(),t.end());
                            s.insert(t);
                        }
                       st.insert(nums[k]);
                    }
                }
            }
             vector<vector<int>>ans(s.begin(),s.end());
        return ans;
        }
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long t1=nums[i]+nums[j];
                long long nt=target-t1;
                int l=j+1,r=n-1;
                while(l<r){
                    if(nums[l]+nums[r]==nt){
                        vector<int>t({nums[l],nums[r],nums[i],nums[j]});
                        sort(t.begin(),t.end());
                        s.insert(t);
                        l++;
                        r--;
                    }else if(nums[l]+nums[r]>nt){
                        r--;
                    }else{
                        l++;
                    }
                }
                }
            }
             vector<vector<int>>ans(s.begin(),s.end());
        return ans;
        }
};