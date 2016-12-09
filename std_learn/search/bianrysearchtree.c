// 二叉树顺序查找
enum Status {FALSE, TRUE};
// 二叉树的二叉链表结点结构定义
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 递归查找T中是否存在key，f指向T的父节点，初始调用值为NULL
int SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    if (!T) {   // T为空，即查找失败, p指向最后一个访问的节点并返回FALSE
        *p = f;
        return FALSE;
    }
    else if (T->data == key) {  // 查找成功，p指向该节点并返回TRUE
        *p = T;
        return TRUE;
    }
    else if (T->data > key)
        return SearchBST(T->lchild, key, T, p); // 查找左子树
    else
        return SearchBST(T->rchild, key, T, p);  // 查找右子树
}

// 不存在就插入并返回TRUE
int InsertBST(BiTree *T, int key) {
    BiTree p, s;
    if (SearchBST(T, key, NULL, &p)) // 存在key，不插入
        return FALSE;
    s = (BiTree)malloc(sizeof(BiTNode));
    s->data = key;
    s->lchild = s->rchild = NULL;
    if (!p) // 一棵没有根节点的二叉树
        *T = s; // 直接插入
    else if (key < p->data)
        p->lchild = s;
    else
        p->rchild = s;
    return TRUE;
}

// 删除节点并重接左右子树 
int Delete(BiTree *p) {
    BiTree q;
    if ((*p)->rchild == NULL) {  // 右子树空
        q = *p;                  // 把它的左子树接替它的位置
        *p = (*p)->lchild;
    }
    else if ((*p)->lchild == NULL) {    // 左子树空
        q = *p;                         // 右子树接替它的位置
        *p = (*p)->rchild;
    }
    else {                       // 都不空
        q = *p;
        // 找到删除节点的前驱（或后继）
        BiTree s = (*p)->lchild; // 前驱为：左子节点的最右子节点
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }

        (*p)->data = s->data;       // s指向被删节点的直接前驱
                            
        if (q != *p)               // 如果q != *p（即s != (*p)->lchild）直接前驱不是被删节点的左子节点
            q->rchild = s->lchild;  // （原来最右的节点/前驱的父节点）重接右子树（原来最右的节点/前驱的左子树）
        else                        // 如果q == *p（即s == (*p)->lchild),即s是原来节点的左子树
            q->lchild = s->lchild;  // 重接左子树
        
        free(s);
    }
    return TRUE;
}


// 删除节点
int DeleteBST(BiTree *T, int key) {
    if (!*T) // 一棵没有根节点的二叉树，什么节点也没有
        return FALSE;
    else {
        if (key == (*T)->data)
            return Delete(T);
        else if (key < (*T)->data)
            return DeleteBST(T->lchild, key);
        else
            return DeleteBST(T->rchild, key);
    }
}