class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        // cout<<num[n-1]-'0';
        string ans="";
        for(int i=n-1;i>=0;i--){
            int t=num[i]-'0';
            if(t%2!=0){
                ans=num.substr(0,i+1);
                break;
            }
        }
        return ans;
    }
};