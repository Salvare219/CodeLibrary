class Stack:
    # initialize your data structure here.
    def __init__(self):
        self.len=0
        self.que=[]

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.que.append(x)
        self.len+=1
    # @return nothing
    def pop(self):
        self.que.pop()
        self.len-=1
    # @return an integer
    def top(self):
        return self.que[self.len-1]

    # @return an boolean
    def empty(self):
        return self.len==0