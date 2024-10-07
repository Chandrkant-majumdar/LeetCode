class Solution {
public:
    int f(vector<int>&a,int x){
    int l=0,h=a.size()-1;
	int ans=-1;
	while(l<=h){
		int m=(l+h)/2;
        if(a[m]==x){
            ans=m;
            h=m-1;            
        }
		else if(a[m]<x){
			// ans=m;
			l=m+1;
		}else{
            // ans=m;
			h=m-1;
		}
	}
	return ans;
}
int c(vector<int>&a,int x){
	int l=0,h=a.size()-1;
	int ans=-1;
	while(l<=h){
		int m=(l+h)/2;
        if(a[m]==x){
          ans=m;
          l=m+1;
        }
		else if(a[m]>x){
			//  ans=m;
			h=m-1;
		}else{
			// h=m-1;
			l=m+1;
		}
	}
	return ans;
}
    vector<int> searchRange(vector<int>& nums, int x) {
        int fl=f(nums,x);
        int cl=c(nums,x);
        return {fl,cl};
    }
};