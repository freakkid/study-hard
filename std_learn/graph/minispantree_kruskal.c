// kruskal算法生成最小生成树

// 对边集数组Edge结构的定义
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

int Find(int *parent, int f) {  // 查找连线顶点的尾部下标
    while (parent[f] > 0)
        f = parent[f];
    return f;
}

void MiniSpanTree_Kruskal(MGraph G) {
    Edge edges[MAXEDGE];    // 定义边集数组
    int parent[MAXVEX];     // 判断边与边是否形成环路
    
    // 省略将邻接矩阵G转化成边集数组edges并按权由小到大排序的代码

    for (int i = 0; i < G.numVertexes; i++)
        parent[i] = 0;

    for (int i = 0; i < G.numEdges; i++) {
        int n = Find(parent, edges[i].begin);
        int m = Find(parent, edges[i].end);
        if (n != m) {   // 说明此边没有与现成的生成树形成回路
            parent[n] = m;  // 表示该点已经在生成树集合中
            printf("(%d, %d) %d", edge[i].begin, edge[i].end, edge[i].weight);
        }
    }
}