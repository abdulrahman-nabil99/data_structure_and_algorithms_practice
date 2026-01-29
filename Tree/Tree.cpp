#include <iostream>
#include "stack.h"
#include "queue.h"
#include "BinaryTree.h"



int main()
{
    BinaryTree<int> b_tree;
    b_tree.create_binary_tree();
    std::cout << "Preorder" << std::endl;
    b_tree.preorder();
    b_tree.i_preorder();
    std::cout << "Level order" << std::endl;
    b_tree.level_order();
    std::cout << "Postorder" << std::endl;
    b_tree.postorder();
    std::cout << "Inorder" << std::endl;
    b_tree.inorder();
    b_tree.i_inorder();

    std::cout << "Count " << b_tree.count() << std::endl;
    std::cout << "Level " << b_tree.height() << std::endl;

}
