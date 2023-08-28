#include <stdio.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool traversalEqual(TreeNode *r1, TreeNode *r2)
{
    if (!r1 && !r2)
    {
        return true;
    }
    if (r1 && r2 && r1->val == r2->val)
    {

        return traversalEqual(r1->left, r2->right) && traversalEqual(r1->right, r2->left);
    }

    return false;
}
bool isSymmetric(TreeNode *root)
{
    return traversalEqual(root->left, root->right);
}

int main()
{
    struct TreeNode *a;
    a->val = 1;

    struct TreeNode *b;
    b->val = 2;

    struct TreeNode *c;
    c->val = 2;

    struct TreeNode *d;
    d->val = 3;

    a->left = b;
    a->right = c;

    bool sym = isSymmetric(a);
    a->right = d;
    bool asym = isSymmetric(a);

    printf("%s\n", sym ? "True" : "False");
    printf("%s\n", asym ? "True" : "False");
}