class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), r = 0, c = n-1;
        while (true) {
            if (r >= m || c < 0) return false;
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) c--;
            else if (matrix[r][c] < target) r++;
        }
    }
};