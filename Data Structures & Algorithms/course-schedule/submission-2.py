from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # given array of prereqs
        # each prereq is an array of size 2 where:
        # - element 1 is the prereq for element 0
        # - element 1 must come BEFORE element 0

        # approach: topological sort
        # detect if there is a cycle
        """
        1. calculate in-degrees of each vertex while building adjacency list
        2. add all vertices with in-degrees of 0 to the queue
        3. process curr vertex in queue while queue is not empty
            3a. pop vertex from queue
            3b. decrease in-degrees of each neighbor of curr
            3c. add all neighbors with in-degrees of 0 to queue
        4. if any vertex still has an in-degree > 0, return False
        """

        # 1. calculate in-degrees of each vertex while building adjacency list
        inDegrees = [0 for i in range(numCourses)]
        adjacencyList = {}
        for course, prereq in prerequisites:
            inDegrees[course] += 1
            if prereq not in adjacencyList:
                adjacencyList[prereq] = [course]
            else:
                adjacencyList[prereq].append(course)
         
        # 2. add all vertices with in-degrees of 0 to queue
        q = deque()
        #=========================
        def addZeroDegrees() -> None:
            nonlocal q, inDegrees
            for course, inDegree in enumerate(inDegrees):
                if inDegree == 0:
                    q.append(course)
        #=========================
        addZeroDegrees()

        # 3. process curr vertex in queue while queue is not empty
        while q:
            # 3a. pop vertex from queue
            curr = q.popleft()
            # 3b. decrease in-degrees of each neighbor of curr
            if curr in adjacencyList:
                for neighbor in adjacencyList[curr]:
                    inDegrees[neighbor] -= 1
                    # 3c. add neighbor to queue if inDegrees = 0
                    if inDegrees[neighbor] == 0:
                        q.append(neighbor)

        # 4. if any vertex still has an in-degree > 0, return False
        for inDegree in inDegrees:
            if inDegree > 0:
                return False

        # return true if possible to finish all courses
        return True