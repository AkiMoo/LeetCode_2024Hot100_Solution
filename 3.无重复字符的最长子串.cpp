class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> counter;
        int ans = 0;
        int temp = 0,left = 0;
        if(n==1||n==0){
            return n;
        }
        for(int right = 0;right<n;right++){
            counter[s[right]]++;
            if(counter[s[right]]>1){
                ans = max(ans,temp);
                for(int j = left;j<right;j++){
                    if(s[j]==s[right]){
                        temp = right - left;
                        left = j+1;
                        counter[s[right]]--;
                        break;
                    }
                }
            }
            temp = right - left + 1;
            cout<<temp<<s[right]<<" ";
        }
        return max(ans,temp);
    }
};
