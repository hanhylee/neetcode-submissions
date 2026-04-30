/**
[7,1,7,2,2,4]
height=2, width=4, area=8

[1,3,7]
height=7, width=1, area=7

BRUTE FORCE:

calculate area of all areas using a sliding window
take the min height and multiply by width
O(n * n * n) = O(n^3)

ALTERNATIVELY:

calculate max_area starting from left height while advancing a right pointer
   |   [7. ,1.  ,7.  ,2.  ,2,   4]
--------------------------------------
 0 |    7   2   3     4    5    6
 1 |        SKIP
 2 |            7    4     6    8
 3 |                 2     4    6
   |
   |
O(n^2)

*/

#include <algorithm>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int global_max = 0;
        for (int l=0; l<heights.size(); l++) {
            int min_height = heights[l];
            global_max = max(global_max, min_height);
            for (int r=l+1; r<heights.size(); r++) {
                min_height = min(min_height, heights[r]);
                int max_local_area = min_height * (r - l + 1);
                global_max = max(global_max, max_local_area);
            }
        }
        return global_max;

        // for (int ws=1; ws<=heights.size(); ws++) {
        //     for (int i=0; i<heights.size()-ws+1; i++) {
        //         auto start_idx = heights.begin()+i;
        //         auto end_idx = start_idx + ws;
        //         auto min_height = min_element(start_idx, end_idx);
        //         int height = *min_height * ws;
        //         global_max = max(global_max, height);
        //     }
        // }
    }
};
