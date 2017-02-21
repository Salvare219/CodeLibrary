class Solution(object):
    ans=[]
    use=[]
    
    def get(self,n):
        t=[]
        for i in xrange(n):
            z=""
            for j in xrange(n):
                if self.use[i][j]>=10000:
                    z+='Q'
                else:
                    z+='.'
            t.append(z)
        return t
        
    def put(self,x,y,n,t):
        for i in xrange(n):
            self.use[x][i]+=t
            self.use[i][y]+=t
            if y-x+i>=0:
                self.use[i][y-x+i]+=t
            if y+x-i<n:
                self.use[i][y+x-i]+=t
                
    def dfs(self,s,n):
        if s==n:
            self.ans.append(self.get(n))
        else:
            for i in xrange(n):
                if self.use[s][i]==0:
                    self.use[s][i]=10000
                    self.put(s,i,n,1)
                    self.dfs(s+1,n)
                    self.put(s,i,n,-1)
                    self.use[s][i]=0
                
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.ans=[]
        self.use=[[0 for col in range(25)] for row in range(25)]
        self.dfs(0,n)
        return self.ans
        
        
        
        
        