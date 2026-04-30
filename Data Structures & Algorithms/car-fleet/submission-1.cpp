/**
target = 10, position = [1,4], speed = [3,2]
car1 becomes fleet with car2 if 1+3t = 4+2t <= 10
1+3t = 10 -> t = 3
4+2t = 10 -> t = 3

target = 10, position = [4,1,0,7], speed = [2,2,1,1]
car1: 4+2t=10 -> t = 3
car2: 1+2t=10 -> t = 4.5
car3: 0+1t=10 -> t = 10
car4: 7+1t=10 -> t = 3
in order from distance from target: car3 -> car2 -> car1 -> car4
- if t for car3 <= car2, it becomes a fleet
- conversely, if t for car3 > car2, it's an independent count
O(n log n) to sort positions

target=10, position=[6,8], speed=[3,2]
car1: t=4/3
car2: t=1/2

*/


class Solution {
public:
    float timeToDest(int tgt, int pos, int spd) {
        return (float) (tgt - pos)/spd;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, float>> position_time_pairs;

        for (int i=0; i<position.size(); i++) {
            float ttd = timeToDest(target, position[i], speed[i]);
            cout << "ttd: " << ttd << " ";
            pair<int, float> pos_time(position[i], ttd);
            position_time_pairs.push(pos_time);
        }
        cout << "\n";

        float slowest = 0.0;
        int numFleets = 0;
        while (!position_time_pairs.empty()) {
            float next_ttd = position_time_pairs.top().second;
            if (next_ttd > slowest) {
                numFleets++;
                slowest = next_ttd;
            }
            position_time_pairs.pop();
        }

        return numFleets;
    }
};
