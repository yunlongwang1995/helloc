//
// Created by wangyunlong01 on 2022/6/21.
//
#include <limits>
#include <forward_list>

const int Inf = Inf;

// 邻接矩阵存储
void MatrixGraph() {
    const int vertexNum = 5;

    int graph[vertexNum][vertexNum] = {};
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[0][4] = 1;

    graph[1][0] = 1;
    graph[1][2] = 1;

    graph[2][0] = 1;
    graph[2][1] = 1;

    graph[3][0] = 1;
    graph[4][0] = 1;
}

// 邻接表
void LinkGraph() {
    const int vertexNum = 5;
    std::forward_list<int> linkGraph[vertexNum];

    linkGraph[0].push_front(1);
    linkGraph[0].push_front(2);
    linkGraph[0].push_front(3);
    linkGraph[0].push_front(4);

    linkGraph[1].push_front(0);
    linkGraph[1].push_front(2);

    linkGraph[2].push_front(0);
    linkGraph[2].push_front(1);

    linkGraph[3].push_front(0);
    linkGraph[4].push_front(0);
}

// 深度遍历


// 广度遍历



int main() {

}
