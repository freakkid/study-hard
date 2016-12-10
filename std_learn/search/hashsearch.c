#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

typedef struct {
    int *elem;      // 数据元素存储基质，动态分配数组
    int count;      // 当前数据元素个数
} HashTable;
int m = 0;          // 散列表表长，全局变量

// 初始化散列表
int InitHashTable(HashTable *H) {
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return 1;
}
// 计算地址，散列函数
int Hash(int key) {
    return key % m;     // 除留余数法
}
// 插入关键字进散列表
void InsertHash(HashTable *H, int key) {
    int addr = Hash(key);               // 求散列地址
    while (H->elem[addr] != NULLKEY)    // 如果不为空，冲突
        addr = (addr + 1) % m;          // 开放定址法的线性探测
    H->elem[addr] = key;                // 直到有空位后插入关键字
}
// 散列表查找关键字
int SearchHash(HashTable H, int key, int *addr) {
    *addr = Hash(key);                  // 求散列地址
    while (H.elem[*addr] != key) {      // 不为空，冲突
        *addr = (*addr + 1) % m;        // 开放定址法的线性探测
        if (H.elem[*addr] == NULLKEY)   // 关键字不存在
            return UNSUCCESS;
    }
    return SUCCESS;
}