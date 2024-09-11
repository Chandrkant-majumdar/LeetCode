class Solution {
public:
    int minBitFlips(int s, int g) {
        int ans=s^g;
        int cnt=0;
        while(ans>0){
            if(ans&1) cnt++;
            ans=ans>>1;
        }
        return cnt;
    }
};