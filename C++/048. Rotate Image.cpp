// Detailed explanation with hand-draw graph can be found in discuss.
// In-place.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        helper(matrix, 0, 0, matrix.size());
    }
    
    void helper(vector<vector<int>>& matrix, int row, int col, int size) {
        if (size == 0 || size == 1) return;
        int step = 0;
        while(step < size - 1){
            swap(matrix[row][col + step], matrix[row + step][col + size - 1]);
            swap(matrix[row][col + step], matrix[row + size - 1 - step][col]);
            swap(matrix[row + size - 1][col + size - 1 - step], matrix[row + size - 1 - step][col]);
            step++;
        }
        helper(matrix, row + 1, col + 1, size - 2);
    }
};

// Just for clear up, A common method to rotate the image from this post by @SHICHAOTAN:
// https://discuss.leetcode.com/topic/6796/a-common-method-to-rotate-the-image.
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
