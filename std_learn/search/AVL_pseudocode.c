// https://visualgo.net/bst
insert v
check balance factor of this and its children and its children
case 1: this.rotateRight
case 2: this.left.rotateLeft, this.rotateRight
case 3: this.rotateLeft
case 4: this.right.rotateRight, this.rotateLeft
this is balanced

remove v
check balance factor of this and its children
case 1: this.rotateRight
case 2: this.left.rotateLeft, this.rotateRight
case 3: this.rotateLeft
case 4: this.right.rotateRight, this.rotateLeft
this is balanced

