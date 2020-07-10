#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

typedef struct{
    int x, y;
} point;

typedef struct
{
    int x, idx;
} mountainElem;

typedef struct
{
    int idx;
    bool have;
} stackElem;

bool compare (point a, point b)
{
    if (a.y < b.y)
        return true;
    else if (a.y == b.y)
    {
        if (a.x < b.x)
            return true;
    }
    
    return false;
}

bool compare2 (mountainElem a, mountainElem b)
{
    if (a.x < b.x)
    return true;
    return false;
}

int main()
{
    int n, size, second = 1, idx = 1, ans1 = 0, ans2 = 0;
    vector <point> v;
    vector <mountainElem> mountain;
    stack <stackElem> st;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    
    rotate(v.begin(), min_element(v.begin(), v.end(), compare), v.end());
    v.push_back(v.front());
    
    for (int i = 0; i < n; i++)
    {
        if ((ll)v[i].y * v[i+1].y < 0)
        {
            mountain.push_back({v[i].x, idx});
            second++;
            if (second % 2)
                idx++;
        }
    }
    
    sort(mountain.begin(), mountain.end(), compare2);
    size = mountain.size();
    
    for (int i = 0; i < size; i++)
    {
        int idx = mountain[i].idx;
        
        if (st.empty())
        {
            st.push({idx, false});
            ans1++;
        }
        else{
            if (st.top().idx == idx)
            {
                if (!st.top().have)
                    ans2++;
                st.pop();
            }
            else
            {
                st.top().have = true;
                st.push({idx, false});
            }
        }
    }
    
    printf("%d %d", ans1, ans2);
    return 0;
}