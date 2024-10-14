class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto x:nums){
            pq.push(x);
        }
        long long sum=0;
        while(!pq.empty() && k--){
            sum+=pq.top();
            int t=pq.top();
            pq.pop();
            pq.push(ceil(((double)t/(double)3)));

        }
        return sum;
    }
};