class Solution {
public:
    int canjump(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n,0);
        hash[0] = 1;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<i+nums[i];j++){
                if(nums[j]==0){
                    hash[j]=1;
                }
                else {
                    hash[j] = min(hash[j],hash[i]+1);
                }
            }
        }
        return hash[n-1];
    }
};
