class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        int ans = 0;
        while(l<r){
            ans = max(ans,min(height[l],height[r])*(l-r));
            if(heightp[l]<height[l+1]){
                l++;
                continue;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};
