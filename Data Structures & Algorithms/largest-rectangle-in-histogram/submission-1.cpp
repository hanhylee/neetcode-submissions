/**
[7,1,7,2,2,4]
height=2, width=4, area=8

[1,3,7]
height=7, width=1, area=7

BRUTE FORCE:
calculate area of all areas using a sliding window
take the min height and multiply by width
O(n * n * n) = O(n^3)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int global_max = 0;
        for (int ws=1; ws<=heights.size(); ws++) {
            for (int i=0; i<heights.size()-ws+1; i++) {
                auto start_idx = heights.begin()+i;
                auto end_idx = start_idx + ws;
                auto min_height = min_element(start_idx, end_idx);
                int height = *min_height * ws;
                global_max = max(global_max, height);
            }
        }
        return global_max;
    }
};
