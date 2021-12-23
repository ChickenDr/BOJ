#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, pare[10001], resualt = 0, cnt = 0;

int find(int n){
    if(pare[n] < 0) return n;
    return pare[n] = find(pare[n]);
}

bool merge(int v1, int v2){
    v1 = find(v1);
    v2 = find(v2);

    if(v1 == v2) return false;
    pare[v2] = v1;
    return true;
}

class Edge{
    public:
        pair<int, int> node;
        long long dist;

        Edge(int from, int to, long long dist){
            this->node.first = from;
            this->node.second = to;
            this->dist = dist;
        }

        bool operator < (Edge &edge){
            return this->dist < edge.dist;
        }
};

int main(){
    cin >> n >> m;

    vector<Edge> v;
    for (int i = 0; i < m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;

        v.push_back(Edge(from, to, w));
    }

    memset(pare, -1, sizeof(pare));
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
    {
        if(merge(v[i].node.first, v[i].node.second)){
            resualt += v[i].dist;
        }
    }
    
    cout << resualt;
    return 0;
}