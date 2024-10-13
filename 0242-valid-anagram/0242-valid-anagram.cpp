class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int>c(26,0);
        for(auto x:s){
            c[x-'a']++;
        }
        for(auto x:t){
            c[x-'a']--;
            if((c[x-'a'])<0) return false;
        }
        return true;
    }
};