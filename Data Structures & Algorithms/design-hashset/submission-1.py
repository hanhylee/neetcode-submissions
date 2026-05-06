class MyHashSet:

    def __init__(self):
        self.hashset = [0 for x in range(20000)]

    def getHash(self, key: int) -> int:
        return (133 * key + 133) % 20000

    def add(self, key: int) -> None:
        self.hashset[self.getHash(key)] = 1

    def remove(self, key: int) -> None:
        self.hashset[self.getHash(key)] = 0

    def contains(self, key: int) -> bool:
        return self.hashset[self.getHash(key)] == 1


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)