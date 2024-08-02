class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int i = 0,j=0;
        while(visited[i][j]!=1){
            visited[i][j] =1;
            if(matrix[i][j]==target){
                return true;
            }
            else{
                if(matrix[i][j]<target){
                    if(i<m&&visited[i+1][j]==0){
                        i++;
                    }
                    else if(j<n&&visited[i][j+1]==0){
                        j++;
                    }
                }
                else {
                    if(i>0&&visited[i-1][j]==0){
                        i--;
                    }
                    else if(j>0&&visited[i][j-1]==0){
                        j--;
                    }
                }
            }
        }
        return false;
    }
};
