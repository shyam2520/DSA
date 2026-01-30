class Solution:
    def validPop(self,topch,ch): 
        if (topch=='(' and ch==')' ) or (topch=='[' and ch==']') or (topch=='{' and ch=='}'):
            return True 
        return False
    def isValid(self, s: str) -> bool:
        st = [] 
        for ch in s: 
            if ch == '(' or ch=='[' or ch=='{':
                st.append(ch) 
            else: 
                if st and self.validPop(st[-1],ch):
                    st.pop() 
                else: 
                    st.append(ch)
        
        return len(st)==0