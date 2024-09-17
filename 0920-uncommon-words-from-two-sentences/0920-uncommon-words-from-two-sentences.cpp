class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream t(s1);
        set<string>st1;
        string t1,t2;
        map<string,int>m;
        while(getline(t,t1,' ')){
            //   if(st1.find(t1)==st1.end())
            //    st1.insert(t1);
            //    else
            //    st1.erase(t1);
            m[t1]++;
        }
        // vector<string>ans;
        stringstream ss(s2);
        while(getline(ss,t2,' ')){
            m[t2]++;
            // if(st1.find(t2)!=st1.end()){
            //     st1.erase(t2);
            //     // ans.push_back(t2);
            // }else{
            //     st1.insert(t2);
            // }
        }
        vector<string>ans;
        for(auto x:m){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};