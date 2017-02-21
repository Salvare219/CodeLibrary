class MinStack:
    # initialize your data structure here.
    def __init__(self):
        self.q=[]
        self.p=[]

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.q.append(x)
        if len(self.p)==0:
            self.p.append(len(self.q)-1)
        else:
            if self.q[self.p[len(self.p)-1]]>x:
                self.p.append(len(self.q)-1)

    # @return nothing
    def pop(self):
        self.q.pop()
        while len(self.p)>0 and self.p[len(self.p)-1]>=len(self.q):
            self.p.pop()

    # @return an integer
    def top(self):
        return self.q[len(self.q)-1]

    # @return an integer
    def getMin(self):
        return self.q[self.p[len(self.p)-1]]
        