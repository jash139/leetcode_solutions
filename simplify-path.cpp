class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        
        if (path[path.size() - 1] != '/')
            path += "/";
        
        string directory = "";
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (directory == "" or directory == ".")
                    directory = "";
                else if (directory == "..") {
                    if (stack.size() != 0)
                        stack.pop_back();
                } else
                    stack.push_back(directory);
                directory = "";
            } else
                directory += path[i];
        }
        
        string res = "";
        for (auto p : stack)
            res += "/" + p;
        
        if (res.size() == 0)
            return "/";
        
        return res;
    }
};
