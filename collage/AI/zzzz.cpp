#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long minRequestTime(vector<int> &requestedServers, vector<int> &transitionTime)
{
    int m = transitionTime.size();
    long totalTime = 0;
    int current = 1;  // Start at server 1 (1-based indexing)
    int curr_idx = 0; // Index for transitionTime
    // Loop through each requested server
    for (int i = 0; i < requestedServers.size(); i++)
    {
        // If the requested server is out of bounds, skip
        if (requestedServers[i] < 1 || requestedServers[i] > m)
        {
            cout << "Requested server " << requestedServers[i] << " is out of bounds." << endl;
            continue; // Skip this request
        }
        // If the requested server is the same as the current server, skip
        if (current == requestedServers[i])
            continue; // Already at the requested server
        // Calculate clockwise distance (current → target)
        int clockwise = 0;
        int j = current;
        while (j != requestedServers[i])
        {
            clockwise += transitionTime[(j - 1)]; // Time to move from server j to adjacent
            j = (j % m) + 1;                      // Move clockwise
        }
        // Calculate counter-clockwise distance (current → target)
        int counter = 0;
        j = current;
        while (j != requestedServers[i])
        {
            counter += transitionTime[(j - 1)]; // Time to move from server j to adjacent
            j = ((j - 2 + m) % m) + 1;          // Move counter-clockwise
        }
        cout << "Current: " << current << ", Target: " << requestedServers[i] << endl;
        cout << "Clockwise: " << clockwise << ", Counter-clockwise: " << counter << endl;
        // Choose the shorter path
        totalTime += min(clockwise, counter);
        current = requestedServers[i]; // Update current position
    }
    return totalTime;
}

int main()
{
    // transitionTime[i] is the time to move from server i+1 to any adjacent server
    vector<int> transitionTime = {1, 2};      // Time for servers 1, 2, 3
    vector<int> requestedServers = {1, 2, 1}; // Sequence of visits

    cout << "Total time: " << minRequestTime(requestedServers, transitionTime) << endl; // Expected: 4
    return 0;
}