class Solution {
public:
    bool isValid(string s) {
        stack<char> mem;
        int n = s.length(),i=0;
        while(i<n){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                mem.push(s[i]);
            }
            else if(s[i]==')'){
                if(mem.empty()||mem.top()!='('){
                    return false;
                }
                mem.pop();
            }
            else if(s[i]==']'){
                if(mem.empty()||mem.top()!='['){
                    return false;
                }
                mem.pop();
            }
            else{
                if(mem.empty()||mem.top()!='{'){
                    return false;
                }
                mem.pop();
            }
            i++;
        }
        if(mem.empty()){
            return true;
        }
        return false;
    }
};
