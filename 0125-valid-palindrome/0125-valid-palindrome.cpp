class Solution {
public:
    bool isPalindrome(string s) {
        string r="",t="";
        // cout<<int('A')<<int('a');
        for(auto c:s){
            if(isalnum(c))
            t+=tolower(c); 
        }
        r=t;
        
        reverse(r.begin(),r.end());
        cout<<r<<" "<<t;
        return t==r;
    }
};