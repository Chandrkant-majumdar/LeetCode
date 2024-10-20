class Solution {
public:
    char f(char op,vector<char>&li){
        if(op=='!') return (li[0]=='f')?'t':'f';
        else if(op=='&'){
            for(auto x:li){
               if(x=='f') return 'f';
            }
            return 't';
        }
        else if(op=='|'){
            for(auto x:li){
               if(x=='t') return 't';
            }
            return 'f';
        }
        return 'f';
    }
    bool parseBoolExpr(string s) {
        
        stack<char>st;
        for(auto x:s){
            if(x==')'){
                vector<char>li;
                while(st.top()!='('){
                    li.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                char t=f(op,li);
                st.push(t);
            }
            else if(x!=','){
                st.push(x);
            }
        }

        return (st.top()=='t')?true:false;
    }
};