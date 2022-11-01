class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& arr) 
{
	int n=arr.size();
	vector<int>parent(n,-1);
	vector<int>size(n,0);
	
	for(int i=0;i<parent.size();i++)
	{
		parent[i]=i;  
		size[i]=1;   
	}

    vector<pair<int,pair<int,int>>>edges;
	
    for(int i=0;i<arr.size();i++)   
	{
       int xi=arr[i][0];
       int yi=arr[i][1];
       
       for(int j=i+1;j<arr.size();j++)
       {
       	  int xj=arr[j][0];
       	  int yj=arr[j][1];
       	  
       	  int dis=abs(xi-xj) + abs(yi-yj);
       	  
       	  edges.push_back(make_pair(dis,make_pair(i,j)));
	   }
    }   
    
	sort(edges.begin(),edges.end()); 
	pair<int,pair<int,int>>p;
	
	int cost=0;
	for(int i=0;i<edges.size();i++)
	{
		p=edges[i];
	    int w=p.first;
	    int u=p.second.first;
	    int v=p.second.second;
	    
	    int a=find_set(u,parent);
	    int b=find_set(v,parent);
	    
	    
	    if(a==b)  
	    {
	    	continue;
		}
		else
		{
			cost=cost+w;		
			
			
			if(size[b]>size[a])
			{
				swap(a,b);
			}
			parent[b]=a;
			size[a]+=size[b];
		}
	}
	return cost;
}
int find_set(int v,vector<int>&parent)
{
	if(parent[v]==v)
	{
		return v;
	}
	return parent[v]=find_set(parent[v],parent);
}
};