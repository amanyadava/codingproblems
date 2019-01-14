#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void Serialize(TreeNode*, std::string&);
TreeNode* Deserialize(std::string);
TreeNode* DeserializeUtil(std::vector<std::string>&, int&);

const char* nullNodeStr = "null";
const char* delimiter = ",";

int main(int argc, char const *argv[])
{
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    TreeNode four(4);
    TreeNode five(5);
    one.left = &two;
    one.right = &three;
    two.right = &four;
    three.left = &five;

    std::string serialTree;
    Serialize(&one, serialTree);
    std::cout << serialTree << "\n";
    return 0;
}

void Serialize(TreeNode* root, std::string& str)
{
    if (root == nullptr)
    {
        str.append(nullNodeStr);
        str.append(delimiter);
        return;
    }

    std::stringstream ss;
    ss << root->val << delimiter;
    str.append(ss.str());
    Serialize(root->left, str);
    Serialize(root->right, str);
}

TreeNode* Deserialize(std::string str)
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> vNodeStr; 
    while(getline(ss, token, *delimiter))
    {
        vNodeStr.push_back(token);
    }

    int idx = 0;
    return DeserializeUtil(vNodeStr, idx);
}

TreeNode* DeserializeUtil(std::vector<std::string>& vNodeStr, int& idx)
{
    if (0 == vNodeStr[idx].compare(nullNodeStr))
    {
        idx++;
        return nullptr;
    }

    int val = std::stoi(vNodeStr[idx]);
    TreeNode* newNode = new TreeNode(val);
    idx++;
    newNode->left = DeserializeUtil(vNodeStr, idx);
    newNode->right = DeserializeUtil(vNodeStr, idx);
    return newNode;
}
