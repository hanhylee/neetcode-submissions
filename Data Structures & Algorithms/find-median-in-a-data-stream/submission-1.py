class MedianFinder:

    # class Node:
    #     def __init__(self, num: int):
    #         self.num = num
    #         self.next = None
    #         self.prev = None

    def __init__(self):
        # self.head = None
        self.data = []          # list(int)
        # self.num_node = {}    # {int: Node}
        # self.size = 0

    def addNum(self, num: int) -> None:
        # binary search to add num? O(log n) + O(n)
        if len(self.data) == 0:
            self.data.append(num)
            return

        l, r = 0, len(self.data) - 1

        while l <= r:
            m = l + (r - l)//2

            if self.data[m] == num:
                self.data.insert(m, num)
                print(self.data)
                return
            elif self.data[m] < num:
                l = m + 1
            else:
                r = m - 1
        
        self.data.insert(l, num)
        print(self.data)
        return

    def findMedian(self) -> float:
        # O(1) if data is sorted
        size = len(self.data)
        print(f"size: {size}")

        if size % 2 == 1:
            print(self.data[size//2])
            return float(self.data[size//2])
        else:
            print(f"avg of {self.data[size//2]} and {self.data[size//2 - 1]}")
            return float(self.data[size//2] + self.data[size//2 - 1])/2
        