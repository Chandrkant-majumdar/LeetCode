class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(auto c:s){
            if((c>='a' && c<='z') || (c>='0' && c<='9')) s1+=c;
            else if(c>='A' && c<='Z') s1+=(c-'A')+'a';
        }
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};