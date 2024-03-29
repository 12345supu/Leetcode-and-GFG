//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isCyclic(int N, vector<int> adj[])
    {
        int indegree[N] = {0};
        for(int i = 0; i < N; i++)
        {
            for(auto v : adj[i])
            {
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < N; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(indegree[i] > 0)
                return true;
        }
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(auto i : prerequisites)
	    {
	        adj[i.first].push_back(i.second);
	    }
	    if(isCyclic(N, adj) == false)  
	        return true;
	    else
	        return false;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends