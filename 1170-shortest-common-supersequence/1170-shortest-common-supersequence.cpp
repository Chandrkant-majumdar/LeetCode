class Solution {
public:

     int f(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
        }
        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
     }
   
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = f(n, m, s1, s2, dp);

        // Debug print for dp table (optional)
        // for(auto x : dp){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }

        string s = "";
        int i = n , j = m ;
        
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                s += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                s += s1[i-1];
                i--;
            } else {
                s += s2[j-1];
                j--;
            }
        }

        while(i > 0) {
            s += s1[--i];
        }

        while(j > 0) {
            s += s2[--j];
        }

        reverse(s.begin(), s.end());
        return s;
    }
};
