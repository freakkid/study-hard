//  邻接表 数组与链表相结合
typedef char VertexType;    // 顶点类型由用户对定义
typedef int EdgeType;       // 边上权值类型由用户定义

// 边表结点
typedef struct EdgeType {
    int adjvex;             // 邻接点域，存储该顶点对应的下标
    EdgeType weight;        // 用于存储权值，对于非网图可以不需要
    struct EdgeType *next;  // 指向下一个邻接点
} EdgeNode;

// 顶点表结点
typedef struct VertexType {
    VertexType data;        // 顶点域，存储顶点信息
    EdgeNode *firstedge;    // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;  // 图中当前顶点数和边数
} GraphAdjList;

// 建立无向图的邻接表结构
void CreateALGraph(GraphAdjList *G) {
    printf("输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);
    // 顶点表信息
    for (int i = 0; i < G->numVertexes; i++) {
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    // 边表信息
    EdgeNode *e;
    for (int k = 0; k < G->numVertexes; k++) {
        printf("输入边(vi, vj)上的顶点序号：\n");
        scanf("%d,%d", &i, &j);

        // 头插法
        e = (EdgeNode*)malloc(sizeof(EdgeNode)); // 边表结点
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        e->adjvex = j;  // 邻接序号为j

        e = (EdgeNode*)malloc(sizeof(EdgeNode)); // 边表结点
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
        e->adjvex = i;
    }

}