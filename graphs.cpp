#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
//#include <unordered_map>
using namespace std;

class graph{
	public:
		int vertices;
		//list<int> *adjlist;
		vector<vector<int> > adj;
		
		graph(int v){
			vertices=v;
			adj.resize(vertices);
		}
//		void addedge(vector<int> adj[], int s, int d){
//			adj[s].push_back(d);
//			adj[d].push_back(s);
//		}
		void addedge(int s, int d){
			
			adj[s].push_back(d);
			adj[d].push_back(s);
		}
//		void printgraph(vector<int> adj[], int vertices){
//			for(int i=0;i<vertices;i++){
//				cout<<"vertex " << i << " : ";
//				//cout<< i;
//				for(int j=0;j<adj[i].size();j++){
//					cout<<" -> "<< adj[i][j] ;
//				}
//				cout<<endl;
//			}	
//			
//		}
		void printgraph(){
			for(int i=0;i<adj.size();i++){
				cout<<"vertex " << i << " : ";
				//cout<< i;
				for(int j=0;j<adj[i].size();j++){
					cout<<" -> "<< adj[i][j] ;
				}
				cout<<endl;
			}	
			
		}
		
		void bfs(){
			
			//unordered_map<int,bool> visited;
			vector<bool> visited;
			visited.resize(vertices,false);
			for(int x=0;x<vertices;x++){ // adding for loop to handle disconnected graph cases
				if(visited[x]==false){
					queue<int> q;
					q.push(x);
					visited[x]=true;
					while(q.empty()!=true){
						
						int firstnode=q.front();
						cout<< firstnode << " ";
						q.pop();
						for(int i=0;i<adj[firstnode].size();i++){
							if(visited[adj[firstnode][i]]==false)
							q.push(adj[firstnode][i]);
							visited[adj[firstnode][i]]=true;
						}
					}
					
				}
				
			}
		}
		void dfs(){
			vector<bool> visited ;
			visited.resize(vertices,false);
			for(int x=0;x<vertices;x++){
				stack<int> s;
				if(visited[x]==false){
					s.push(x);
					visited[x]=true;
					while(s.empty()!=true){
						int firstnode=s.top();
						s.pop();
						cout<< firstnode<<" ";						
						for(int i=0;i<adj[firstnode].size();i++){
							if(visited[adj[firstnode][i]]==false){
								s.push(adj[firstnode][i]);
								visited[adj[firstnode][i]]=true;
							}
						}
					}
				}
			}
		}
		
		bool isCyclicBFS(){
			vector<bool> visited;
			visited.resize(vertices,false);
//			vector<int> parent;
//			parent.resize(vertices,-1);
			
			for(int x=0;x<vertices;x++){
				if(visited[x]==false){
				
					//cout<<" \nfirst for loop x = "<<x<<endl;
					queue<int> q;
					vector<int> parent(vertices);
					q.push(x);
					visited[x]=true;
					parent[x]=-1;
					//cout<< "\nparent of "<<x <<" = "<< parent[x] <<endl;
					while(q.empty()!=true){
						
						int frontNode=q.front();
						q.pop();
						//cout<<"\ninside while frontnode = "<<frontNode<<endl;
						for(int i=0;i<adj[frontNode].size();i++){
							//	cout<<"\n inside for.. adjacency of = " << frontNode<<endl;
							if(visited[adj[frontNode][i]]==true && parent[frontNode] != adj[frontNode][i]){
							//	cout<<"\nadj[frontNode][i] = "<<adj[frontNode][i]<< " visited[adj[frontNode][i]] = " << visited[adj[frontNode][i]] << " parent[adj[frontNode][i]] = "<<parent[adj[frontNode][i]]<<endl;
								return true;
							}
							else if(visited[adj[frontNode][i]]==false){
								q.push(adj[frontNode][i]);
								visited[adj[frontNode][i]]=true;
								parent[adj[frontNode][i]]=frontNode;
							//	cout<< "parent of "<<adj[frontNode][i]<<" is "<<parent[adj[frontNode][i]]<<" = " << frontNode <<endl;
							}
						}
					}
				}
				return false;	
			}
	}
	
	bool isCyclicDFS(){
		vector<int> visited(vertices,false);
		for(int x=0;x<vertices;x++){
			if(visited[x]==false){
				stack<int> s;
				vector<int> parent(vertices,-1);
				s.push(x);
				visited[x]=true;
				while(s.empty()!=true){
					int front=s.top();
					s.pop();
					for(int i=0;i<adj[front].size();i++){
						if(visited[adj[front][i]]==true && parent[front]!=adj[front][i]){
							return true;
						}
						else if(visited[adj[front][i]]==false){
							s.push(adj[front][i]);
							visited[adj[front][i]]=true;
							parent[adj[front][i]]=front;
						}
					}
				}
			}
		}
		return false;
	}
	
	void shortestPathBFS(int source, int dest){
		vector<int> ans;
		vector<int> visited(vertices,false);
		vector<int> Mainparent(vertices);
		
		for(int x=0;x<vertices;x++){
			if(visited[x]==false){
				vector<int> parent(vertices);
				queue<int> q;
				q.push(x);
				visited[x]=true;
				parent[x]=-1;
				while(!q.empty()){
					int front=q.front();
					q.pop();
					for(int i=0;i<adj[front].size();i++){
						if(visited[adj[front][i]]==false){
							q.push(adj[front][i]);
							visited[adj[front][i]]=true;
							parent[adj[front][i]]=front;
						}
					}
				}
				for(int j=0;j<parent.size();j++){
					Mainparent[j]=parent[j];
//					cout<<j << " -- "<< parent[j] <<endl;
				}
			}
		}
		cout<<"\n parent array\n";
		
		for(int j=0;j<Mainparent.size();j++){
			cout<<j << " -- "<< Mainparent[j] <<endl;
		}
		
		cout<<"\nShortest distance form" << source<<" and destination"<<dest <<"using bfs \n";
		int curr=dest;
		ans.insert(ans.begin(),curr);
		cout<<"starting curr"<<curr<<endl;
		while(curr!=source){
			curr=Mainparent[curr];
			cout<<"curr in while" <<curr<<endl;
			ans.insert(ans.begin(),curr);
		}
		
		for(int j=0;j<ans.size();j++){
			cout<< ans[j] <<" - > ";
		}
	}
};

int main(){
	
	
	int num_vertex, num_edge;
	cout<<"Enter the number of edges and vertices :" <<endl;
	cin>> num_vertex >> num_edge ;
	graph g(num_vertex);
	cout << "Enter the edges : Enter source then destination "<<endl;
	for (int i=0;i<num_edge;i++){
		int s, d;
		cin>>s>>d;
		g.addedge(s,d);
	}
	cout<< " \n The adjecency list is :" << endl;
	g.printgraph();
	cout<<"\nBFS traversal is : \n";
	g.bfs();
	cout<<"\nDFS traversal is : \n";
	g.dfs();
	cout<<"\n cycle using BFS"<<endl;
	if(g.isCyclicBFS()==false){
		cout<<"\nGraph does not contain any cycles\n";
	}
	else{
		cout<<"\nGraph contains cycles\n";
	}
	cout<<"\n cycle using DFS"<<endl;
	if(g.isCyclicDFS()==false){
		cout<<"\nGraph does not contain any cycles\n";
	}
	else{
		cout<<"\nGraph contains cycles\n";
	}
	int s,d;
	cout<<"\nEnter the source and destination for shortest distance\n";
	cin>>s>>d;
	g.shortestPathBFS(s,d);
//	int V=5;
//	graph g(V);
//	vector<int> adj[V];
//    g.addedge(adj, 0, 1);
//    g.addedge(adj, 0, 4);
//    g.addedge(adj, 1, 2);
//    g.addedge(adj, 1, 3);
//    g.addedge(adj, 1, 4);
//    g.addedge(adj, 2, 3);
//    g.addedge(adj, 3, 4);
//    g.printgraph(adj, V);


    return 0;
	
	
}
