class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        m,n = len(version1),len(version2)
        i,j = 0,0 
        while i<m or j<n: 
            v1,v2 =0,0 
            while i<m and version1[i]!='.':
                v1=v1*10+int(version1[i]) 
                i+=1
            while j<n and version2[j]!='.':
                v2=v2*10+int(version2[j])
                j+=1
            if v1>v2:
                return 1
            elif v2>v1:
                return -1 
            i+=1 
            j+=1
        return 0
