class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //摩尔投票，众数记1，非众数记0
        int x = 0, votes = 0;
        for (int num : nums){
            if (votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        return x;
    }
};
