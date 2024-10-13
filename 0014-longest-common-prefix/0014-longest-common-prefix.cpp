class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(),s.end());
        int n=s[0].size(),m=s[s.size()-1].size();
        string t="";
        for(int i=0;i<min(n,m);i++){
            if(s[0][i]==s[s.size()-1][i]){
                t+=s[0][i];
            }else{
                break;
            }
        }
        return t;
    }
};