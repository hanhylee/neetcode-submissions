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

BINARY CLEAVE
- similar to brute force but we select k using binary search
- k = (l+r)/2
[1,4,3,2] -> max_pile_size = 4 -> k = 2


*/
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max_pile = max_element(piles.begin(), piles.end());
        int max_pile_size = *max_pile;

        int l=1, r=max_pile_size;
        int min_k=max_pile_size;

        while (l <= r) {
            int t = 0;
            int k = l + (r - l)/2;
        
            // calculate time to eat bananas
            for (const int& pile: piles) {
                int divisor = pile / k;
                if (pile % k == 0) {
                    t += divisor;
                } else {
                    t += divisor + 1;
                }
                if (t > h) break;
            }
            
            if (t > h) {                    // if time to eat is too much, k > mid
                l = k+1;
            } else {
                min_k = min(min_k, k);
                cout << "min_k: " << min_k << "\n";
                r = k-1;
            }
        }

        return min_k;
    }
};
