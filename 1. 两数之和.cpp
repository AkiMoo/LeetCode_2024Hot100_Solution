#include <iostream>
#include <unordered_map>
#include <vector>
#include <windows.h>
using namespace std;

void twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    unordered_map<int,int> hash;
    for(int i = 0;i<n;i++){
        hash[nums[i]] = i+1;
        if(hash[target-nums[i]]>0){
            ans.push_back(hash[target-nums[i]]-1),ans.push_back(i);
            //return ans;
            break;
        }
    }
    for(int i = 0;i<2;i++){
        cout<<"fadsfas"<<endl;
        cout<<ans[i]<<endl;
    }
    // ans.push_back(0);
    // ans.push_back(1);
    //return ans;
}
int main(){
    vector<int> nums = {2,8,11,4,15,5};
    
    twoSum(nums,9);
    system("pause");
}
