# include<iostream>
# include<utility>
# include<set>
# include<vector>
using namespace std;

class graph{
	public:
	int vertices;
	vector<vector<pair<int,int> > > adj;
	
	graph(int v){
		vertices=v;
		adj.resize(v);
		
	}
	void addedge(int source, int dest, int weight){
		pair<int, int> t;
		t.first=weight;
		t.second=dest;
		adj[source].push_back(t);
		adj[dest].push_back(make_pair(weight,source));
	}
	void printgraph(){
		for(int i=0;i<adj.size();i++){
			cout<< "source node = " << i <<" ";
			for(int k=0;k<adj[i].size();k++){
				cout<<" dest node = "<<adj[i][k].second <<" ";
				cout<<" wieght = " << adj[i][k].first <<endl;
			}
			cout<<endl;
		}
	}
	
	void dijkstras(int s){
		vector<int> dist(vertices,INT_MAX);
		set<pair<int,int> > st;
		dist[s]=0;
		st.insert(make_pair(0,s));
		while(st.empty()!=true){
			pair<int,int> top= *(st.begin());
			int topnode=top.second;
			int topweight=top.first;
			st.erase(st.begin());
			//cout<<"topnode = " << topnode << "   topweight = "<< topweight;
			for(int i=0;i<adj[topnode].size();i++){
				//cout<< "\nadj[topnode][i].first =  " << adj[topnode][i].first;
				//cout<< "\nadj[topnode][i].second =  "<< adj[topnode][i].second;
				if(topweight + adj[topnode][i].first < dist[adj[topnode][i].second]){
					
					set<pair<int,int> >::iterator temp= st.find(make_pair(dist[adj[topnode][i].second],adj[topnode][i].second));
					if(temp!=st.end()){
						st.erase(temp);
					}
					
					dist[adj[topnode][i].second] = topweight + adj[topnode][i].first;
					st.insert(make_pair(dist[adj[topnode][i].second],adj[topnode][i].second));
				}
			}
		}
		cout<<"\nDistance \n";
		for(int x=0;x<dist.size();x++){
			cout<<x << " = " << dist[x] <<endl;
		}
		
	}
	
	void primsAlgoMST(){
		
		vector<int> key(vertices,INT_MAX);
		vector<int> parent(vertices,-1);
		vector<bool> MST(vertices,false);
		
		key[0]=0;
		parent[0]=-1;
		
		for(int x=0;x<vertices;x++){
		
			int u , mini=INT_MAX;
			for(int i=0;i<key.size();i++){
				if(MST[i]==false && key[i]<mini){
					u=i;
					mini=key[i];
				}
			}
			
			MST[u]=true;
			
			for(int v=0;v<adj[u].size();v++){
				int node= adj[u][v].second;
				int nodeWeight= adj[u][v].first;
				cout<< "node = "<< node << endl;
				cout<< "nodeWeight" << nodeWeight<<endl; 
				if(MST[node]==false && nodeWeight< key[node]){
					key[node]= nodeWeight;
					parent[node]=u;
				}
			}
		
		}
		
		//print parent array
		cout<<"\nparent";
		for(int j=0;j<parent.size();j++){
			cout<< parent[j] << " ";
			
		}
		cout<<"\nMST\n";
		
		for(int j=0;j<parent.size();j++){
			cout<< MST[j] << " ";
			
		}
		cout<<"key\n";
		for(int j=0;j<parent.size();j++){
			cout<< key[j] << " ";
			
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
//	g.dijkstras(0);
	g.primsAlgoMST();
	
	
}

