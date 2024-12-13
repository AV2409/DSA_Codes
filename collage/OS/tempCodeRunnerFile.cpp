Process p[5];
    p[0] = Process(1, 0, 3, 3);
    p[1] = Process(2, 1, 4, 2);
    p[2] = Process(3, 2, 6, 4);
    p[3] = Process(4, 3, 4, 6);
    p[4] = Process(5, 5, 2, 10);
    int n = 5;
    calculate(p, n);