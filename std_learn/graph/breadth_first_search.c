// 广度优先遍历
// 邻接矩阵
void BFSTravse(MGraph G) {
    Queue Q;
    InitQueue(&Q);
    
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    
    for (int i = 0; i < G.numVertexes; i++)
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", G.vexs[i]);
            
            EnQueue(&Q, i); // 进入队列

            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);    // 将队头的顶点出队列
                for (int j = 0; j < G.numVertexes; j++) {
                    if (G.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = TRUE;
                        printf("%c ", G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
}
// 邻接表
void BFSTravse(GraphAdjList GL) {
    Queue Q;
    InitQueue(&Q);

    for (int i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    
    for (int i = 0; i < GL->numVertexes; i++)
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", GL->adjList[i]);
            
            EnQueue(&Q, i);

            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);
                EdgeNode *p = GL->adjList[i].firstedge;
                while (p) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", GL->adjList[p->adjList].data);
                        EnQueue(&Q, i);
                    }
                    p = p->next;
                }
            }
        }
}