int majorityElement(vector<int>& nums) {
    int hash[3] = 0,n= nums.size();
    for(int i = 0;i<n;i++){
        hash[nums[i]]++;
    }
    for(int i = 0;i<n;i++){
        if(hash[0]>0){
            nums[i]=0;
            hash[0]--;
        }
        else if(hash[1]>0){
            nums[i]=1;
            hash[1]--;
        }
        else {
            nums[i]=2;
        }
    }
    return nums;
}
