class Solution:
    def isValid(self, s: str) -> bool:
        st = [ ]
        
        opening = { ')' : '(',
                    ']' : '[',
                    '}' : '{'}
        
        for ch in s:
            if ch in ( '(','{','[' ):
                st.append(ch)
            elif st:
                if( st[-1] != opening[ch] ):
                    return False
                else:
                    st.pop()
            else:
                return False
            
        if st:
            return False
        return True