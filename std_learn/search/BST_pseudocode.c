// https://visualgo.net/bst
// 伪代码
// search
// find Min
if this is null return empty
if left != null
    go left
else return this key

// find Max
if this is null return empty
if right != null
    go right
else return this key

// find value
if this == null
    return null
else if this key == search value
    return this
else if this key < search value
    return right
else search left

// insert
if insertion point is found
    create new vertex
if value to be inserted < this key
    go left
else go right

// remove
search for v

if v is a leaf
    delete leaf v
else if v has 1 child
    bypass v
else replace v with successor

// pred/succ-essor
// get predessor
if this.left != NULL
    return findMax(this.left);
else {
    p = this.parent;
    T = this;
    while (p != NULL && T == p.left) {
        T = p;
        P = T.parent;
    }
    if (p == NULL)
        return -1;
    else
        return p;
}

// get successor
if (this.right != NULL)
    return findMin(this.right);
else {
    p = this.parent;
    T = this;
    while (p != NULL && T == p.right) {
        T = p;
        p = T.parent;
    }
    if (p == NULL)
        return -1;
    else
        return p;
}


// inorder traversal
void inOrder(BiTree *T) {
    if (T == NULL)
        return;
    inOrder(T->left);
    visit T;
    inOrder(T->right);
}
