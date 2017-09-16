class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>>res(A.size(), vector<int>(B[0].size()));
		for (int i = 0; i < A.size(); i++)
			for (int j = 0; j < B[0].size(); j++)
				res[i][j] = helper(A[i], B, j);
		return res;
	}

	int helper(vector<int>& v, vector<vector<int>>& B, int col) {
		int res = 0;
		for (int i = 0; i < v.size(); i++)
			if (v[i] != 0 && B[i][col] != 0)
				res += v[i] * B[i][col];
		return res;
	}
};

// Optimize
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>res(A.size(), vector<int>(B[0].size()));
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < A[0].size(); j++)
                if(A[i][j] != 0)
                for(int k = 0; k < B[0].size(); k++)
                    res[i][k] += A[i][j] * B[j][k];
        return res;
    }
};
