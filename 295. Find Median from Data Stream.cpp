#include <queue>
using namespace std;
class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (small.size() == large.size())
        {
            if (small.empty() || num <= large.top())
                small.push(num);
            else
            {
                small.push(large.top());
                large.pop();
                large.push(num);
            }
        }
        else
        {
            if (large.empty())
            {
                if (num <= small.top())
                {
                    large.push(small.top());
                    small.pop();
                    small.push(num);
                }
                else
                    large.push(num);
            }
            else if (num >= small.top())
            {
                large.push(num);
            }
            else
            {
                large.push(small.top());
                small.pop();
                small.push(num);
            }
        }
    }

    double findMedian()
    {
        if (small.size() == large.size())
            return (double)(small.top() + large.top()) / 2;
        else
            return small.top();
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */