class Solution:
    def removeStack(self,stack,k):
        if len(stack) and min([stack[-1][1],stack[-1][2]])==k:
            for i in range(2*k): 
                print(i)
                stack.pop()
                # print(stack)
        return stack

    def removeSubstring(self, s: str, k: int) -> str:
        # ((())())
        # stack - '(',open_cnt,closed_cnt 
        # only point the stack gets rest if the prev ')' and curr  '('
        stack = [] 
        for ch in s: 
            if len(stack)==0: 
                if ch=='(': stack.append(['(',1,0])
                else: stack.append([')',0,1])
            else: 
                prev = stack[-1] 
                if prev[0] == ch: 
                    if ch=='(': stack.append([ch,prev[1]+1,prev[2]])
                    else: stack.append([ch,prev[1],prev[2]+1])
                else: 
                    if prev[0]=='(': stack.append([ch,prev[1],1])
                    else: stack.append([ch,1,0])
            # print(stack)
            stack = self.removeStack(stack,k)
        ans = ""
        while len(stack): 
            ans+=stack[-1][0]
            stack.pop()
        rev = ans[::-1]
        return rev