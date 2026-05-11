class WordDictionary:

    class Node:
        def __init__(self, val: str) -> None:
            self.val = val
            self.nexts = [None for x in range(26)]
            self.terminator = False

    def __init__(self):
        self.head = self.Node("")

    def addWord(self, word: str) -> None:
        curr = self.head
        for letter in word:
            idx = ord(letter) - ord("a")
            if not curr.nexts[idx]:
                curr.nexts[idx] = self.Node(letter)
            curr = curr.nexts[idx]
        curr.terminator = True
        print(f"added {word}")

    def search(self, word: str) -> bool:
        # returns true if there is any string in the dictionary that matches word
        # word may contain dots '.' where dots can be matched with any letter
        # prefix tree would work with BFS
        def backtrack(node: Node, word: str) -> bool:
            # base case
            if not node:
                return False
            if len(word) == 0:
                return node.terminator
        
            letter = word[0]
            print(f"looking for {letter}...")
            if letter == ".":
                for nextNode in node.nexts:
                    if backtrack(nextNode, word[1:]):
                        return True
            else:
                idx = ord(letter) - ord("a")
                if backtrack(node.nexts[idx], word[1:]):
                    return True
            return False

        return backtrack(self.head, word)