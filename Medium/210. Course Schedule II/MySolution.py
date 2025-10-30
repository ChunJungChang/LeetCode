class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        for i in range(numCourses):
            inDegree = {}
            graph = {}
        for i in range(numCourses):
            inDegree[i] = 0
            graph[i] = []
        for pair in prerequisites:
            inDegree[pair[0]] += 1
            graph[pair[1]].append(pair[0])
        
        
        queue = deque()
        for i in range(numCourses):
            if inDegree[i] == 0:
                queue.append(i)
        
        numVisitedCourses = 0
        ret = []
        while len(queue):
            preCourse = queue.popleft()
            numVisitedCourses += 1
            ret.append(preCourse)
            for Course in graph[preCourse]:
                inDegree[Course] -= 1
                if inDegree[Course] == 0:
                    queue.append(Course)
        
        if numVisitedCourses == numCourses:
            return ret
        else:
            return []
