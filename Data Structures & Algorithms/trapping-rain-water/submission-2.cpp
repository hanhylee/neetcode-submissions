class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeftHeights = {0};
        vector<int> maxRightHeights = {0};

        for (int i=0; i<height.size()-1; i++) {
            maxLeftHeights.push_back(max(maxLeftHeights.back(), height[i]));
            cout << maxLeftHeights.back();
        }
        cout << endl;
        for (int i=height.size()-1; i>0; i--) {
            maxRightHeights.push_back(max(maxRightHeights.back(), height[i]));
            cout << maxRightHeights.back();
        }
        cout << endl;

        int volume = 0;
        for (int i=0; i<height.size()-1; i++) {
            int temp = min(maxLeftHeights[i], maxRightHeights[height.size()-1-i]) - height[i];
            cout << temp;
            if (temp > 0) volume += temp;
        }

        return volume;
    }
};
