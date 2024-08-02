class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size()
        int ans = 0
        vector<vector<int>> dp(n,vector<int>(n));
        dp[0][0] = nums[0];
        for(int i = 0;i<n;i++){
            dp[i][i] = nums[i];
            for(int j = i+1;j<n;j++){
                dp[i][j] = dp[i][j-1] + nums[j];
                if(ans==dp[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
