class Node:
    def __init__(self, val: str):
        self.val = val
        self.nexts = {}
        self.isTerminator = False

class PrefixTree:

    def __init__(self):
        self.root = Node(None)

    def insert(self, word: str) -> None:
        curr = self.root
        for i, c in enumerate(word):
            if c not in curr.nexts:
                new_node = Node(c)
                curr.nexts[c] = new_node
            if i == len(word) - 1:
                curr.isTerminator = True
            curr = curr.nexts[c]

    def search(self, word: str) -> bool:
        curr = self.root
        print(f"looking for {word}...")
        for i, c in enumerate(word):
            if c in curr.nexts:
                print(f"found {c}")
                if i == len(word) - 1:
                    return curr.isTerminator
                curr = curr.nexts[c]
            else: 
                return False
        return False

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for i, c in enumerate(prefix):
            if c in curr.nexts:
                curr = curr.nexts[c]
            else:
                return False
        return True
        