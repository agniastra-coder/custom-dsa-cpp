#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    void preorder(TreeNode* node, string& result) {
        if (!node) {
            result += "#,";
            return;
        }
        result += to_string(node->val) + ",";
        preorder(node->left, result);
        preorder(node->right, result);
    }

    TreeNode* buildDFS(vector<string>& nodes, int& i) {
        if (i >= nodes.size() || nodes[i] == "#") {
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root->left = buildDFS(nodes, i);
        root->right = buildDFS(nodes, i);
        return root;
    }

public:
    string serialize(TreeNode* root) {
        string result = "";
        preorder(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> nodes;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }
        int i = 0;
        return buildDFS(nodes, i);
    }
};
