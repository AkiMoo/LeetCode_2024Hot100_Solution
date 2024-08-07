class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n,0);
        // if(n==1){
        //     return 0;
        // }
        for(int i=0;i<n;i++){
            if(hash[i]==0&&i>0){
                break;
            }
            for(int j =i+1;j<=i+nums[i]&&j<n;j++){
                if(hash[j]==0){
                    hash[j] = hash[i]+1;
                }
                else{
                    hash[j] = min(hash[j],hash[i]+1);
                }
            }
        }
        return hash[n-1];
    }
};
