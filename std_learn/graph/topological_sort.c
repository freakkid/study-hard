#define MAXSIZE 1000
enum {false, true};

typedef struct EdgeNode {   // 边表结点
    int adjvex;             // 邻接点域，存储该顶点的下标
    int weight;             // 权值
    struct EdgeNode *next;  // 链域，指向下一个邻接点
} EdgeNode;

typedef struct VertexNode {    // 顶表结点
    int in;                     // 入度
    int data;                   // 对应的下标
    EdgeNode *firstedge;        // 边表头指针
} VertexNode, AdjList[MAXSIZE];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} graphAdjList, *GraphAdjList;

// 拓扑排序，若有回路返回false,否则输出拓扑结构并返回true
int TopologicalSort(GraphAdjList GL) {
    EdgeNode *e;
    int gettop;     // 获得栈顶元素
    int count = 0;  // 用于统计输出顶点的个数
    // 建栈存储入度为0的顶点
    int *stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (int i = 0; i < GL->numVertexes; i++)
        if (GL->adjList[i].in == 0) // 入度为0的顶点入栈
            stack[++top] = i;
    while (top) {
        gettop = stack[top--];      // 出栈
        printf("%d -> ", GL->adjList[gettop].data);
        ++count;                    // 输出结点数加1

        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            int k = e->adjList;
            if (!(--GL->adjList[k].in)) // 将k号结点的入度减1，判断是否为0
                stack[++top] = k;       // 入度为0的顶点入栈
        }
    }
// 如果count小于顶点数
    if (count < GL->numVertexes)
        return false;
    else
        return true;
}