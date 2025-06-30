#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort_kahn(vector<vector<int>> &adj, int V)
{
    vector<int> indeg(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
        {
            indeg[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        ans.push_back(ele);

        for (int it : adj[ele])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}
string findOrder(string dict[], int N, int K)
{
    string ans = "";
    vector<vector<int>> adj(K);

    for (int i = 0; i < N - 1; i++)
    {
        string st1 = dict[i];
        string st2 = dict[i + 1];
        int x = min(st1.size(), st2.size());
        int ptr = 0;
        for (int ptr = 0; ptr < x; ptr++)
        {
            if (st1[ptr] != st2[ptr])
            {
                adj[st1[ptr] - 'a'].push_back(st2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> temp = topoSort_kahn(adj, K);
    if (temp.size() == K)
    {
        for (auto i : temp)
        {
            ans = ans + char(i + 'a');
        }
    }
    return ans;
}

string alienOrder(vector<string> &words)
{
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indeg;

    // Initialize indegree for all unique characters
    for (auto &word : words)
    {
        for (char c : word)
        {
            indeg[c] = 0;
        }
    }

    // Build the graph
    for (int i = 0; i < words.size() - 1; i++)
    {
        string &w1 = words[i];
        string &w2 = words[i + 1];

        // Invalid case: prefix issue
        if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2)
        {
            return "";
        }

        int len = min(w1.size(), w2.size());
        for (int j = 0; j < len; j++)
        {
            if (w1[j] != w2[j])
            {
                adj[w1[j]].insert(w2[j]);
                indeg[w2[j]]++;
                break; // only first different char matters
            }
        }
    }

    // Topological Sort (Kahn's Algorithm)
    queue<char> q;
    for (auto &p : indeg)
    {
        if (p.second == 0)
        {
            q.push(p.first);
        }
    }

    string order = "";
    while (!q.empty())
    {
        char curr = q.front();
        q.pop();
        order += curr;

        for (char neighbor : adj[curr])
        {
            indeg[neighbor]--;
            if (indeg[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // If not all characters are used, then there was a cycle
    if (order.size() != indeg.size())
    {
        return "";
    }

    return order;
}

int main()
{

    return 0;
}