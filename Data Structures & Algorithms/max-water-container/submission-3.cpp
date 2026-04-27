class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;

        int max_area;

        while (l < r) {
            int width = r - l;
            int height = min(heights[r], heights[l]);
            int area = width * height;
            max_area = max(area, max_area);
            if (heights[r] < heights[l]) r--;
            else l++;
        }

        return max_area;
    }
};
