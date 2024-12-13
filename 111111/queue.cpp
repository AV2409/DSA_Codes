#include <iostream>
#include <queue>
using namespace std;

int maxEqualSum(queue<int> &q1, queue<int> &q2, queue<int> &q3)
{
    // Calculate the initial sums of the three queues
    int sum1 = 0, sum2 = 0, sum3 = 0;

    // Calculate sum of queue 1
    queue<int> temp1 = q1; // Temporary queue to preserve original
    while (!temp1.empty())
    {
        sum1 += temp1.front();
        temp1.pop();
    }

    // Calculate sum of queue 2
    queue<int> temp2 = q2; // Temporary queue to preserve original
    while (!temp2.empty())
    {
        sum2 += temp2.front();
        temp2.pop();
    }

    // Calculate sum of queue 3
    queue<int> temp3 = q3; // Temporary queue to preserve original
    while (!temp3.empty())
    {
        sum3 += temp3.front();
        temp3.pop();
    }

    // Use a set to track the sums of the queues
    while (true)
    {
        // If all sums are equal, return the sum
        if (sum1 == sum2 && sum2 == sum3)
        {
            return sum1;
        }

        // If any sum becomes zero, it's impossible to equalize
        if (sum1 == 0 || sum2 == 0 || sum3 == 0)
        {
            return -1;
        }

        // Remove the largest sum queue
        if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= q1.front();
            q1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= q2.front();
            q2.pop();
        }
        else
        {
            sum3 -= q3.front();
            q3.pop();
        }
    }
}

int main()
{
    // Example input queues
    queue<int> q1, q2, q3;

    // Fill Queue 1
    q1.push(4);
    q1.push(2);
    q1.push(3);
    q1.push(8);

    // Fill Queue 2
    q2.push(1);
    q2.push(6);
    q2.push(2);
    q2.push(5);

    // Fill Queue 3
    q3.push(2);
    q3.push(3);
    q3.push(7);
    q3.push(4);

    // Calculate the maximum equal sum
    int result = maxEqualSum(q1, q2, q3);

    // Output the result
    cout << "Maximum Equal Sum: " << result << endl;

    return 0;
}
