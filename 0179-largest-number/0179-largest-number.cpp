class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string>arr;
        for(auto x:nums){
            arr.push_back(to_string(x));
        }
        sort(arr.begin(),arr.end(),[](string &a,string &b){
            return (a+b)>(b+a);
        });
         if(arr[0]=="0") return "0";

        for(auto x:arr){
            s+=x;
        }
        return s;
    }
};