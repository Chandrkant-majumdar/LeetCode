class Solution {
public:
    bool isPalindrome(string s) {
        string r="",t="";
        // cout<<int('A')<<int('a');
        for(auto c:s){
            if(isalpha(c) || isdigit(c))
            t+=tolower(c); 
        }
        r=t;
        
        reverse(r.begin(),r.end());
        cout<<r<<" "<<t;
        return t==r;
    }
};