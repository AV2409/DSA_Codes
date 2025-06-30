for (int i = 0; i < V; i++)
    {
        if(!visited[i])
            dfs(i, st, visited, adj);
    }