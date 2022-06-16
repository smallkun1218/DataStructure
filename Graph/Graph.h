//
// Created by luck on 2021/9/12.
//

#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H
#include "bits/stdc++.h"

const int MAX_VERTEX = 10;

typedef int DataType;

class MGraph{
private:
    DataType vertex[MAX_VERTEX]{};
    int arc[MAX_VERTEX][MAX_VERTEX]{};
    int vertexNum{}, arcNum{};
    void DFS(int v);
public:
    MGraph(const DataType v[], int n, int e);
    ~MGraph();
    void DFSTraverse(int v);
    void BFSTraverse(int v);
    void test(){
        for (int i = 0; i < vertexNum; ++i) {
            for (int j = 0; j < vertexNum; ++j) {
                std::cout << arc[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

MGraph::MGraph(const DataType *v, int n, int e) {
    vertexNum = n;
    arcNum = e;
    for (int i = 0; i < vertexNum; ++i) {
        vertex[i] = v[i];
    }
    for (int i = 0; i < vertexNum; ++i) {
        for (int j = 0; j < vertexNum; ++j) {
            arc[i][j] = 0;
        }
    }
    for (int i = 0; i < arcNum; ++i) {
        int vi, vj;
        std::cin >> vi >> vj;
        arc[vi][vj] = 1;
        arc[vj][vi] = 1;
    }
}

int visited[20];
void MGraph::DFSTraverse(int v) {
    memset(visited, 0, sizeof(visited));
    DFS(v);
    std::cout << std::endl;
}

void MGraph::DFS(int v){
    int j;
    std::cout << vertex[v] << " ";
    visited[v] = 1;
    for(j = 0;j < arcNum;j++){
        if (arc[v][j] == 1 && !visited[j])
            DFS(j);
    }
}

void MGraph::BFSTraverse(int v) {
    memset(visited, 0, sizeof(visited));
    std::queue<DataType> Q;
    std::cout << vertex[v] << " ";
    visited[v] = 1;
    Q.push(vertex[v]);
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        for (int j = 0; j < arcNum; ++j) {
            if (arc[v][j] == 1 && !visited[j]){
                std::cout << vertex[j] << " ";
                visited[j] = 1;
                Q.push(vertex[j]);
            }
        }
    }
    std::cout << std::endl;
}

MGraph::~MGraph() {

}

typedef struct ArcNode{
    int adjvex;
    ArcNode * next;
}ArcNode;

typedef struct VertexNode{
    DataType vertex;
    ArcNode * firstEdge;
}VertexNode;

class ALGraph{
private:
    VertexNode adjList[MAX_VERTEX]{};
    int vertexNum, arcNum;
    void DFS(int v);
public:
    ALGraph(const DataType v[], int n, int e);
    ~ALGraph();
    void DFSTraverse(int v);
    void BFSTraverse(int v);

    void test(){

        ArcNode * p = adjList[0].firstEdge;
        while(p != nullptr){
            std::cout << p->adjvex << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

};

ALGraph::ALGraph( const DataType *v, int n, int e) {
    vertexNum = n;
    arcNum = e;
    for (int i = 0; i < vertexNum; ++i) {
        adjList[i].vertex = v[i];
        adjList[i].firstEdge = nullptr;
    }

    for (int i = 0; i < arcNum; ++i) {
        int vi, vj;
        std::cin >> vi >> vj;
        auto * s = new ArcNode;
        s->adjvex = vj;
        s->next = adjList[vi].firstEdge;
        adjList[vi].firstEdge = s;
    }
}

void ALGraph::DFSTraverse(int v) {
    memset(visited, 0, sizeof(visited));
    DFS(v);
    std::cout << std::endl;
}

void ALGraph::DFS(int v) {
    ArcNode * p;
    int j;
    std::cout << adjList[v].vertex << " ";
    visited[v] = 1;
    p = adjList[v].firstEdge;
    while(p != nullptr){
        if (!visited[p->adjvex]){
            DFS(p->adjvex);
        }
        p = p->next;
    }
}

void ALGraph::BFSTraverse(int v) {
    std::queue<DataType> Q;
    memset(visited, 0, sizeof(visited));

    std::cout << adjList[v].vertex << " ";
    visited[v]=1;
    Q.push(adjList[v].vertex);

    while(!Q.empty()){
        int k = Q.front();
        Q.pop();
        ArcNode * p = adjList[k].firstEdge;
        while(p != nullptr){
            int j = p->adjvex;
            if (!visited[j]){
                std::cout << adjList[j].vertex << " ";
                visited[j] = 1;
                Q.push(j);
            }
            p = p->next;
        }
    }

}

ALGraph::~ALGraph() = default;





#endif //DATASTRUCTURE_GRAPH_H
