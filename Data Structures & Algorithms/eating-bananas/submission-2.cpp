/**
can eat <=k bananas per pile per hour but not from multiple piles
return minimum k such that koko can eat all the bananas with h hours

piles = [1,4,3,2], h = 9
k=1 -> t=10 > h=9
k=2 -> t=6 < h=9

BRUTE FORCE
- go from k to max value in pile {O(n)}
- for each k, attempt to finish each pile and then move onto the next
- let's say worst case each pile has m bananas
- t += (m % k == 0) ? m/k : m/k + 1; which will always round up
- if t > h at any point, go to next k

ALTERNATIVE
- 


*/
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end(), greater<int>());

        int max_pile_size = piles[0];
        for (int k=1; k<max_pile_size; k++) {
            int t=0;
            for (const int& m: piles) {
                int divisor = m / k;
                if (m % k == 0) {
                    t += divisor;
                } else {
                    t += divisor + 1;
                }
                if (t > h) break;
            }
            if (t <= h) return k;
        }
        return max_pile_size;
    }
};
