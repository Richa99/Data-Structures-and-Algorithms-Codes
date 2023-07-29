#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class directed_graph{
	public: 
		int vertices;
		vector<vector<int> > adj;
		
		directed_graph(int v){
			vertices=v;
			adj.resize(vertices);
			
		}
		void addedge(int source, int dest){
			
			adj[source].push_back(dest);
		}
		
		void printgraph(){
			for(int i=0;i<vertices;i++){
				cout<< i << " ";
				for(int k=0;k<adj[i].size();k++){
					cout<< "- >" << adj[i][k] << " ";
				}
				cout<<endl;
			}
		}
	
		void bfs(){
			vector<bool> visited(vertices,false);
			for(int x=0;x<vertices;x++){
				if(visited[x]==false){
					queue<int> q;
					q.push(x);
					visited[x]=true;
					
					while(q.empty()!=true){
						int front=q.front();
						q.pop();
						cout<< front << " ";
						for(int i=0;i<adj[front].size();i++){
							if(visited[adj[front][i]]==false){
								q.push(adj[front][i]);
								visited[adj[front][i]]=true;
							}
						}
					}
				}
				
			}
		}
		
		void dfs(){
			vector<bool> visited(vertices,false);
			for(int x=0;x<vertices;x++){
				if(visited[x]==false){
					stack<int> s;
					s.push(x);
					visited[x]=true;
					while(s.empty()!=true){
						int front=s.top();
						s.pop();
						cout<< front << " ";
						for(int i=0;i<adj[front].size();i++){
							if(visited[adj[front][i]]==false){
								s.push(adj[front][i]);
								visited[adj[front][i]]=true;
							}
						}
					}
				}
			}
		}
		
		//DFS using recursion
		void recurisveDFS(int node, vector<vector<int> > &adj, vector<bool> &visited){
			
			visited[node]=true;
			cout<< node << " ";
			for(int i=0;i<adj[node].size();i++){
				if(visited[adj[node][i]]!=true){
					recurisveDFS(adj[node][i],adj,visited);
				}
			}
			
		}
		
		void callDFS(){
			vector<bool> visited(vertices,false);
			for( int x=0;x<vertices;x++){
				if(!visited[x]){
					recurisveDFS(0,adj,visited);
				}
			}
			
		}
		
		
		bool isCyclicDFS(){
			vector<bool> visited(vertices,false);
			vector<bool> visitdfs(vertices,false);
			
			for(int x=0;x<vertices;x++){
				if(visited[x]==false){
					stack<int> s;
					s.push(x);
					visited[x]=true;
					visitdfs[x]=true;
					while(!s.empty()){
						int front=s.top();
						s.pop();
						for(int i=0; i<adj[front].size();i++){
							if(visited[adj[front][i]]==false){
								s.push(adj[front][i]);
								visited[adj[front][i]]=true;
								visitdfs[adj[front][i]]=true;
							}
							else if(visitdfs[adj[front][i]]==true){
								return true;
							}
						}
					}
				}
				visitdfs[x]=false;
			}
			return false;
		}
		
		void topologicalsort( int node, vector<bool> &visited, stack<int> &toposort ){
			visited[node]=true;
			
			for(int i=0;i<adj[node].size();i++){
				if(visited[adj[node][i]]==false){
					topologicalsort(adj[node][i],visited,toposort);
				}
			}
			toposort.push(node);
		}
	
		void topological_sortDFS(){
			vector<bool> visited(vertices, false);
			stack<int> toposort;
			for(int x=0;x<vertices;x++){
				if(visited[x]==false){
					topologicalsort(x,visited,toposort);
				}
			}
			while(!toposort.empty()){
				cout<<toposort.top() << " ";
				toposort.pop();
			}
		}
};


int main(){
	
	int num_vertex, num_edge;
	cout<<"Enter the number of vertices and edge"<< endl;
	cin>> num_vertex >> num_edge;
	directed_graph g(num_vertex);
	
	cout<<" Enter the edges" <<endl;
	for(int i=0;i<num_edge;i++){
		int s,d;
		cin>>s >>d;
		g.addedge(s,d);
	}
	g.printgraph();
	cout<<"\nBFS traversal is : \n";
	g.bfs();
	cout<<"\nDFS traversal is : \n";
	g.dfs();
	
	cout<<"\nDFS using recursion : \n";
	g.callDFS();
	
	if(g.isCyclicDFS()){
		cout<<"\nThe graph contains cycles\n";
	}
	else{
		cout<<"\nThe graph does not contain cycles\n";
	}
	cout<<"\nTopological sort is : "<<endl;
	g.topological_sortDFS();
	return 0;
}
