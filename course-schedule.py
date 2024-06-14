from typing import List, Dict

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        hashmap: Dict[int, List[int]] = {i:[] for i in range(numCourses)}

        for course, pre in prerequisites:
            hashmap[course].append(pre)

        visited = [False for _ in range(numCourses)]

        def finish(course: int):
            if hashmap[course] == []:
                return True
            if visited[course]:
                return False
            
            visited[course] = True
            for pre in hashmap[course]:
                if not finish(pre):
                    return False
            hashmap[course] = []
            return True

        for course in range(numCourses):
            if not finish(course):
                return False
        return True
