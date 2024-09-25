class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),ans=0;
        unordered_map<int,int> hashmap;//记录相同前序和的个数
        int prefix=0;
        hashmap[0] = 1;//输入存在“零”，使得前序和本身就是答案的解能够留下
        for(int i = 0;i<n;i++){
            prefix+=nums[i];
            if(hashmap.find(prefix-k)!=hashmap.end()){//此处代表找到了0-j之间的前序和和0-i之间的前序和之差为k
                ans += hashmap[prefix-k];
            }
            hashmap[prefix]++;
        }
        return ans;
    }
};
