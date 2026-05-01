#include <unordered_map>
#include <string>
#include <vector>

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> time_map;

public:
    TimeMap() {
        time_map;
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string> new_pair(timestamp, value);
        if (time_map.find(key) == time_map.end()) {
            vector<pair<int, string>> new_array = {new_pair};
            time_map[key] = new_array;
        } else {
            time_map[key].push_back(new_pair);
        }
    }
    
    /**

    returns most recent value of key IF 
    set was previously called on it 
    AND the most recent timestamp for that key (prev_timestamp) <= timestamp

    unordered_map<string, vector<pair<int, string>>>
    - assuming that time only moves linearly forward, the vector will be sorted in asc order
    - this allows us to find the most recent value string (second element in pair) in O(log n) time
    
    let's do an implementation without the binary search first for simplicity

    */
    string get(string key, int timestamp) {
        if (time_map.find(key) == time_map.end()) {
            return "";
        } else {
            pair<int, string> prev(0,"");
            for (const auto& kv: time_map[key]) {
                if (kv.first <= timestamp) {
                    prev = kv;
                } else {
                    break;
                }
            }
            return prev.second;
        }
    }
};
