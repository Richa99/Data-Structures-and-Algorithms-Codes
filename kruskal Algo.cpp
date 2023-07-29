# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
		return a[2] < b[2];
	}

class graph{
	public:
		int vertices;
		vector<vector<int> > edges;
		vector<int> parent;
		vector<int> rank;
		
		graph(int v){
			vertices=v;
			parent.resize(vertices);
			rank.resize(vertices,0);
		}
		
		void addedge(int u, int v, int w){
			//edges.push_back({u,v,w});
			vector<int> temp;
	        temp.push_back(u);
	        temp.push_back(v);
	        temp.push_back(w);
	        edges.push_back(temp);
		}
		
		void printgraph(){
			for(int i=0;i<edges.size();i++){
				cout<<" u = "<< edges[i][0] <<" v = "<< edges[i][1]<<" w = "<< edges[i][2]<<endl;
			}
		}
		
		
		int findParent(int u, vector<int>& parent ){
			if(parent[u]==u){
				return u;
			}
			return parent[u]=findParent(parent[u],parent);
		}
		
		void unionSet(int u, int v, vector<int>& parent, vector<int>& rank){
			int up=findParent(u,parent);
			int vp=findParent(v,parent);
			if(rank[up]>rank[vp]){
				parent[v]=up;
			}
			else if(rank[up]<rank[vp]){
				parent[u]=vp;
			}
			else{
				parent[v]=up;
				rank[up]++;
			}
		}
		
	
		
		void kruksal(){
			
			sort(edges.begin(),edges.end(),cmp);
			cout<< " \nsorted list\n";
			printgraph();
			
			vector<int> parent(vertices);
			vector<int> rank(vertices,0);
			
			for(int i=0;i<vertices;i++){
				parent[i]=i;
			}
			
			int minWeight=0;
			
			for(int x=0;x<edges.size();x++){
				int u= findParent(edges[x][0],parent);
				int v= findParent(edges[x][1],parent);
				if(u!=v){
					cout<< "\nedge Selected is:  u= "<<edges[x][0] <<" v = "<<edges[x][1] <<" w = "<< edges[x][2]<<endl;
					minWeight+=edges[x][2];
					unionSet(u,v,parent,rank);
				}
			}
			
			cout << "Minimum weight graph hs weight = "<< minWeight;
		}
		
		
		
		
		//bellmon ford is used to find the shortest distance in directed grapgh with negative weights
		//dijkstras doesn't give correctg output on the negative weights graphs
		void bellmonFord(int v,int e, int src, int dest){
		
			cout<< " \n\nBELLMON FORD \n";
			vector<int> dist(v,INT_MAX);
			dist[src]=0;
			for(int x=0;x<v;x++){
				for(int i=0;i<e;i++){
					int s=edges[i][0];
					int d=edges[i][1];
					int w=edges[i][2];
					cout<<" s = "<< s << "d = "<< d << "w = "<< w<<endl;
					if(dist[s]!=INT_MAX && (dist[s]+w) < dist[d]){
						dist[d]=dist[s]+w;
					}
					
				}
			}
			
			//check for negative cyles 
			
			int flag=0;
			for(int i=0;i<e;i++){
				int s=edges[i][0];
				int d=edges[i][1];
				int w=edges[i][2];
				cout<<" s = "<< s << "d = "<< d << "w = "<< w<<endl;
				if(dist[s]!=INT_MAX && (dist[s]+w ) < dist[d]){
					flag=1;
				}
				
			}
			
			if(flag==1){
				cout<< "The graph contains negative cycles, bellmon ford cannot b applied "<<endl ;
			}
			else{
				for(int i=0;i<dist.size();i++){
					cout<< dist[i] << " ";
				}
			}
	}
		

	
	
};

int main(){
	int vertices,edges,u,v,w;
	cout<<"\nEnter the no of vetices and edges\n";
	cin>>vertices >>edges;
	graph g(vertices);
	cout<<"enter edges source, dest, weight\n" ;
	for(int i=0;i<edges;i++){
		cin>>u>>v>>w;
		g.addedge(u,v,w);
	}
	
	g.printgraph();
	
	int src,dest;
	cout<<"enter src and dest for bellmon ford \n";
	cin>>src >> dest;
	
	g.bellmonFord(vertices,edges,src,dest);
	g.kruksal();
	
	
//Input
//0 3 1
//0 1 2
//1 2 3
//1 3 3
//0 4 4
//2 3 5
//1 5 7
//2 5 8
//3 4 9
	
}
