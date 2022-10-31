class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-1*x for x in stones]
        heapify(stones)
        
        while len(stones) > 1:
            a = heappop(stones)*-1
            b = heappop(stones)*-1
        
            if a != b:
                c = max(a,b) - min(a,b)
                heappush(stones,c*-1)
                
        return stones[-1]*-1 if stones else 0
