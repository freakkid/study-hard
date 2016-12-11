// Dijkstra算法
// 不是一下子求出v0到v8的最短路径，而是一步步求出它们之间顶点的最短路径，
// 过程都是基于已经求出的最短路径的基础上，求出更远顶点的路径
#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];    // 存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX]; // 存储到各点最短路径的权值和

// Dijkstra算法,求有向网G的v0顶点到其余顶点最短路径P[v],带权长度D[v],O(n2)
// P[v]的值为前驱顶点的下标，D[v]表示v0到v的最短路径长度和
void ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D) {
    int v, minIndex, w, minEdge;
    int final[MAXVEX];  // final[w]=1表示已经确定顶点v0和Vw的最短路径

    for (v = 0; v < G.numVertexes; v++) {
        final[v] = 0;   // 初始化为未知最短路径的状态
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = 0;    // 初始化路径数组P为0
    }

    (*D)[v0] = 0;       // v0到v0路径长度为0
    final[v0] = 1;      // v0到v0之间的最短路径
    
    // 开始主循环，每次求得v0到某个v顶点的最短路径
    for (v = 1; v < G.numVertexes; v++) {
        minEdge = INFINITY;

        for (w = 0; w < G.numVertexes; w++) {
            if (!final[w] && (*D)[w] < min) {
                minIndex = w;
                minEdge = (*D)[w];  // w顶点离v0顶点
            }
        }

        final[minIndex] = 1;               // w顶点离v0顶点的最短路径确定

        // 修正为当前最短路径和距离
        for (w = 0; w < G.numVertexes; w++) {
            // 如果经过v顶点的路径比已知的路径还要短的话
            if (!final[w] && (minEdge + G.arc[minIndex][w]) < (*D)[w]) {
                (*D)[w] = minEdge + G.arc[minIndex][w];
                (*P)[w] = minIndex;
            }
        }
    }

}
// 最终完成的时候final数组为{1,1,1,1,1,1,1,1,1}
// 如果要找任何一点到其他点的最短路径，应该是在原有的算法上再来一次循环 O(n3)
