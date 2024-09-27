class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<2){
            return s;
        }
        int maxlen = 1,begin=0;
        //用dp[i][j]代表从i到j是否回文
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i =0 ;i<n;i++){
            dp[i][i] = 1;//每一个单个字母都是回文串
        }
        for(int len =2;len<=n;len++){//枚举长度
            for(int i=0;i<n;i++){//从第一个位置开始枚举
                int right = len + i - 1;
                if(right>=n){
                    break;
                }
                if(s[i]!=s[right]){
                    dp[i][right] = 0;
                }
                else{
                    if(right-i<2){
                        dp[i][right] = 1;//处理长度为2的短串
                    }
                    else{
                        dp[i][right] = dp[i+1][right-1];//两端相同，则取决于中间是否回文串
                    }
                }
                if(dp[i][right]&&right-i+1>maxlen){
                    maxlen = right-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};
