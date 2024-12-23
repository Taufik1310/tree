#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode *insertNode(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < root->value)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void preOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->value << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << " ";
}

void levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        cout << current->value << " ";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}

void visualizeTree(TreeNode *root, int space = 0, int height = 10)
{
    if (root == nullptr)
        return;

    space += height;
    visualizeTree(root->right, space);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << root->value << "\n";

    visualizeTree(root->left, space);
}

int main()
{
    TreeNode *root = nullptr;

    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    for (int value : values)
    {
        root = insertNode(root, value);
    }

    cout << "=======================\n";
    cout << "  Tree Traversals Demo\n";
    cout << "=======================\n\n";

    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "\nVisualisasi Tree:\n";
    visualizeTree(root);

    cout << "\n\nProgram selesai! Terima kasih telah mencoba. :)\n";

    return 0;
}
