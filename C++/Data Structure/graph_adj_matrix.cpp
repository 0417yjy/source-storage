/*
 * File: graph_adj_matrix.cpp
 * Project: Data Structure
 * File Created: Thursday, 24th September 2020 6:11:37 pm
 * Author: Jongyeon Yoon (0417yjy@naver.com)
 * -----
 * Last Modified: Thursday, 24th September 2020 6:30:48 pm
 * Modified By: Jongyeon Yoon (0417yjy@naver.com>)
 * -----
 * Copyright 2020 Jongyeon Yoon
 */

#include <iostream>
#include <queue>
#include "graph_adj_matrix.h"

using namespace std;

Graph::Graph(int size) {
    visited = NULL;
    vertex_num = size;
    adj_matrix = new int* [size];

    // initialize adjacency matrix
    for (int i = 0; i < size; i++) {
        adj_matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    // free adjacency matrix memory
    for (int i = 0; i < vertex_num; i++) {
        delete[]adj_matrix[i];
    }
    delete[]adj_matrix;
}

void Graph::insert_undirected_edge(int v, int w) {
    adj_matrix[v][w] = 1;
    adj_matrix[w][v] = 1;
}

void Graph::insert_undirected_edge(int v, int w, int weight) {
    adj_matrix[v][w] = weight;
    adj_matrix[w][v] = weight;
}

void Graph::insert_directed_edge(int v, int w) {
    adj_matrix[v][w] = 1;
}

void Graph::insert_directed_edge(int v, int w, int weight) {
    adj_matrix[v][w] = weight;
}

void Graph::dfs_search(int v_idx) {
    initialize_visited();

    dfs_recursive(v_idx);
    cout << endl;
    
    free_visited();
}

void Graph::bfs_search(int v_idx) {
    initialize_visited();
    int current_idx = v_idx;

    bfs_queue.push(current_idx);
    visited[current_idx] = true;
    do {
        current_idx = bfs_queue.front();
        bfs_queue.pop();
        cout << current_idx + 1 << ' '; // operation

        for (int i = 0; i < vertex_num; i++) {
            if (adj_matrix[current_idx][i] == 1) {
                if (visited[i] == false) {
                    visited[i] = true;
                    bfs_queue.push(i);
                }
            }
        }
    } while (!bfs_queue.empty());

    free_visited();
}

void Graph::dfs_recursive(int v_idx) {
    if (!visited[v_idx]) {
        visited[v_idx] = true;
        cout << v_idx + 1 << ' '; // operation

        for (int i = 0; i < vertex_num; i++) {
            if (adj_matrix[v_idx][i] == 1) {
                dfs_recursive(i);
            }
        }
    }
}

void Graph::initialize_visited() {
    visited = new bool[vertex_num];
    for (int i = 0; i < vertex_num; i++) {
        visited[i] = false;
    }
}

void Graph::free_visited() {
    delete[]visited;
}