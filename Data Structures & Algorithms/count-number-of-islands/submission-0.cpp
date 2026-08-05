class Solution {
public:
    void traceIsland(int i,int j,vector<vector<char>> &grid,vector<vector<bool>> &visited){
        if(i < 0 || i >= grid.size()){
            return;
        }
        if(j < 0 || j >= grid[0].size()){
            return;
        }
        if(visited[i][j] || (grid[i][j] == '0')){
            return;
        }
        visited[i][j] = true;
        traceIsland(i+1,j,grid,visited);
        traceIsland(i-1,j,grid,visited);
        traceIsland(i,j+1,grid,visited);
        traceIsland(i,j-1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if((!visited[i][j]) && (grid[i][j] == '1')){
                    count++;
                    traceIsland(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
