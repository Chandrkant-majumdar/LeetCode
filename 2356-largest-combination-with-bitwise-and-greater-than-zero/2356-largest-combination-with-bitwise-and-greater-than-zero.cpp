class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> countPowers(24,0);
        for(int &candidate: candidates){
            for(int i=0;i<24;i++){
                if(candidate & (1<<i)){
                    countPowers[i]++;
                }
            }
        }
        int res=1;
        for(int &count:countPowers)res=max(res,count);
        return res;
    }
};