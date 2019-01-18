/* Unival (universal value) tree is a tree in which all the node have the same
 * value. The problem is to find the number of unival subtrees for a given root
 * node for a tree.
 */

#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int t_val):
    val(t_val),
    left(nullptr),
    right(nullptr)
    { }
};

bool NumUnivalSubTreesUtil(TreeNode* node, int& num, int parentVal = 0)
{
    if (nullptr == node)
    {
        return true;
    }

    bool isLeftSubTreeUnival = NumUnivalSubTreesUtil(node->left, num, node->val);
    bool isRightSubTreeUnival = NumUnivalSubTreesUtil(node->right, num, node->val);

    num += isLeftSubTreeUnival & isRightSubTreeUnival;

    return isLeftSubTreeUnival && isRightSubTreeUnival && (node->val == parentVal);
}

int NumUnivalSubTrees(TreeNode* root)
{
    int num = 0;
    NumUnivalSubTreesUtil(root, num);
    return num;
}

int main(int argc, char const *argv[])
{
    //    0
    //   / \
    //  1   0
    //     / \
    //    1   0
    //   / \
    //  1   1
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->right = new TreeNode(0);
    std::cout << "Number of unival subtrees = " << NumUnivalSubTrees(root) << "\n";
    return 0;
}
