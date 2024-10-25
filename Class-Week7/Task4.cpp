# include<iostream>
#include <queue>
using namespace std;

bool comparingQueue(queue<int> q1, queue<int> q2)
{
    if(q1.empty() && q2.empty())
        return true;
    if(q1.empty() || q2.empty())
        return false;
        
    int a = q1.front();
    q1.pop();
    int b = q2.front();
    q2.pop();
    return comparingQueue(q1, q2) && (a == b);
}

int main()
{
    queue<int> q1;
    queue<int> q2;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(5);
    q2.push(5);

    cout << comparingQueue(q1, q2);
    return 0;
}