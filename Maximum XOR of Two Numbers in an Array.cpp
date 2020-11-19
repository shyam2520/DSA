#define SIZE 31
class Trie {
public:
    vector<Trie*> bit;
    bool isEnd;
    
    Trie() {
        this->bit.resize(2, NULL);
        this->isEnd = false;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& a)
    {   
        const int n = a.size();
        if(n == 1) {
            return 0;
        }
        
        Trie *root = new Trie();
        insert(root, a[0]);

        int ans = INT_MIN;
        for(int i = 1 ; i < n ; i++)
        {
            ans = max(ans, query(root, a[i]));
            insert(root, a[i]);
        }
        return ans;
    }
    
    void insert(Trie *root, int num)
    {
        Trie *currNode = root;
        for(int i = SIZE ; i >= 0 ; i--) 
        {
            int currBit = ((num >> i) & 1);
            if(currNode->bit[currBit] == NULL) 
            {
                currNode->bit[currBit] = new Trie();
            }
            currNode = currNode->bit[currBit];
        }
        currNode->isEnd = true;
    }

    int query(Trie *root, int num)
    {
        Trie *currNode = root;
        int xorValue = 0;

        for(int i = SIZE ; i >= 0 ; i--)
        {
            int currBit = ((num >> i) & 1);
            if(currNode->bit[!currBit] != NULL) 
            {
                xorValue |= (1 << i);
                currNode = currNode->bit[!currBit];
            }
            else if(currNode->bit[currBit] != NULL) 
            {
                currNode = currNode->bit[currBit];
            }
            else break;
        }
        return xorValue;
    }
};