class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y){
        int n = grid.size(), m = grid[0].size();
        if(x>n-1||y>m-1||x<0||y<0){
            return;
        }
        if(grid[x][y]!='1'){
            return;
        }
        else{
            grid[x][y] = '2';
        }
        dfs(grid,x-1,y);
        dfs(grid,x+1,y);
        dfs(grid,x,y-1);
        dfs(grid,x,y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
