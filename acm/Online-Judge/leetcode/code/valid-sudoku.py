class Solution:
    # @param {character[][]} board
    # @return {boolean}
    def isValidSudoku(self, board):
        f=0
        for i in xrange(9):
            s=set()
            for j in xrange(9):
                if board[i][j]!='.' and board[i][j] in s:
                    f=1
                s.add(board[i][j])
        for i in xrange(9):
            s=set()
            for j in xrange(9):
                if board[j][i]!='.' and board[j][i] in s:
                    f=1
                s.add(board[j][i])
        for i in xrange(9):
            s=set()
            for j in xrange(9):
                x=i/3*3+j/3
                y=i%3*3+j%3
                if board[x][y]!='.' and board[x][y] in s:
                    f=1
                s.add(board[x][y])
        return not f
                
                
                
                