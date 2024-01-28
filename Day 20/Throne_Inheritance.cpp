class ThroneInheritance {
public:
    unordered_map<string, vector<string>> tree;
    string root;
    unordered_map<string, bool> dead; 
    ThroneInheritance(string kingName) {
        root= kingName;
    }
    
    void birth(string parentName, string childName) {
        tree[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    void dfs(string root, vector<string> &order){
        if(!dead[root]){
            order.push_back(root);
        }
        for(auto child: tree[root]){
            dfs(child, order);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(root, order);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
