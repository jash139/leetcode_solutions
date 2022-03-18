class Solution:
    def getParenthesis(self, result, currentCombination, left, right):
        if left == 0 and right == 0:
            result.append(currentCombination)
            return

        if left > 0:
            self.getParenthesis(result, currentCombination + "(", left - 1, right)

        if right > left:
            self.getParenthesis(result, currentCombination + ")", left, right - 1)

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.getParenthesis(result, "", n, n)
        return result;