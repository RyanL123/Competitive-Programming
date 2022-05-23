class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size(), m = matrix.size();
        int l = 0, r = m-1;
        int row = -1;
        while (l <= r) {
            int m = (l+r)/2;
            int mn = matrix[m][0], mx = matrix[m][n-1];
            if (target >= mn && target <= mx) {
                row = m;
                break;
            }
            else if (target < mn) r = m-1;
            else l = m+1;
        }
        if (row == -1) return false;
        l = 0, r = n-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (matrix[row][m] == target) return true;
            if (matrix[row][m] > target) r = m-1;
            else l = m+1;
        }
        return false;
    }
};