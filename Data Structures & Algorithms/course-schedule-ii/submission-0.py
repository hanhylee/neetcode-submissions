from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # given array of prereqs
        # prereq[i] = [course, prereq]
        
        """
        approach:
        - count inDegrees of each vertex while building adjacency list for O(1) lookup
        - add vertices with 0 inDegrees to queue since those can be taken without prereqs
        - while q:
            - curr = pop q and add to res
            - look up all the vertices that are enabled as a result of curr course taken
            - decrease the inDegrees of those vertices
            - add the vertex if all prereqs are met (i.e. inDegrees == 0)
        - if queue is empty and there is an inDegree > 0, return []
        """

        # count inDegrees of each vertex while building adjacency list for O(1) lookup
        inDegrees = [0 for i in range(numCourses)]
        adjacencyList = {}
        for course, prereq in prerequisites:
            inDegrees[course] += 1
            if prereq in adjacencyList:
                adjacencyList[prereq].append(course)
            else:
                adjacencyList[prereq] = [course]
        
        # add vertices with 0 inDegrees to queue since those can be taken without prereqs
        q = deque()
        for course, inDegree in enumerate(inDegrees):
            if inDegree == 0:
                q.append(course)
        
        res = []
        while q:
            # curr = pop q and add to res
            curr = q.popleft()
            res.append(curr)
            # look up all the vertices that are enabled as a result of curr course taken
            if curr in adjacencyList:
                for nextNode in adjacencyList[curr]:
                    # decrease the inDegrees of those vertices
                    inDegrees[nextNode] -= 1
                    # add the vertex if all prereqs are met (i.e. inDegrees == 0)
                    if inDegrees[nextNode] == 0:
                        q.append(nextNode)

        # if queue is empty and there is an inDegree > 0, return []
        for inDegree in inDegrees:
            if inDegree > 0:
                return []

        # return topologically sorted array or empty array if not possible
        return res