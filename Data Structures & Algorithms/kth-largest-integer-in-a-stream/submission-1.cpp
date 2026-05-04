class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        heap = priority_queue(nums.begin(), nums.end());
    }
    
    int add(int val) {
        heap.push(val);
        vector<int> re_add;
        for (int i=0; i<k-1; i++) {
            int next = heap.top();
            re_add.push_back(next);
            cout << "removing " << i << "th int: " << next << "\n";
            heap.pop();
        }
        int kth_largest = heap.top();
        for (int num: re_add) {
            heap.push(num);
            cout << "readded " << num << "\n";
        }
        return kth_largest;
    }

private:
    priority_queue<int> heap;
    int k;
};
