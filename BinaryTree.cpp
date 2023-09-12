#include <iostream>
#include <queue>
using namespace std;

struct Node
{
public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }

    return -1;
}

void inOrderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

Node *buildTreePostOrder(int postorder[], int inorder[], int start, int end)
{
    static int ind = end;

    if (start > end)
    {
        return NULL;
    }

    int curr = postorder[ind];
    ind--;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->right = buildTreePostOrder(postorder, inorder, pos + 1, end);
    node->left = buildTreePostOrder(postorder, inorder, start, pos - 1);

    return node;
}
Node *buildTreePreOrder(int preorder[], int inorder[], int start, int end)
{
    static int ind = 0;

    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[ind];
    ind++;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->left = buildTreePreOrder(preorder, inorder, start, pos - 1);
    node->right = buildTreePreOrder(preorder, inorder, pos + 1, end);

    return node;
}

void printlevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int sumAtK(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int countOfNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return countOfNodes(root->left) + countOfNodes(root->right) + 1;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}

int calcHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calcDiameter(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

int calDiameterOptimized(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calDiameterOptimized(root->left, &lh);
    int rDiameter = calDiameterOptimized(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

void sumReplace(Node *root)
{
    if (root == NULL)
        return;

    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
        root->data += root->left->data;

    if (root->right != NULL)
        root->data += root->right->data;
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    if (isBalanced(root->left) == false)
        return false;
    if (isBalanced(root->right) == false)
        return false;

    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

int isBalancedOptimized(Node *root, int *height)
{
    if (root == NULL)
        return true;

    int lh = 0, rh = 0;

    if (isBalancedOptimized(root->left, &lh) == false)
        return false;
    if (isBalancedOptimized(root->right, &rh) == false)
        return false;

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (root->data > val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    if (root->data > key)
        return searchInBST(root->left, key);

    return searchInBST(root->right, key);
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;

    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    if (root->data > key)
        root->left = deleteInBST(root->left, key);
    else if (root->data < key)
        root->right = deleteInBST(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

int main()
{
    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);

    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // preorder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;
    // postorder(root);

    // int preorder[] = {1, 2, 4, 3, 5};
    // int postorder[] = {4, 2, 5, 3, 1};
    // int inorder[] = {4, 2, 1, 5, 3};

    // Node *root = buildTreePreOrder(preorder, inorder, 0, 4);
    // Node *root = buildTreePostOrder(postorder, inorder, 0, 4);
    // inOrderPrint(root);

    // printlevelOrder(root);
    // cout << sumAtK(root, 2);

    // cout << countOfNodes(root);
    // cout << sumOfNodes(root);
    // cout << calcHeight(root);

    // cout << calcDiameter(root);

    // int h = 0;
    // cout << calDiameterOptimized(root, &h);

    // preOrder(root);
    // cout << endl;
    // sumReplace(root);
    // preOrder(root);

    // if (isBalanced(root))
    //     cout << "Balanced tree";
    // else
    //     cout << "Unbalanced Tree";

    // int height = 0;
    // if (isBalancedOptimized(root, &height))
    //     cout << "Balanced tree";
    // else
    //     cout << "Unbalanced Tree";

    /* BST */
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    inorder(root);
    cout << endl;
    // if (searchInBST(root, 3) == NULL)
    //     cout << "Not found";
    // else
    //     cout << "found";

    root = deleteInBST(root, 4);
    inorder(root);

    return 0;
}