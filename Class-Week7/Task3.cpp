#include <iostream>
#include <stack>
using namespace std;

void removeNegative(stack<int>& st)
{
    if(st.empty())
    {
        return;
    }
    int TopElement = st.top();
    st.pop();
    removeNegative(st);

    if(TopElement >= 0)
    {
        st.push(TopElement);
    }
}

int main() 
{
    stack<int> st;
    st.push(2);
    st.push(5);
    st.push(-1);
    st.push(3);
    st.push(-4);
    removeNegative(st);

    stack<int> temp;
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    while(!temp.empty())
    {
        cout << "|" << temp.top() << "|" << endl;
        temp.pop();
    }

    return 0;
}
