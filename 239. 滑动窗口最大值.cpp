class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> priorityq;
        int n = nums.size();
        for(int i=0;i<k;i++){
            priorityq[nums[i]]++;
        }
        vector<int> ans;
        ans.push_back(priorityq.rbegin()->first);
        for(int i = k;i<n;i++){
            priorityq[nums[i-k]]--;
            if(priorityq[nums[i-k]]==0){
                priorityq.erase(nums[i-k]);
            }
            priorityq[nums[i]]++;
            ans.push_back(priorityq.rbegin()->first);
        }
        return ans;
    }
};
