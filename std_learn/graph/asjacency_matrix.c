// 无向图 邻接矩阵 带权值
// 创建无向网图 时间复杂度是O(n + n2 + e)

typedef char VertexType;    // 顶点类型由用户定义
typedef int EdgeType;       // 边上的权值类型应由用户定义
#define MAXVEX 100          // 最大顶点数，应由用户定义
#define INFINITY 65535      // 65535 表示 ∞

typedef struct {
    VertexType vexs[MAXVEX];        // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];   // 邻接矩阵，边表
    int numVertexes, numEdges;      // 图中当前的顶点数和边数
} MGraph;

// 建立无向图的邻接矩阵
void CreateMGaph(MGraph *G) {
    printf("输入顶点数和边数(用,隔开)：\n");
    scanf("%d,%d", &G->numVertexes,, &G->numEdges); // 输入顶点数和边数
    // 输入顶点信息
    for (int i = 0; i < G->numVertexes; i++)
        scanf(&G->vexs[i]);
    // 初始化邻接矩阵
    for (int i = 0; i < G->numVertexes; i++)
        for (int j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;
    // 读入numEdges条边，建立邻接矩阵
    int w;
    for (int k = 0; k < G->numEdges; k++) {
        printf("输入边(vi, vj)上的下标i,j和权w:\n");
        scanf("%d,%d,%d", &i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = w;   // 无向图-矩阵对称
    }
}