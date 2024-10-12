class Solution {
public:
    int f(vector<vector<int>>& ma,int mid,int n,int m){
        int maxi=INT_MIN,row=-1;
        for(int i=0;i<n;i++){
            if(maxi<ma[i][mid]){
                maxi=ma[i][mid];
                row=i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& ma) {
        int n=ma.size();
        int m=ma[0].size();
       
        int l=0,h=m-1;
        while(l<=h){
            int mid=(l+h)>>1;
            int r=f(ma,mid,n,m);
            int le=(mid-1<0)?-1:ma[r][mid-1];
            int ri=(mid+1>m-1)?-1:ma[r][mid+1];
            if(ma[r][mid]>le && ma[r][mid]>ri) return {r,mid};
            if(ma[r][mid]<le) h=mid-1;
            else
            l=mid+1;
        }






       return {-1};
    }
    
    vector<int> findPeakGrid1(vector<vector<int>>& ma) {
        int n=ma.size();
        int m=ma[0].size();
        int r[]={-1,+1,0,0};
        int c[]={0,0,-1,+1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool flag=true;
                for(int k=0;k<4;k++){
                    int nr=i+r[k];
                    int nc=j+c[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<m){
                        if(ma[i][j]<=ma[nr][nc]){
                            flag=false;
                        }
                    }
                    
                
                }
                if(flag) return{i,j};

            }
        }
 return {-1};
    }
   
};