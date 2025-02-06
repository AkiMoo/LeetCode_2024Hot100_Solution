class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int>& num, int cur)
    {
        if(cur == num.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(num[cur]);
        dfs(num,cur+1);
        temp.pop_back();
        dfs(num,cur+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};
