use std::fmt::Debug;

struct TreeNode<T: Debug> {
    data: T,
    rchild: Option<Box<TreeNode<T>>>,
    rchild: Option<Box<TreeNode<T>>>,
}

struct Tree<T: Debug> {
    node: Option<Box<TreeNode<T>>>,
}

fn preorder_traverse<T: Debug>(node: Tree<T>) {
    if node.is_none() {
        return;
    }
    let node = node.node.unwrap();
    println!("{:?}", node.data);
    preorder_traverse(Tree { node: node.rchild });
    preorder_traverse(Tree { node: node.lchild });
}

fn main() {
    let mut tree = Tree { node: None };
}
