class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           vector<int>t(n+m);
        //    if(n==0 || m==0) return;
           int i=0,r=0,ind=0;
           while(i<m && r<n){
              if(nums1[i]>nums2[r]){
                t[ind]=nums2[r];
                ind++,r++;
              }else{
                t[ind]=nums1[i];
                i++,ind++;
              }
           }
           while(i<m){
            t[ind++]=nums1[i++];
           }
           while(r<n){
            t[ind++]=nums2[r++];

           }
           for(int i=0;i<n+m;i++){
             nums1[i]=t[i];
            // else
            // nums[i]=t[]
           }
        
    }
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           int l=m-1;
           int r=0;
        //    while()
           while(l>=0 && r<n){
            if(nums1[l]>nums2[r]){
                swap(nums1[l],nums2[r]);
                l--,r++;
            }else{
                break;
            }
           }
           sort(nums1.begin(),nums1.begin()+m);
           sort(nums2.begin(),nums2.end());
           for(int i=m;i<n+m;i++){
            nums1[i]=nums2[i-m];
           }
    }
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
          int len=(m+n);
        //   int l=0;
          int gap=(len/2)+(len%2);
          while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                if(left<n && right>=n){
                if(nums1[left]>nums2[right-n])
                    swap(nums1[left],nums2[right-n]);
                }
                else if(left>=n && right>=n){
                    if(nums2[left-n]>nums2[right-n])
                    swap(nums2[left-n],nums2[right-n]);
                }
                else{
                    if(nums1[left]>nums1[right])
                    swap(nums1[left],nums1[right]);
                }
                left++,right++;
            }
             if(gap==1) break;
            gap=(gap/2)+(gap%2);
            

            
          }
          for(int i=0;i<m;i++){
            nums1[n+i]=nums2[i];
          }

    }
};