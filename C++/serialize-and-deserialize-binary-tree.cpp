/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "*";
        
        string serializedString = to_string(root -> val) + "," + serialize(root -> left) + "," + serialize(root -> right);
        
        return serializedString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserializeString(data);
    }
    
    TreeNode* deserializeString(string &data) {
        if (data[0] == '*') {
            if (data.size() > 1)
                data = data.substr(2);
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(getNodeValueAndUpdate(data));
        node -> left = deserializeString(data);
        node -> right = deserializeString(data);
        
        return node;
    }
    
    int getNodeValueAndUpdate(string &data) {
        int pos = data.find(',');
        int nodeValue = stoi(data.substr(0, pos));
        
        data = data.substr(pos + 1);
        
        return nodeValue;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
