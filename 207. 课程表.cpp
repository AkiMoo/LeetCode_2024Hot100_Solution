class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> matrix(numCourses,vector<int>(numCourses,0));
        queue<int> q;
        int n = prerequisites.size();
        for(int i =0;i<n;i++){
            matrix[prerequisites[i][0]][prerequisites[i][1]]++;
        }
        for(int i=0;i<numCourses;i++){
            int sum = 0;
            for(int j=0;j<numCourses;j++){
                sum+=matrix[j][i];
            }
            if(sum==0){
                q.push(i);
            }
        }
        queue<int> check;
        while(!q.empty()){
            for(int i=0;i<numCourses;i++){
                if(matrix[q.front()][i]>0){
                    matrix[q.front()][i] = 0;
                    check.push(i);
                }
            }
            q.pop();
            while(!check.empty()){
                int sum = 0;
                for(int j=0;j<numCourses;j++){
                    sum+=matrix[j][check.front()];
                }
                if(sum==0){
                    q.push(check.front());
                }
                check.pop();
            }
        }
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<numCourses;j++){
                if(matrix[i][j]!=0){
                    return false;
                }
            }
        }
        return true;
    }
};
