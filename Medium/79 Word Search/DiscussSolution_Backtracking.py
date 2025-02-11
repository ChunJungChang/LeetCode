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
        # Mark the choice before exploring further.
        board[row][col] = '#'
        # Step 3: Explore the 4 neighbor directions in DFS.
        for rowOffset, colOffset in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ret = self.existHelp(board, row + rowOffset, col + colOffset, word[1:])
            if ret:
                break
        # Step 4: Revert the change and return the result.
        board[row][col] = word[0]

        return ret

    def exist(self, board: List[List[str]], word: str) -> bool:
        self.RowBoundary = len(board)
        self.ColBoundary = len(board[0])

        for row in range(self.RowBoundary):
            for col in range(self.ColBoundary):
                if self.existHelp(board, row, col, word):
                    return True

        return False
