class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hash(26);
        vector<int> ans;
        int n = s.length();
        for(int i=0;i<n;i++){
            hash[s[i]-'a'] = i;
        }
        int start_mark = hash[s[0]-'a'],count_mark = 0;
        for(int i=0;i<n;i++){
            if(i>=start_mark){
                ans.push_back(i-count_mark+1);
                if(i+1<n){
                    start_mark = hash[s[i+1]-'a'];
                    count_mark = i+1;
                }
            }
            else{
                start_mark = max(start_mark,hash[s[i]-'a']);
            }
        }
        return ans;
    }
};
