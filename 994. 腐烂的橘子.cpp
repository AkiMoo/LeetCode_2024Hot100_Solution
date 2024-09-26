class Solution {
public:
    int total = 0;
    void inArea(vector<vector<int>>& grid,int x,int y){
        int n = grid.size(), m = grid[0].size();
        if(x<n&&y<m&&x>=0&&y>=0){
            if(grid[x][y]==1){
                grid[x][y] = 3;
                //otal--;
            }
        }
        else{
            return ;
        }
    }
    void dfs(vector<vector<int>>& grid,int x,int y){
        inArea(grid,x-1,y);
        inArea(grid,x+1,y);
        inArea(grid,x,y-1);
        inArea(grid,x,y+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        int last = 1, current = 0;
        while(total>0){
            if(last==current){
                return -1;
            }
            last = current;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==2){
                        dfs(grid,i,j);
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==3){
                        grid[i][j]=2;
                        total--;
                    }
                }
            }
            ans++;
            current = total;
        }
        return ans;
    }
};
