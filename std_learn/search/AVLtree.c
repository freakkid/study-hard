// http://www.cnblogs.com/huangxincheng/archive/2012/07/22/2603956.html
// AVL平衡二叉树
typedef struct BiTree {
    int data;           // 结点数据
    int bf;             // 结点的平衡因子
    struct BiTNode *lchild, *rchild;
}


// 左左情况（左子树的左节点）
// 右旋操作 - 对以p为根的二叉排序树作右旋处理
void R_Rotate(BiTree *p) {
    BiTree L = (*p)->lchild;    // p左子树的根节点
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    (*p) = L;
}

// 右右情况（右子树的右节点）
// 左旋操作 - 对以p为根的二叉排序树作左旋处理
void L_Rotate(BiTree *p) {
    BiTree R = (*p)->rchild;    // p右子树的根节点
    (*p)->rchild = L->lchild;
    L->lchild = (*p);
    (*p) = L;
}

// 左右情况（左子树的右节点）右高
// 先对根节点的右子树进行右旋后对根节点进行左旋

// 右左情况（右子树的左节点）左高
// 先对根节点的左子树进行左旋后对根节点进行右旋
#define LH +1   // 左高
#define EH 0    // 等高
#define RH -1   // 右高

void LeftBalance(BiTree *T) {
    BiTree L = (*T)->lchild;
    BiTree Lr;
    // 检查T的左子树的平衡度，并作相应平衡处理
    switch (L->bf) {
        case LH:        // 新结点插入在T的左孩子的字左子树上，右旋处理
            (*T)->bf = L->bf;
            R_Rotate(T);
            break;
        case RH:        // 新结点插入在T的左孩子的右子树上，双旋处理
            Lr = L->rchild;
            switch (Lr->bf) {   // 修改T及其左孩子的平衡因子
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
    }

}

int InsertAVL(BiTree *T, int e, int *taller) {
    if(!*T) {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else {
        if (e == (*T)->data) {
            *taller = FALSE;
            return FALSE;
        }
        if (e < (*T)->data) {
            if (!InsertAVL(&(*T)->lchild, e, taller))
                return FALSE;
            if (*taller) {
                switch ((*T)->bf) {
                    case LH:
                        LeftBalance(T);
                        *taller = FALSE;
                        break;
                    case EH:
                        (*T)->bf = LH;
                        *taller = TRUE;
                        break;
                    case RH:
                        (*T)->bf = EH;
                        *taller = FALSE;
                        break;
                }
            }
        }
        else {
            if (!InsertAVL(&(*T)->rchild, e, taller))
                return FALSE;
            if (*taller) {
                switch ((*T)->bf) {
                    case LH:
                        (*T)->bf = EH;
                        *taller = FALSE;
                        break;
                    case EH:
                        (*T)->bf = RH;
                        *taller = TRUE;
                        break;
                    case RH:
                        RightBalance(T);
                        *taller = FALSE;
                        break;
                }
            }
        }
    }
    return TRUE;
}


int main() {
    int a[] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    BiTree T = NULL;
    int taller;
    for (int i = 0; i < 10; i++)
        InsertAVL(&T, a[i], &taller);
}