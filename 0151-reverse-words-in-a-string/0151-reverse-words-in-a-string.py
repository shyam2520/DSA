class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.strip()
        list_words = list(filter(lambda x:len(x)>0,s.split(' ')))
        # print(list_words)
        n = len(list_words)
        for i in range(len(list_words)//2):
            list_words[i],list_words[n-1-i]=list_words[n-1-i],list_words[i]

        return ' '.join(list_words)
