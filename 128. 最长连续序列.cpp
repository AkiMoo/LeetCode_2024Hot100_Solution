// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int,int> hash;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             hash[nums[i]] = 1;
//         }
//         int ans = 1;
//         for(int i=0;i<n;i++){
//             int temp = nums[i];
//             int thisround = 1;
//             while(hash[temp++]>0){
//                 thisround++;
//                 //temp++;
//             }
//             ans = max(ans,thisround);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};
