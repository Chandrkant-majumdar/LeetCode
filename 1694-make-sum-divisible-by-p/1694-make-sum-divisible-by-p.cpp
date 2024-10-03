class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
      map<long long,vector<long long>>mp;
      long long n = nums.size();
      long long ans = n;
      long long tot = 0;
      for(auto i : nums){
        tot+=i;
      }
      long long R = tot%p;
       if (R == 0) return 0;
      vector<long long>pref(n);
      pref[0] = nums[0];
      for(long long i =1 ; i < n ; i++){
         pref[i] = pref[i-1];
         pref[i] = pref[i]+nums[i];
      }  
      mp[0].push_back(-1);
    
      set<long long>st;
        st.insert(0);
      for(long long i = 0 ; i < n ; i++){
        long long cur = pref[i]%p;
        long long target = ((cur  - R)+ p)%p;
        if(st.find(target)!=st.end()){
                long long j = mp[target].back();
                long long f = j+1;
            ans = min ( ans , i - f +1);
            
        }
        mp[cur].push_back(i);
        st.insert(cur);
      }
      return (ans == n)?-1:ans;
    }
};