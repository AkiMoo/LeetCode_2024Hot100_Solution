class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> ans;
        vector<int> hashCountS(26);
        vector<int> hashCountP(26);
        if(n<m){
            return ans;
        }
        for(int i = 0;i<m;i++){
            hashCountS[s[i]-'a']++;
            hashCountP[p[i]-'a']++;
        }
        if(hashCountP==hashCountS){
            ans.push_back(0);
        }
        for(int i = 0;i < n - m;i++){
            hashCountS[s[i]-'a']--;
            hashCountS[s[i+m]-'a']++;
            if(hashCountP==hashCountS){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
