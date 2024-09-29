class Solution {
public:
    unordered_map<string,int> hash;
    bool find(string s, vector<string> wordDict){
        int i = 0;
        if(hash.find(s)!=hash.end()){
            return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(auto w : wordDict){
            hash[w]++;
        }
        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<i;j++){
                string temp = s.substr(j,i-j);
                if(find(temp,wordDict)&&dp[j]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        if(dp[n]==0){
            return false;
        }
        return true;
    }
};
