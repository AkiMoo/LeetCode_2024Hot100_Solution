class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.length();
        stack<int> num;
        queue<char> alp;
        int i = 0;
        while(i<n){
            if(s[i]<='9'&&s[i]>='0'){
                num.push(s[i]-'0');
            }
            else if(s[i]=='['){
                i++;
                while(s[i]!=']'){
                    alp.push(s[i]);
                    i++;
                }
                int cnt = 1,temp=0;
                while(!num.empty()){
                    temp += num.top()*cnt;
                    cn*=10;
                    num.pop();
                }
                string para ="";
                while(!alp.empty()){
                    para+=alp.front();
                    alp.pop();
                }
                for(int j=0;j<temp;j++){
                    ans+=para;
                }
            }
            else if(s[i]!=']'){
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};
