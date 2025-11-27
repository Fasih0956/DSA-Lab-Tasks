// Was given choice to do any 1 of Q5 and Q6 , done Q5 
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;
public:
    Graph(int vertices){
        V = vertices + 1;
        adjList.resize(V);
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    
    // Adding edges
    void addEdge(int u, int v){
        // For adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
        // For adjacency matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    // Displaying adjacency list
    void displayAdjList(){
        cout<<"Adjacency List:"<<endl;
        for(int i = 1; i < V; i++){
            cout<<i<<" -> ";
            for(int neighbor : adjList[i]){
                cout<<neighbor<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    // Displaying adjacency matrix
    void displayAdjMatrix(){
        cout<<"Adjacency Matrix:"<<endl;
        cout<<"  ";
        for(int i = 1; i < V; i++){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i = 1; i < V; i++){
            cout<<i<<" ";
            for(int j = 1; j < V; j++) {
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    // BFS traversal
    void BFS(int startVertex){
        vector<bool> visited(V, false);
        queue<int> q;
        cout<<"BFS Traversal: ";
        
        visited[startVertex] = true;
        q.push(startVertex);
        
        while(!q.empty()){
            int current = q.front();
            q.pop();
            cout<<current<<" ";
            
            for(int neighbor : adjList[current]){
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    // DFS traversal
    void DFS(int startVertex){
        vector<bool> visited(V, false);
        stack<int> st;
        cout<<"DFS Traversal: ";
        st.push(startVertex);
        visited[startVertex] = true;
        
        while(!st.empty()){
            int current = st.top();
            st.pop();
            cout<<current<<" ";
            
            for(auto it = adjList[current].rbegin(); it != adjList[current].rend(); it++){
                if(!visited[*it]) {
                    visited[*it] = true;
                    st.push(*it);
                }
            }
        }
        cout<<endl;
    }
};
int main(){
    // Create graph with 5 vertices (1 to 5)
    Graph g(5);
    
    // Add edges for your graph using 1-based indexing:
    // 1-4, 4-2, 4-5, 2-5, 5-3
    g.addEdge(1, 4); // 1-4
    g.addEdge(4, 2); // 4-2
    g.addEdge(4, 5); // 4-5
    g.addEdge(2, 5); // 2-5
    g.addEdge(5, 3); // 5-3
    
    cout<<"<---GRAPH IMPLEMENTATION--->"<<endl;
    
    g.displayAdjList();   //Displaying List
    g.displayAdjMatrix();   //Displaying matrix
    
    cout<<"<---GRAPH TRAVERSALS--->"<<endl;
    g.BFS(1);
    g.DFS(1);
    return 0;
}