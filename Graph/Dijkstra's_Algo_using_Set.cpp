// We use set to erase the part that are unnecessary

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node. 
        set<pair<int,int> > st;
        vector<int> dist(V, 1e9);

        st.insert({0,S});
        dist[S] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];

                if(dis + edgeWeight < dist[adjNode]){
                    // erase if it exists
                    if(dist[adjNode] != 1e9 ){
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};




// At the worst Case the Time COmolixity is O(E*logV);

