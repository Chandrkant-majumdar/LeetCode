class Solution {
public:
    int findKthPositive1(vector<int>& arr, int k) {
        
        for(auto x:arr){
            if(x<=k){
                k++;
            }
            else{
                break;
            }
        }
        return k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        
       int l=0,h=arr.size()-1;
       while(l<=h){
        int m=(l+h)/2;
        int mis=arr[m]-(m+1);
        if(mis>=k){
            h=m-1;
        }else{
            l=m+1;
        }
       }
       //h+1+k
       return l+k;
    }

};