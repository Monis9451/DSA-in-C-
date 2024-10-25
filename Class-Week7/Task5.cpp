#include <iostream>
#include <queue>
using namespace std;

int findingMax(queue<int>& q)
{
    int Max = q.front();
    q.pop();
    queue<int> tempQ;

    while(!q.empty())
    {
        if(q.front() > Max)
        {
            tempQ.push(Max);
            Max = q.front();
        }
        else
        {
            tempQ.push(q.front());
        }
        q.pop();
    }

    while(!tempQ.empty())
    {
        q.push(tempQ.front());
        tempQ.pop();
    }
    return Max;
}

void sortQueue(queue<int>& q)
{
    if(q.empty())
        return;
    int maxElement = findingMax(q);
    sortQueue(q);
    q.push(maxElement);
}

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << "|" << q.front() << "|" << endl;
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(5);

    print(q);

    sortQueue(q);

    print(q);

    return 0;
}