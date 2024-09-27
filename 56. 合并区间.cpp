class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        if(n== 1){
            return intervals;
        }
        int i = 0;
        while(i<n-1){
            if(intervals[i][1]>=intervals[i+1][0]){
                if(intervals[i+1][1]<intervals[i][1]){
                    intervals[i+1][1] = intervals[i][1];
                }
                intervals[i+1][0] = intervals[i][0];
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        ans.push_back(intervals[i]);
        return ans;
    }
};
