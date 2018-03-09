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

root.visited = true; 
LinkedList<Node> popQueue = new LinkedList();
// need to maintain a node queue

popQueue.add(root);

while(popQueue.size()>0)
{    // iterate over the connected nodes 
     v = popQueue.poll();
     System.out.prinln(v.vertexId);

    for(Node node: v.getList())
    {
    if(!node.visited)
     {
       // mark the visited node true
      node.visited = true;
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
  de.addVertice(ab);
  bc.addVertice(ab);

   

        System.out.println("Following is Breadth First Traversal "+
                        "(starting from vertex 2)");

        g.bfs(2,g);
        g.dfs(2);
    }
    
    public class Node{
  int vertexId;
  boolean visited;
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

