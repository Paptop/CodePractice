#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(nullptr), right(nullptr) {}
};

void iterate_value_middle(TreeNode* node, int tab = 1)
{
    if(node == nullptr)
    {
        return;
    }

    iterate_value_middle(node->left, tab * 4);
    for(int i = 0 ; i < tab; ++i)
    {
        std::cout << " ";
    }
    std::cout << node->val << std::endl;
    iterate_value_middle(node->right, tab * 4);
}

void free_tree(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }

    free_tree(node->left);
    delete(node); 
    free_tree(node->right);
}

TreeNode* assemble_tree(const std::vector<int>& values)
{
   if(values.empty())
   {
       return nullptr;
   }

   std::vector<TreeNode*> nodes(values.size(), nullptr);
   nodes.front() = new TreeNode(values[0]);

   for(int i = 0; i < values.size(); ++i)
   {
       TreeNode* curr_ptr = nodes[i];
       TreeNode* left_ptr = nullptr;
       TreeNode* right_ptr = nullptr;

       int left = 2 * i + 1;
       int right = 2 * i + 2;

       if(values[i] < 0)
       {
           continue;
       }

       if(left >= values.size() || right >= values.size())
       {
           break;
       }

       if(values[left] >= 0)
       {
          left_ptr = new TreeNode(values[left]);
          nodes[left] = left_ptr;
       }

       if(values[right] >= 0)
       {
          right_ptr = new TreeNode(values[right]);
          nodes[right] = right_ptr;
       }

       if(!curr_ptr)
       {
          curr_ptr = new TreeNode(values[i]);
          nodes[i] = curr_ptr;
       }

       curr_ptr->left = left_ptr;
       curr_ptr->right = right_ptr;
   } 

   return nodes.front();
}

bool is_in_range(int value, int L, int R)
{
    return value >= L  && value <= R; 
}

int range_sub_bst(TreeNode* root, int L, int R)
{
    int sum = 0;
    std::stack<TreeNode*> queue;

    queue.push(root);

    while(!queue.empty())
    {
        TreeNode* cur_node = queue.top();
        queue.pop();

        if(is_in_range(cur_node->val, L, R))
        {
            sum += cur_node->val;
        }

        if(cur_node->left)
        {
            queue.push(cur_node->left);
        }

        if(cur_node->right) 
        {
           queue.push(cur_node->right);
        }

    }

    return sum;
}

int main()
{
    TreeNode* tree = assemble_tree({10,5,15,3,7, -1, 18});
    std::cout << "Root value is " << tree->val << std::endl;
//    iterate_value_middle(tree);
//
    int sum = range_sub_bst(tree, 7, 15);
    std::cout << "Sum : " << sum << std::endl;
    free_tree(tree);
    return 0;
}
