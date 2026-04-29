/**
[30,38,30,36,35,40,28]
[1,4,1,2,1,0,0]

BRUTE FORCE
- for each, look ahead until there is a warmer day or we reach the end of the array
- record the number of days in the output array

OPTIMIZED
- 
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        for (int i=0; i<temperatures.size(); i++) {
            for (int j=i+1; j<temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    res.push_back(j-i);
                    break;
                }
                if (j >= temperatures.size() - 1) {
                    res.push_back(0);
                    break;
                }
            }
        }
        res.push_back(0);
        return res;
    }
};
