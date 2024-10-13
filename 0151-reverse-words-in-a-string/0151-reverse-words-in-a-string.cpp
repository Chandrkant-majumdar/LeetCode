class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0,j=0;
        int n=s.size();
       
        while(i<n){
            while(i<n && s[i]==' ') i++;
            string t="";
            while(i<n && s[i]!=' '){
                t+=s[i];
                i++;
            }
            if(ans.size()==0){
                ans=t;
            }else if(t.size()>0){
                ans=t+" "+ans;
            }
        }
        return ans;
    }
};