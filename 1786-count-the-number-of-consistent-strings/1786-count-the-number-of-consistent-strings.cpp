class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) {
       
       int ans=0;
       for(auto x:w){
        bool flag=true;
        for(auto y:x ){
            if(find(a.begin(),a.end(),y)==a.end()){
                flag=false;
            }
        }
        if(flag) ans++;
       }
       return ans;
    }
    
       
      
};