vector<bool>isprime(int limit){
    vector<bool>is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
bool isincreasing(vector<int>&nums){
    int i=0;
    while(i<nums.size()-1){
        if(nums[i]>=nums[i+1]) return false;
        i+=1;
    }
    return true;
}
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int limit=1000;
        vector<bool> primes=isprime(limit);
        for(int i=nums.size()-1;i>0;i--){
            while(nums[i]<=nums[i-1]){
                int flag=0;
                for(int k=2;k<nums[i-1];k++){
                    if(primes[k]){
                        if((nums[i-1]-k)<nums[i])
                        {
                        nums[i-1]-=k;
                        flag=1;
                        break;
                        }
                    }
                }
                if (flag==0) break;
            }
        }
        return isincreasing(nums);
    }
};