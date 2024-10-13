class Solution {
public:
    int maxDepth(string s) {
        int ans=INT_MIN;
        stack<char>st;
        for(auto x:s){
            if(x=='('){
                st.push(x);
                int sz=st.size();
                ans=max(ans,sz);
            }else if(x==')'){
                st.pop();
            }
        }
        return (ans==INT_MIN)?0:ans;
    }
};