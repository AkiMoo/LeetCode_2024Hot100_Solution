class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> hash;
        for(int i = 0;i<n;i++){
            if(hash[target-nums[i]]>0){
                if(hash[target-nums[i]]-1!=i){
                    ans.push_back(hash[target-nums[i]]-1),ans.push_back(i);
                    return ans;
                }
            }
            hash[nums[i]] = i+1;
        }

        ans.push_back(0);
        ans.push_back(1);
        return ans;
    }
};
