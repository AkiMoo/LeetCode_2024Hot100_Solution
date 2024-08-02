class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n = nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]] = 1;
        }
        int ans = 1;
        for(int i=0;i<n;i++){
            int temp = nums[i];
            int thisround = 1;
            while(hash[temp++]>0){
                thisround = ++;
                //temp++;
            }
            ans = max(ans,thisround);
        }
        return ans;
    }
};
