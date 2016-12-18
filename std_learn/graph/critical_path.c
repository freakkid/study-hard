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

int *etv, *ltv; // 事件最早发生时间和最迟发生时间数组
int *stack;     // 用于存储拓扑序列的栈
int top2;       // stack2的指针， stack2存储拓扑序列

int TopologicalSort(GraphAdjList GL) {
    EdgeNode *e;
    int gettop;     // 获得栈顶元素
    int count = 0;  // 用于统计输出顶点的个数
    // 建栈存储入度为0的顶点
    int *stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (int i = 0; i < GL->numVertexes; i++)
        if (GL->adjList[i].in == 0) // 入度为0的顶点入栈
            stack[++top] = i;
    
    top2 = 0;                       // 初始化为0
    etv = (int*)malloc(GL->numVertexes * sizeof(int));  // 事件最早发生时间
    for (int i = 0; i < GL->numVertexes; i++)
        etv[i] = 0;
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));

    while (top) {
        gettop = stack[top--];      // 出栈
        ++count;                    // 输出结点数加1
        stack2[++top2] = gettop;    // 弹出的元素压入拓扑排序

        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            int k = e->adjList;
            if (!(--GL->adjList[k].in)) // 将k号结点的入度减1，判断是否为0
                stack[++top] = k;       // 入度为0的顶点入栈
            
            if ((etv[gettop] + e->weight) > etv[k]) // 求各顶点事件最早发生时间值
                etv[k] = etv[gettop] + e->weight;
        }
    }
    // 如果count小于顶点数
    if (count < GL->numVertexes)
        return false;
    else
        return true;
}
// 求关键路劲，GL为有向网，输出GL的各项关键活动
void CriticalPath(GraphAdjList GL) {
    EdgeNode *e;
    int gettop;
    int ete, lte;   // 声明活动最早发生时间和最迟发生时间变量

    TopologicalSort(GL);
    
    ltv = (int*)malloc(GL->numVertexes * sizeof(int));  // 事件最晚发生时间
    for (int i = 0; i < GL->numVertexes; i++)
        ltv[i] = etv[GL->numVertexes - 1];              // 初始化ltv
    
    while (top2) {
        gettop = stack2[top2--];        // 将拓扑序列出栈，后进先出
        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            k = e->adjList;
            if (ltv[k] - e->weight < ltv[gettop])   // 求各顶点事件最迟发生时间值
                ltv[gettop] = ltv[k] + e->weight;
        }

        for (int j = 0; j < GL->numVertexes; j++) { // 遍历各个点
            for (e = GL->adjList[j].firstedge; e; e = e->next) {    // 遍历点中的邻域
                k = e->adjvex;
                ete = etv[j];               // 活动最早发生时间
                lte = ltv[k] - e->weight;   // 活动最迟发生时间
                if (ete == lte)             // 两者相等即在关键路劲上
                    printf("<v%d, v%d> length: %d, ",
                    GL->adjList[j].data, GL->adjList[k].data, e->weight);
            }
        }
    }
}