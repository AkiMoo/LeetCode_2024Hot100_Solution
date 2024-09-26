class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> s;
        s.push({temperatures[0],0});
        for(int i=1;i<n;i++){
            while(!s.empty()&&temperatures[i]>s.top().first){
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        return ans;
    }
};
