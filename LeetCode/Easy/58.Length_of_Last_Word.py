class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        b = list(a)
        c = b[-1]
        count = 0
        for i in c:
            count += 1
        return count
            
        
