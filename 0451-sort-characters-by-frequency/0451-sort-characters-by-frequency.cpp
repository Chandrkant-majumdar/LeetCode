class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        sort(s.begin(),s.end(),[&](char x,char y){
            if(m[x]!=m[y]){
                return m[x]>m[y];
            }else{
                return x<y;
            }
        });
        return s;
    }
};