class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<double> dp1(n+1),dp2(n+1);
        dp1[0] = nums[0];
        dp2[0] = nums[0];
        double ans = dp1[0];
        for(int i =1;i<n;i++){
            dp1[i] = max(max(static_cast<double>(nums[i]),dp2[i-1]*nums[i]),dp1[i-1]*nums[i]);
            dp2[i] = min(min(static_cast<double>(nums[i]),dp1[i-1]*nums[i]),dp2[i-1]*nums[i]);
            ans = max(dp1[i],ans);
        }
        return ans;
    }
};
