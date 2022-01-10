#include <iostream>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("srevni.in");
ofstream fout("srevni.out");

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<vector<int>> listaAd;

void dfs(int nod, int c, int viz[], int cost[])
{
    viz[nod] = 1;
    cost[nod] = c;

    for(auto vecin : listaAd[nod])
        if(!viz[vecin])
            dfs(vecin, c, viz, cost);
}

int main()
{
    int N, M, c, x, y;

    fin >> N >> M;

    int viz[N+1] = {0}, cost[N+1];


    for(int i = 1; i <= N; i++)
    {
        fin >> c;
        cost[i] = c;
        pq.push(make_pair(c, i));
    }

    listaAd.resize(N+1);
    for(int i = 0; i < M; i++)
    {
        fin >> x >> y;
        listaAd[y].push_back(x);
    }

    while(!pq.empty())
    {
        c = pq.top().first;
        int nod = pq.top().second;
        pq.pop();

        if(!viz[nod])
            dfs(nod,c,viz,cost);
    }

    for(int i = 1; i <= N; i++)
        fout << cost[i] << " ";

    fin.close();
    fout.close();

    return 0;
}
