class Solution:
    def getNewNumber(self, currNum):
        newNum = 0
        while currNum > 0:
            rem = currNum % 10
            newNum += rem * rem
            currNum //= 10

        return newNum

    def isHappy(self, n: int) -> bool:
        isCalculated = {}

        currNum = n

        while currNum not in isCalculated:
            if currNum == 1:
                return True

            isCalculated[currNum] = True
            currNum = self.getNewNumber(currNum)

        return False