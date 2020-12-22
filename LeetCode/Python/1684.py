class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        count = 0
        for w in words:
            isValid = True
            for c in w:
                isValid &= (c in allowed)
            count += isValid
        return count
