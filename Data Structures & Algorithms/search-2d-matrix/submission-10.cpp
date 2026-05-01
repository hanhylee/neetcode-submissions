/**
double binary search problem
matrix = [[1,2,4,10],[11,12,12,13]], target = 10
look at the first number
u=0, d=1 -> m=0
u=1

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find row that num is in
        int u=0, d=matrix.size()-1;

        while (u < d) {
            int m = (u+d)/2;

            if (matrix[m][0] == target) {
                return true;
            } else if (matrix[m][0] < target && m + 1 < matrix.size() && matrix[m+1][0] > target) {
                u = m;
                break;
            } else if (matrix[m][0] > target && m - 1 > 0 && matrix[m-1][0] < target) {
                u = m-1;
                break;
            } else if (matrix[m][0] < target) {
                u = m+1;
            } else {
                d = m-1;
            }
        }

        cout << "target is in row: " << u << "\n";

        // binary search within that row
        int l=0, r=matrix[u].size()-1;

        while (l < r) {
            int m = (l+r)/2;

            if (matrix[u][m] == target) {
                return true;
            } else if (matrix[u][m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        cout << matrix[u][l];

        if (l < matrix[u].size() && matrix[u][l] == target) return true;
        if (r < matrix[u].size() && matrix[u][r] == target) return true;

        return false;
    }
};
