class Solution {
public:
    int change2int(char a){
        int temp = 0;
        if(a>='a'&&a<='z'){
            temp = a-'a';
        }
        else{
            temp = a-'A'+26;
        }
        return temp;
    }
    bool check(vector<int> a,vector<int> b){
        for(int i =0;i<a.size();i++){
            if(a[i]>b[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        string ans="";
        vector<int> countt(53,0);
        vector<int> counts(53,0);
        int n =s.length(),m=t.length();
        if(m>n){
            return ans;
        }
        for(int i =0;i<m;i++){
            countt[change2int(t[i])]++;
        }
        for(int i=0;i<m;i++){
            int temp = change2int(s[i]);
            if(countt[temp]>0){
                counts[temp]++;
            }
        }
        if(check(countt,counts)){
            return s.substr(0,m);
        }
        int left = 0,right=m;
        for(int i = right;i<n;i++){
            int temp = change2int(s[i]);
            if(countt[temp]>0){
                counts[temp]++;
            }
            if(check(countt,counts)){
                while(check(countt,counts)){
                    int temp2 = change2int(s[left]);
                    if(countt[temp2]>0){
                        counts[temp2]--;
                    }
                    left++;
                }
                if(i-left+2<=ans.size()||ans==""){
                    ans = s.substr(left-1,i-left+2);
                }
            }
        }
        return ans;
    }
};
