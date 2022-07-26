class Solution {
public:
    bool isSelfDividing(int n)
    {
        int m=n;
        while(n>0)
        {
            if(n%10==0 || m%(n%10)!=0)
                return false;
            n/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++)
        {
            if(isSelfDividing(i)==true)
                v.push_back(i);  
        }
        return v;
    }
};