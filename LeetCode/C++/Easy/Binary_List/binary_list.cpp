#include <iostream>
#include <vector>

struct ListNode
{
    ListNode* next;
    int val;

    ListNode(): next(nullptr), val(0){}
    ListNode(int val) : next(nullptr), val(val){}
    ListNode(int val, ListNode* node) : next(nullptr), val(val){}
};

ListNode* assemble_list(const std::vector<int>& arr)
{
    ListNode* first_node = new ListNode(arr.front());
    ListNode* node = first_node;

    for(int i = 1; i < arr.size(); ++i)
    {
        node->next = new ListNode(arr[i]);
        node = node->next;
    }

    return first_node;
}

void print_list(ListNode* node)
{
    std::cout << "[ ";

    while(node)
    {
        std::cout << node->val << " "; 
        node = node->next;
    }

    std::cout << "]" << std::endl;
}

void free_list(ListNode* node)
{
    while(node)
    {
        delete(node);
        node = node->next;
    }
}

int length(ListNode* node)
{
    int length = 0;
    while(node)
    {
        length++;
        node = node->next;
    }

    return length;
}

int binary_to_decimal(ListNode* node)
{
    int len = length(node);
    int decimal = 0;

    while(node)
    {
        decimal += node->val << --len;
        node = node->next;
    }

    return decimal;
}

int main()
{
    ListNode* node = assemble_list({1,0,0,1,0,0,1,1,1,0,0,0,0,0,0});
    print_list(node);
    std::cout << "Decimal val : " << binary_to_decimal(node) << std::endl;
    free_list(node);

    return 0;
}
