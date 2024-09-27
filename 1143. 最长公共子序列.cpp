class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(text1[i]==text2[j]){
                    if(i==0||j==0){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                }
                else{
                    if(i>0&&j>0){
                        dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                    }
                    else if(i==0&&j>0){
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(j==0&&i>0){
                        dp[i][j] = dp[i-1][j];
                    }
                }
                ans = max(dp[i][j],ans);
            }
        }
        return ans;
    }
};
