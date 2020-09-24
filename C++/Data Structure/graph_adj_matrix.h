/*
 * File: graph_adj_matrix.h
 * Project: Data Structure
 * File Created: Thursday, 24th September 2020 6:09:02 pm
 * Author: Jongyeon Yoon (0417yjy@naver.com)
 * -----
 * Last Modified: Thursday, 24th September 2020 6:19:20 pm
 * Modified By: Jongyeon Yoon (0417yjy@naver.com>)
 * -----
 * Copyright 2020 Jongyeon Yoon
 */

#include <iostream>
#include <queue>

using namespace std;

class Graph
{
public:
    Graph(int size);
    ~Graph();
    void insert_undirected_edge(int v, int w);
    void insert_undirected_edge(int v, int w, int weight);
    void insert_directed_edge(int v, int w);
    void insert_directed_edge(int v, int w, int weight);

    void dfs_search(int v_idx);
    void bfs_search(int v_idx);

private:
    void initialize_visited();
    void free_visited();
    void dfs_recursive(int v_idx);
    queue<int> bfs_queue;
    bool *visited;
    int **adj_matrix;
    int vertex_num;
};