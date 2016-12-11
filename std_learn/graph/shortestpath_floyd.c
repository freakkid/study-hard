typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
// 因为是求所有顶点到所有顶点的最短路径，所以Pathmatirx，ShortPathTable是二维数组

// Floyd算法，求网图G中的各顶点v到其他顶点w最短路径P[v][w]
void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D) {
    int v, w, k;
    // 初始化D与P
    for (v = 0; v < G.numVertexes; v++)
        for (w = 0; w < G.numVertexes; w++) {
            (*D)[v][w] = G.matrix[v][w];
            (*P)[v][w] = w;
        }
    
    for (k = 0; k < G.numVertexes; k++)
        for (v = 0; v < G.numVertexes; v++)
            for (w = 0; w < G.numVertexes; w++)
                // 如果经过下标为k顶点路径比原两点间路径更短
                // 将当前两点间的权值设为更小的一个
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];    // 路径设置经过下标为k的顶点
                }
            
} 