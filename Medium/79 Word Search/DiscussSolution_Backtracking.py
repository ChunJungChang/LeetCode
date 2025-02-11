class Solution:
    RowBoundary = 0
    ColBoundary = 0

    def existHelp(self, board: List[List[str]], row: int, col: int, word: str) -> bool:
        ret = False

        # Step 1: Check the bottom case.
        if (len(word) == 0):
            return True
        # Step 2: Check the boundaries.
        if (row < 0 or row == self.RowBoundary or \
            col < 0 or col == self.ColBoundary or \
            board[row][col] != word[0]):
            return False
        # Step 3: Explore the neighbors in DFS.
        board[row][col] = '#'
        ret = self.existHelp(board, row - 1, col, word[1:]) or \
              self.existHelp(board, row + 1, col, word[1:]) or \
              self.existHelp(board, row, col - 1, word[1:]) or \
              self.existHelp(board, row, col + 1, word[1:])
        # Step 4: Clean up and return the result.
        board[row][col] = word[0]

        return ret

    def exist(self, board: List[List[str]], word: str) -> bool:
        self.RowBoundary = len(board)
        self.ColBoundary = len(board[0])

        for row in range(len(board)):
            for col in range(len(board[row])):
                if self.existHelp(board, row, col, word):
                    return True

        return False
