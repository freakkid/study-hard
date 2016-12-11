// Prim 最小生成树
// 先构造邻接矩阵
void MiniSpanTree_Prim(MGraph G) {
    int adjvex[MAXVEX];     // 保存相关顶点的下标 
            // adjvex[j] = Xi表示 在lowcost[X] = 0的X中，顶点Xi和顶点j的距离最短
    int lowcost[MAXVEX];    // 保存相关顶点的边的权值
            // lowcost[x] = 0说明 顶点x已经加入生成树中
    
    lowcost[0] = 0; // 初始化第一个权值为0，即v0加入生成树
            // lowcost的值为0，在这里表示下标为0的顶点已经加入生成树
    adjList[0] = 0; // 初始化第一个顶点下标为0
    
    for (int i = 1; i < G.numVertexes; i++) {   // 循环顶点
        lowcost[i] = G.arc[0][i];   // 将v0顶点与其它点的权值导入数组
        adjvex[i] = 0;              // 初始化为v0的下标 
    }
    for (int i = 1; i < G.numVertexes; i++) {
        minEdge = INFINITY;     // ∞
        int j = 1, minIndex = 0;
        // 寻找权值最小的边
        while (j < G.numVertexes) {
            if (lowcost[j] != 0 && lowcost[j] < minEdge) { // 权值为0说明是它自己
                minEdge = lowcost[j];
                minIndex = j;
            }
            ++j;
        }
        
        printf("(%d, %d)", adjvex[minIndex], minIndex);
        lowcost[minIndex] = 0;      // 此顶点已经完成任务，加入最小生成树

        // lowcost和adjvex重新赋值
        for (j = 1; j < G.numVertexes; j++)
            if (lowcost[j] != 0 && lowcost[j] > G.arc[minIndex][j]) {
                lowcost[j] = G.arc[minIndex][j];
                adjvex[j] = minIndex;
            }

    }
}