class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        TC: O(n^2), SC: O(n)
        ref: https://leetcode.com/problems/3sum/solutions/7392/python-easy-to-understand-solution-o-n-n-time/comments/304129
        """
        if len(nums) < 3:
            return []
        nums = sorted(nums) # sorted for two pointers method
        output = set() # the solution set must not contain duplicate triplets
        for left in range(len(nums)-2):
            mid = left + 1 # named as mid because it is the pointer which is between the left and right pointers
            right = len(nums) - 1
            while mid < right:
                sum3 = nums[left] + nums[mid] + nums[right]
                if sum3 == 0:
                    output.add((nums[left], nums[mid], nums[right]))
                    # no need to test dup number, so that mid += 1 and right -= 1 for sure
                    mid += 1
                    right -= 1
                elif sum3 < 0:
                    mid += 1 # because nums is sorted, so mid += 1 makes sum3 bigger
                else:
                    right -= 1
        return list(map(list, output)) # output need to be list of list, not set of tuples
