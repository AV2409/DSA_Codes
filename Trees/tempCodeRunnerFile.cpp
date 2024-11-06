{
    vector<vector<int>> ans;
    queue<Node *> q;

    if (root == NULL)
    {
        return;
    }

    q.push(root);
    bool flag = 0;
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (flag)
            {
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
                level.push_back(temp->data);
            }

            else
            {

                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }
                level.push_back(temp->data);
            }
        }
        flag = !flag;
        ans.push_back(level);
    }
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        int n1 = ans[i].size();

        for (int j = 0; j < n1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}