class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> weights(stones.begin(), stones.end());

        while (weights.size() > 1) {
            int x = weights.top();
            weights.pop();
            int y = weights.top();
            weights.pop();

            if (x > y) {
                x -= y;
                weights.push(x);
            } else if (x < y) {
                y -= x;
                weights.push(y);
            }

        }

        return (weights.size() == 1) ? weights.top() : 0;
    }
};
