from collections import defaultdict
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

        dists = [math.inf for i in range(n+1)]
        dists[k] = 0

        adj = defaultdict(list)
        for u, v, t in times:
            adj[u].append((v, t))
        
        visited = set()

        pq = [(0, k)]

        while pq:
            currDist, currNode = heapq.heappop(pq)
            if currNode in visited:
                continue
            visited.add(currNode)
            for neighborNode, t in adj[currNode]:
                if currDist + t < dists[neighborNode]:
                    dists[neighborNode] = currDist + t
                if neighborNode not in visited:
                    heapq.heappush(pq, (dists[neighborNode], neighborNode))
        
        maxDist = 0
        for dist in dists[1:]:
            if dist == math.inf:
                return -1
            maxDist = max(maxDist, dist)

        # return min time for all nodes to receive signal (max path)
        # return -1 if not all nodes can receive signal
        return maxDist





