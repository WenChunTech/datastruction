use std::fmt::Debug;

struct TreeNode<T: Debug> {
    data: T,
    lchild: Option<Box<TreeNode<T>>>,
    rchild: Option<Box<TreeNode<T>>>,
}

fn preorder_traverse<T: Debug>(node: TreeNode<T>) {
    if node.lchild.is_some() && node.rchild.is_some() {
        println!("{:?}", node.data);
        preorder_traverse(node.lchild.unwrap());
        preorder_traverse(node.rchild.unwrap());
    }
}

fn main() {
    let node5 = TreeNode {
        data: 5,
        lchild: None,
        rchild: None,
    };
    let node4 = TreeNode {
        data: 4,
        lchild: None,
        rchild: None,
    };
    let node3 = TreeNode {
        data: 3,
        lchild: None,
        rchild: None,
    };
    let node2 = TreeNode {
        data: 2,
        lchild: Some(Box::new(node4)),
        rchild: Some(Box::new(node5)),
    };
    let node1 = TreeNode {
        data: 1,
        lchild: Some(Box::new(node2)),
        rchild: Some(Box::new(node3)),
    };
    preorder_traverse(node1);
}
