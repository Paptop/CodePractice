from functools import reduce

class Solution:

    def convert_to_str(self, word):
        out = reduce((lambda acc, ch: acc + ch), word)
        print(out)
        return out
         
    def arrayStringsAreEqual(self, word1, word2):
        return self.convert_to_str(word1) == self.convert_to_str(word2)
    
sol = Solution()
print(sol.arrayStringsAreEqual(["ab","c"], ["a", "b"]))
