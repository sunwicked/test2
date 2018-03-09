// Java program to print BFS traversal from a given source vertex.
import java.io.*;
import java.util.*;

// This class represents a directed graph using adjacency list
// representation
class Graph
{
   

    private List<Node> nodes; 
    // Constructor
    Graph()
    {
       nodes = new ArrayList();
    }



 public  Node addNode(int vertice , Graph g)
  {
   Node node = new Node(vertice);
       g.nodes.add(node);
       return node;
  }
  
  void bfs(int v, Graph g)
  {
    // visit each node at a level 
    // mark visisted node  - need a visited property
    // 
Node root =     g.nodes.get(v);
boolean[] visited = new boolean[g.nodes.size()];
visited[root.vertexId]=true;
LinkedList<Node> popQueue = new LinkedList();
// need to maintain a node queue

popQueue.add(root);

while(popQueue.size()>0)
{    // iterate over the connected nodes 
    Node nxt =popQueue.poll();
     System.out.println(nxt.vertexId + "");

    for(Node node: nxt.getList())
    {
    if(!visited[node.vertexId])
     {
       // mark the visited node true
      visited[node.vertexId]=true;
      System.out.println(node.vertexId);
      popQueue.add(node);

     }
    }
 }  
  }
  
  
  void dfs(int v)
  {
  
  }

    // Function to add an edge into the graph
    
    public static void main(String args[])
    {
        Graph g = new Graph();

     Node ab = g.addNode(0,g);     
     Node bc = g.addNode(1,g);
     Node cd = g.addNode(2,g);
     Node de = g.addNode(3,g);
  
  ab.addVertice(de);
  bc.addVertice(ab); 
  de.addVertice(cd);
  de.addVertice(bc);

   

        System.out.println("Following is Breadth First Traversal "+
                        "(starting from vertex 0)");

        g.bfs(0,g);
        g.dfs(2);
    }
    /**
    * How can we prevent creation of multiple nodes with same vertex Ids ? 
    **/
    public class Node{
 public int vertexId;
  boolean visited; // can we not use this property
  List<Node> adjanceyVertices = new ArrayList();
  
      Node(int v ){
       this.vertexId = v;  
       visited = false; 
      }
      
     public void addVertice(Node value)
      {
       adjanceyVertices.add(value);
      }
      
      public List<Node> getList()
      {
       return adjanceyVertices; 
      }
      }

}

