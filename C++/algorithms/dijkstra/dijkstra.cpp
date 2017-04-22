//
// Created by Mahidhar Rajala on 2/15/17.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct GraphVertex
{
    pair<int, int> m_distance = {numeric_limits<int>::max(), 0};
    vector<pair<GraphVertex&, int>> m_edges;
    int m_id;
    const GraphVertex* mp_pred = nullptr;
};

struct Compare
{
    bool operator() (const GraphVertex* lhs, const GraphVertex* rhs)
    {
        return (lhs->m_distance.first < rhs->m_distance.first ||
                (lhs->m_distance.first == rhs->m_distance.first &&
                 lhs->m_distance.second < rhs->m_distance.second));
    }
};

struct Dijkstra
{
    void operator () (GraphVertex* s, GraphVertex* t)
    {
        s->m_distance = {0, 0};
        std::set<GraphVertex*, Compare> node_set;
        node_set.emplace(s);

        while (!node_set.empty())
        {
            GraphVertex* u = *node_set.cbegin();
            if (u->m_id == t->m_id) break;
            node_set.erase(node_set.cbegin());

            for (const auto& v : u->m_edges)
            {
                int v_distance = u->m_distance.first + v.second;
                int v_num_edges = u->m_distance.second + 1;
                if (v.first.m_distance.first > v_distance ||
                    (v.first.m_distance.first == v_distance &&
                     v.first.m_distance.second > v_num_edges))
                {
                    node_set.erase(&v.first);
                    v.first.mp_pred = u;
                    v.first.m_distance = {v_distance, v_num_edges};
                    node_set.emplace(&v.first);
                }
            }
        }
    }
};