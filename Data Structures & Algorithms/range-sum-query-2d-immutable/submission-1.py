class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        self.matrixSums = self.calculateMatrixSums(matrix)
    
    def calculateMatrixSums(self, matrix: List[List[int]]) -> List[List[int]]:
        matrixSums = matrix

        for y in range(len(matrixSums)):
            for x in range(len(matrixSums[0])):
                if y == 0:
                    matrixSums[y][x] += matrixSums[y][x-1] if x > 0 else 0
                elif x == 0:
                    matrixSums[y][x] += matrixSums[y-1][x] if y > 0 else 0
                else:
                    matrixSums[y][x] += matrixSums[y-1][x] + matrixSums[y][x-1] - matrixSums[y-1][x-1]

        
        for y in matrixSums:
            print(y)

        return matrixSums

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        bigArea = self.matrixSums[row2][col2]
        upperArea = self.matrixSums[row1 - 1][col2] if row1 > 0 else 0
        leftArea = self.matrixSums[row2][col1-1] if col1 > 0 else 0
        upperLeftArea = self.matrixSums[row1-1][col1-1] if row1 > 0 and col1 > 0 else 0
        return bigArea - upperArea - leftArea + upperLeftArea


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)