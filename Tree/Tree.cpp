#include <iostream>
#include "stack.h"
#include "queue.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"



int main()
{
    //BinaryTree<int> b_tree;
    //b_tree.create_binary_tree();
    //std::cout << "Preorder" << std::endl;
    //b_tree.preorder();
    //b_tree.i_preorder();
    //std::cout << "Level order" << std::endl;
    //b_tree.level_order();
    //std::cout << "Postorder" << std::endl;
    //b_tree.postorder();
    //std::cout << "Inorder" << std::endl;
    //b_tree.inorder();
    //b_tree.i_inorder();

    //std::cout << "Count " << b_tree.count() << std::endl;
    //std::cout << "Level " << b_tree.height() << std::endl;

    //BinarySearchTree<int> bts;
    //bts.i_insert(12);
    //bts.i_insert(11);
    //bts.i_insert(13);
    //bts.i_insert(10);
    //bts.i_insert(8);
    //bts.i_insert(5);
    //bts.i_inorder();
    //int value;
    //if(bts.i_max(value))
    //    std::cout << "Max " << value << std::endl;
    //if(bts.i_min(value))
    //    std::cout << "Min " << value << std::endl;

    AVLTree<int> avl_tree;

    avl_tree.i_insert(10);
    avl_tree.i_insert(5);
    avl_tree.i_insert(2);

    avl_tree.display_pretty();

}
