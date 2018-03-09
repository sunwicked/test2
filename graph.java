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
    Node root = g.nodes.get(v); 
    Set<Node> visited = new HashSet();
    visited.add(root);
     Deque<Node> popQueue = new ArrayDeque();
    // need to maintain a node queue

    popQueue.add(root);

    while(popQueue.size()>0)
    {    // iterate over the connected nodes 
       Node nxt =popQueue.poll();
        System.out.println(nxt.vertexId + "");

    for(Node node: nxt.getList())
    {
      if(!visited.contains(node))
       {
       // mark the visited node true
       visited.add(node);
       popQueue.add(node);

     }
    }
 }  
  }
  
 void dfsUtil(Node node,Set<Node>visited)
 {
     visited.add(node);
     System.out.println(node.vertexId + " ");
     Iterator<Node> it =  node.getList().listIterator();
     while(it.hasNext())
     {
         Node nex = it.next();
         if(!visited.contains(nex))
         {
             dfsUtil(nex,visited);
         }
     }
 }
  
  void dfs(int v,Graph g)
  {
   // visit a node check if it is visited 
   // if not push on stack else pop
   Node root = g.nodes.get(v);
   Set<Node> visited =  new HashSet();
   dfsUtil(root,visited);
   
   
   
   
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
        g.dfs(2,g);
    }
    
 public class Node{
   public int vertexId;
   List<Node> adjanceyVertices = new ArrayList();
  
    Node(int v ){
        this.vertexId = v;  
        
    }
      
    public void addVertice(Node value){
       adjanceyVertices.add(value);
    }
      
      public List<Node> getList()
      {
       return adjanceyVertices; 
      }
 }

}

