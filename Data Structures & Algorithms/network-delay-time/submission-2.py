import heapq
import math

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # given network of n directed nodes labeled 1 to n
        # given list of directed edges [start, end, time]
        # given source of signal k

        """
        APPROACH
        - djikstra's algorithm
        - initialize dists array with -1 for all nodes except k which gets 0
        - build adjacency array for O(1) lookup
        - add k to priority queue (pq)
        - loop while next largest != -1 and not in visited
            - pop largest in pq and add to visited
            - if curr path < dists[neighbor]
                - update dists[neighbor] to curr path
            - add neighbor to pq with curr path
        - return -1 if there is a -1 in dists or max element of dists
        """

        adj = collections.defaultdict(list)
        for u, v, t in times:
            adj[u].append((v, t))
        
        visited = set()
        pq = [(0, k)]
        t = 0

        while pq:
            currDist, currNode = heapq.heappop(pq)
            if currNode in visited:
                continue
            visited.add(currNode)
            t = currDist
            for neighborNode, nextDist in adj[currNode]:
                if neighborNode not in visited:
                    heapq.heappush(pq, (currDist + nextDist, neighborNode))

        # return min time for all nodes to receive signal (max path)
        # return -1 if not all nodes can receive signal
        return t if len(visited) == n else -1





