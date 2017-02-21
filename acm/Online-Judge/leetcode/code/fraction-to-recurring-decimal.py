class Solution:
    # @param {string} s
    # @return {integer}
    def calculate(self, s):
        if s=='':
            return 0
        s=s.replace(' ','')
        s='('+s+')'
        sig=[]
        num=[]
        las=-1
        for x in s:
            if x=='+' or x=='-' or x==')':
                if las!=-1:
                    num.append(las)
                    while len(sig)>0 and (sig[len(sig)-1]=='+' or sig[len(sig)-1]=='-'):
                        if sig[len(sig)-1]=='+':
                            sig.pop()
                            num[len(num)-2]+=num[len(num)-1]
                            num.pop()
                        if sig[len(sig)-1]=='-':
                            sig.pop()
                            num[len(num)-2]-=num[len(num)-1]
                            num.pop()
                if x==')':
                    sig.pop()
                    while len(sig)>0 and (sig[len(sig)-1]=='+' or sig[len(sig)-1]=='-'):
                        if sig[len(sig)-1]=='+':
                            sig.pop()
                            num[len(num)-2]+=num[len(num)-1]
                            num.pop()
                        if sig[len(sig)-1]=='-':
                            sig.pop()
                            num[len(num)-2]-=num[len(num)-1]
                            num.pop()
                else:
                    sig.append(x)
                las=-1
            elif x=='(':
                sig.append(x)
            else:
                if las==-1:
                    las=ord(x)-ord('0')
                else:
                    las=las*10+ord(x)-ord('0')
        print(sig)
        print(num)
        while len(sig)>0 and (sig[len(sig)-1]=='+' or sig[len(sig)-1]=='-'):
            if sig[len(sig)-1]=='+':
                sig.pop()
                num[len(num)-2]+=num[len(num)-1]
                num.pop()
            if sig[len(sig)-1]=='-':
                sig.pop()
                num[len(num)-2]-=num[len(num)-1]
                num.pop()
        return num[0]
        
        
        
        