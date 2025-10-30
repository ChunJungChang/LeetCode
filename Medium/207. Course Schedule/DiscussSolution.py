"""
https://medium.com/@ryanyang1221/leetcode-challenge-5-29-course-schedule-%E4%B8%89%E9%83%A8%E6%9B%B2%E5%A4%A7%E7%A6%AE%E5%8C%85-%E4%B8%8A-64d17fa5b1ba
"""

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        Input:
        2
        [[1,0]]
        """
        
        inDegree = {}
        graph = {}
        
        """
        inDegree: {"0": "0", "1": "1"}
        graph: {"0": [1], "1": []}
        """
        for i in range(numCourses):
            inDegree[i] = 0
            graph[i] = []
        for pair in prerequisites:
            inDegree[pair[0]] += 1
            graph[pair[1]].append(pair[0])
        
        queue = deque()
        for k, v in inDegree.items():
            if v == 0:
                queue.append(k)
        
        numVisitedCourses = 0
        while len(queue):
            preCourse = queue.popleft()
            numVisitedCourses += 1
            for Course in graph[preCourse]:
                inDegree[Course] -= 1
                if inDegree[Course] == 0:
                    queue.append(Course)
        
        return numVisitedCourses == numCourses
