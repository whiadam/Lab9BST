#include "TreeType.h"
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

bool TreeType::IsFull() const
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool TreeType::IsEmpty() const
{
  return root == NULL;
}

int CountNodes(TreeNode* tree);

int TreeType::GetLength() const
{
  return CountNodes(root);
}

int CountNodes(TreeNode* tree)
{
  if (tree == NULL)
    return 0;
  else 
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found);

ItemType TreeType::GetItem(ItemType item, bool& found)
{
  Retrieve(root, item, found);
  return item;
}

void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found)
{
  if (tree == NULL)
    found = false;
  else if (item < tree->info)      
    Retrieve(tree->left, item, found);
  else if (item > tree->info)
    Retrieve(tree->right, item, found);
  else
  {
    item = tree->info;
    found = true;
   }
} 

void Insert(TreeNode*& tree, ItemType item);

void TreeType::PutItem(ItemType item)
{
  Insert(root, item);
}

void Insert(TreeNode*& tree, ItemType item)
{
  if (tree == NULL)
  {
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);
  else
    Insert(tree->right, item);
} 

void DeleteNode(TreeNode*& tree);
void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
{
  Delete(root, item);
}

void Delete(TreeNode*& tree, ItemType item)
{
  if (item < tree->info)
    Delete(tree->left, item);
  else if (item > tree->info)
    Delete(tree->right, item);
  else
    DeleteNode(tree);
}   

void GetPredecessor(TreeNode* tree, ItemType& data);

void DeleteNode(TreeNode*& tree)
{
  ItemType data;
  TreeNode* tempPtr;
  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);
  }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

void PrintTree(TreeNode* tree, std::ofstream& outFile) 
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);
    outFile << tree->info;
    PrintTree(tree->right, outFile);
  }
}

void TreeType::Print(std::ofstream& outFile) const
{
  PrintTree(root, outFile);
}

TreeType::TreeType()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
{
  Destroy(root);
}

void Destroy(TreeNode*& tree)
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}

void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
{
  CopyTree(root, originalTree.root);
}

void TreeType::operator= 
     (const TreeType& originalTree)
{
  {
  if (&originalTree == this)
    return;
  Destroy(root);
  CopyTree(root, originalTree.root);
  }
}

void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree)
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}

void PreOrder(TreeNode*, QueType&);
void InOrder(TreeNode*, QueType&);
void PostOrder(TreeNode*, QueType&);

void TreeType::ResetTree(OrderType order)
{
  switch (order)
  {
    case PRE_ORDER : PreOrder(root, preQue);
                     break;
    case IN_ORDER  : InOrder(root, inQue);
                     break;
    case POST_ORDER: PostOrder(root, postQue);
                     break;
  }
}

void PreOrder(TreeNode* tree, QueType& preQue)
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}

void InOrder(TreeNode* tree, QueType& inQue)
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}

void PostOrder(TreeNode* tree, QueType& postQue)
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}

ItemType TreeType::GetNextItem(OrderType order, bool& finished)
{
  finished = false;
  ItemType item;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
  return item;
}

int CountLeaves(TreeNode* tree)
{
  if (tree == NULL)
    return 0;
  if (tree->left == NULL && tree->right == NULL)
    return 1;
  return CountLeaves(tree->left) + CountLeaves(tree->right);
}

int TreeType::LeafCount() const
{
  return CountLeaves(root);
}
