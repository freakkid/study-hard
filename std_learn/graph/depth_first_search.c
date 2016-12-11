typedef int Boolean;        // FALSE 或 TRUE
Boolean visited[MAX];       // 访问标志数组
// 邻接矩阵 深度优先递归算法
void DFS(MGraph G, int i) {
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);
    for (int j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j]) // G.arc[i][j] != INFINITY
            DFS(G, j); 
}
// 邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G) {
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    for (int i = 0; i < G.numVertexes; i++)
        if (!visited[i]) // 对未访问的顶点调用DFS，若是连通图，只会执行一次
            DFS(G, i);
}

// 邻接表的深度优先递归算法
void DFS(GraphAdjList GL, int i){
    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);
    EdgeNode *p = GL->adjList[i].firstedge;
    while (p) {
        if (!visited[p->adjList])
            DFS(GL, p->adjList);
        p = p->next;
    }
}
// 邻接表的深度遍历操作
void DFSTraverse(GraphAdjList GL) {
    for (int i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    for (int i = 0; i < GL->numVertexes; i++)
        if (!visited[i])
            DFS(GL, i);
}