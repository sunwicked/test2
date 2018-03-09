// Java program to print BFS traversal from a given source vertex.
// BFS(int s) traverses vertices reachable from s.
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

static class Node()
{
  int vertexId;
  boolean visited;
  List<Node> adjanceyVertices = new ArrayList();
  
      Node(int v ){
       this.vertexId = v;  
       visited = false; 
      }
      
     public void addVertice(Node value)
      {
       adcencyVertices.add(value);
      }
      
      public List<Node> getList()
      {
       return adcencyVertices; 
      }
      
}

 public  Node addNode(int vertice )
  {
   Node node = new Node(vertice);
       g.addNode(node);
       return node
  }
  
  BFS(int v, Graph g)
  {
    // visit each node at a level 
    // mark visisted node  - need a visited property
    // 
Node root =     g.getNodes.get(v);

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
  
  
  DFS(int v)
  {
  
  }

    // Function to add an edge into the graph
    
    public static void main(String args[])
    {
        Graph g = new Graph();

     Node ab =   addNode(0 );     
                 Node bc =   addNode(1 );
Node cd                     addNode(2);
  Node de =                          addNode(3 );
  
  ab.addVertices(de);
  de.addVertices(ab);
  bc.addVertices(ab);

   

        System.out.println("Following is Breadth First Traversal "+
                        "(starting from vertex 2)");

        g.BFS(2);
        g.DFS(2);
    }
}
// This code is contributed by Aakash Hasija
