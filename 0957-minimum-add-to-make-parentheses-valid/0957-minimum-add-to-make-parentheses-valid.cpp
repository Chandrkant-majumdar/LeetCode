class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans=0;
        for(auto x:s){
            if(x=='('){
                st.push(x);
            }else if(!st.empty() && x==')'){
                st.pop();
            }else{
                ans++;
            }
        }
        return ans+st.size();
    }
};