//https://youtu.be/f2EfGComRKM
class Solution {
private:
// need a map or vector vis to check if copy has already been created and also to carry a record of this copy for further use. if copy already created just add to adj list if not create copy add to adj list call dfs for copy
void dfs(Node* og, Node* &copy, vector<Node*>& vis)
{
for(auto &x : og->neighbors)
{
if(vis[x->val]==nullptr)
{
vis[x->val]=new Node(x->val);
copy->neighbors.push_back(vis[x->val]);
dfs(x,vis[x->val],vis);
}
else copy->neighbors.push_back(vis[x->val]);
}
}
public:
Node* cloneGraph(Node* node) {
if(node==nullptr) return nullptr;
vector<Node*> vis(101,nullptr);
vis[node->val]=new Node(node->val);
//dfs(node, vis[node->val], vis);
queue<pair<Node*, Node*>> q;
q.push({node,vis[node->val]});
while(!q.empty())
{
auto og=q.front().first;
auto copy=q.front().second;
q.pop();
for(auto&x : og->neighbors)
{
if(vis[x->val]==nullptr)
{
vis[x->val]=new Node(x->val);
copy->neighbors.push_back(vis[x->val]);
q.push({x,vis[x->val]});
}
else
{
copy->neighbors.push_back(vis[x->val]);
}
}
}
return vis[node->val];
}
};