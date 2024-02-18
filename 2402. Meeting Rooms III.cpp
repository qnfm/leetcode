#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n);
        vector<long long> roomavailtime(n);
        int j = 0;
        for (auto &meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableRoom = 0;
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (roomavailtime[i] <= start)
                {
                    found = true;
                    count[i]++;
                    roomavailtime[i] = end;
                    break;
                }

                if (minRoomAvailabilityTime > roomavailtime[i])
                {
                    minRoomAvailabilityTime = roomavailtime[i];
                    minAvailableRoom = i;
                }
            }
            if (!found)
            {
                roomavailtime[minAvailableRoom] += end - start;
                count[minAvailableRoom]++;
            }
        }
        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++)
        {
            if (count[i] > maxMeetingCount)
            {
                maxMeetingCount = count[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};