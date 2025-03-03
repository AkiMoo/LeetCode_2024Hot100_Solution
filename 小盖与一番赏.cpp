#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <Windows.h>
using namespace std;

int main(){
    queue<string> q, outq;
    map<string,int> ans;
    int n,m,op;
    cin>>n>>m>>op;
    for(int i = 0;i <op;i++){
        string input;
        cin>>input;
        if(input.length()==1){
            cout<<q.size()<<endl;
            
        }
        else if(input[0]=='3'){
            int x = stoi(input.substr(2,input.length()-2));
            n-=x;
            q.pop();
            if(!q.empty()&&n<=m){
                string top = q.front();
                ans[top] += n;
                break;
            }
        }
        else if(input[0]=='1'){
            string man = input.substr(2,input.length()-2);
            if(n<=m){
                ans[man] += n;
                break;
            }
            else{
                q.push(man);
            }
        }
        else{
            string man = input.substr(2,input.length()-2);
            while(!q.empty()){
                if(q.front()!=man){
                    outq.push(q.front());
                }
                q.pop();
            }
            while(!outq.empty()){
                q.push(outq.front());
                outq.pop();
            }
        }
    }
    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    //system.pause();
}
