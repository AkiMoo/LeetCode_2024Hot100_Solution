class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int k = n-1;
            for(int j = i+1;j<k;j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                while(nums[i]+nums[j]+nums[k]>0&&j<k){
                    k--;
                }
                if(j==k){
                    break;
                }
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                }
                
            }
        }
        return ans;
    }
};
