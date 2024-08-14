class Solution {
public:
    bool cmp(vector<int> a,vector<int> b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        if(n<2){
            return intervals;
        }
        vector<vector<int>> ans;
        int b = intervals[0][0],e = intervals[0][1], i=0;
        vector<int> temp;
        while(i<n){
            temp.clear();
            while(intervals[i-1][1]>=intervals[i][0]){
                e = intervals[i][1];
                i++;
            }
            // if(i+1<n){
            //     b = intervals[i+1][0],e = intervals[i+1][1];
            // }
            temp.push_back(b),temp.push_back(e);
            ans.push_back(temp);
            b = intervals[i][0],e = intervals[i][1];
        }
        return ans;
    }
};
