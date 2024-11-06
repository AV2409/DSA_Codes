int turnAround[n];
    int waiting[n];
    int completion[n];
    int total = 0;
    int t_tat = 0;
    int t_wait = 0;
    for (int i = 0; i < n; i++)
    {
        total += burst[i];
        completion[i] = total;
        turnAround[i] = completion[i] - arrival[i];
        waiting[i] = turnAround[i] - burst[i];
        t_tat += turnAround[i];
        t_wait += waiting[i];
    }

    cout << "Process\t  Arrival\t  Burst\t  Completion\t  TurnAround\t  Waiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << "  " << process[i] << "\t    " << arrival[i] << "\t\t   " << burst[i] << "\t\t" << completion[i] << "\t\t" << turnAround[i] << "\t\t" << waiting[i] << endl;
    }
    float avg_tat = (float)t_tat / n;
    float avg_wait = (float)t_wait / n;
    cout << endl
         << "avg waiting: " << avg_wait;
    cout << endl
         << "avg tat: " << avg_tat;