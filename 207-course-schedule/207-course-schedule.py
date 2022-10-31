class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        #
        #   bi --> ai
        #
        #   Return true if you can finish all courses.
        #
        #   what is impossible case?
        #          __
        #         /  \-->
        #        0<------1
        #
        #   if closed circle is detected, it is impossible.
        #
        #
        #  Example: It is impossible. Here, we prepare path stack. Start from 0
        #
        #          ---->
        #         /     \
        #        0       1--->2
        #         \     /
        #          <----
        #
        #  Path Stack
        #  [0]
        #  [0,1]
        #  [0,1,2]
        #  [0,1]
        #  [0,1,0]  <--- if coming node is already included in stack, closed circle exists.
        #
        #  if start from 1
        #  Path Stack
        #  [1]
        #  [1,2]
        #  [1]
        #  [1,0]
        #  [1,0,1]  <--- coming node is already included in stack
        #
        #
        #  Example: This is acceptable
        #
        #        4--->
        #       /     \
        #      0       1--->2
        #       \     /
        #        3--->
        #
        #  Path Stack
        #  [0]
        #  [0,4]
        #  [0,4,1]
        #  [0,4,1,2]
        #  [0,4,1]
        #  [0,4]
        #  [0]
        #  [0,3]  <--- ok
        #
        #
        
        def dfs(root) :
            visited[root] = True
            path_stack.append(root)
            for node in graph[root] :
                #print(path_stack,node)
                if node in path_stack : return False
                if not visited[node] :
                    if not dfs(node) :
                        return False
                    path_stack.pop()
            return True
        
        from collections import defaultdict
        from collections import deque
        
        # construct graph
        graph = defaultdict(list)
        for ai,bi in prerequisites :
            graph[ai].append(bi)
            
        # visited record
        visited = [ False ]*numCourses
        
        # for-loop to visit all of nodes
        for initial_course in range(numCourses) :
            if not visited[initial_course] :
                # traverse by dfs
                path_stack = deque()
                if not dfs(initial_course) :  # False -- cycle detected case
                    return False
        return True
