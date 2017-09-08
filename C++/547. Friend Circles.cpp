class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int>Tags(M.size());
        int tag = 0;
        for(int i = 0; i < M.size(); i++){
            if(Tags[i]) continue;
            Tags[i] = ++tag;
            for(int j = 0; j < M[0].size(); j++){
                if(j == i || M[i][j] == 0) continue;
                if(M[i][j]){
                    M[i][j] = M[j][i] = 0;
                    DFS(Tags, M, j, tag);
                }
            }
        }
        return tag;
    }
    
    void DFS(vector<int>& Tags, vector<vector<int>>& M, int row, int tag){
        Tags[row] = tag;
        for(int i = 0; i < M[row].size(); i++){
            if(M[row][i]){
                M[row][i] = M[i][row] = 0;
                DFS(Tags, M, i, tag);
            }
        }
    }
};
