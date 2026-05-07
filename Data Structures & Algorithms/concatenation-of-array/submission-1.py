class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        # templist = []*len(nums)*2
        # for i, item in enumerate(nums): 
        #     templist.insert(i, item)
        #     templist.insert(i + len(nums), item)
        
        # return templist
        return nums + nums        