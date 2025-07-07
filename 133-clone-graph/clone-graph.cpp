/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node  * dfs(Node * node , unordered_map  <Node * ,Node *>  & map){
vector<Node * >vec;
Node * newnode = new Node(node->val);
map[node]=newnode;
for(auto it  : node->neighbors){
	if(map.find(it)!= map.end()){
		vec.push_back(map[it]);
	}
	else{
		vec.push_back(dfs(it,map));
	}

}
newnode->neighbors = vec;
return newnode;
}
Node *cloneGraph(Node *node)
{

	unordered_map<Node * ,Node*> map;
    // Write your code here.
   if(node ==nullptr){
	   return nullptr;
   }

   if(node->neighbors.size()==0){
	   Node * newnode = new Node(node->val);
	   return newnode;
   }
   return dfs(node  ,map);
   






}
    
};