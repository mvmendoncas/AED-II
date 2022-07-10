package matrizAdjacente;
import java.util.LinkedList;
import java.util.List;

/**
 * 
 * @author Maria Virgínia Mendonça dos Santos
 */
public class MatrizAdjacencia {
   private  LinkedList<String> vertices;
   private  LinkedList<String> arestas;
   private  List<String> vertice;
   private  int matriz[][];
   private int numeroDeVertices;
  

    public MatrizAdjacencia(List<String> vertices) {
        this.vertice = vertices;
        this.numeroDeVertices = vertices.size();
        this.matriz = new int[numeroDeVertices][numeroDeVertices];
        
        for(int i = 0; i < this.numeroDeVertices; i++){
            for(int j = 0; j < this.numeroDeVertices; j++){
                if(i == j){
                    this.matriz[i][j] = 1;
                } else {
                    this.matriz[i][j] = 0;
                }
            }
        }
    }
    
    public void adicionaAresta(int v1, int v2){
       this.matriz[v1][v2] = 1;
       this.matriz[v2][v1] = 1;
       
    }
    
     public void verMatriz(){
        for(int i = 0; i < this.numeroDeVertices; i++){
            for (int j = 0; j < this.numeroDeVertices; j++){
                System.out.print(this.matriz[i][j] + " \t ");
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    
    

    public LinkedList<String> getVertices() {
        return vertices;
    }

    public void setVertices(LinkedList<String> vertices) {
        this.vertices = vertices;
    }

    public LinkedList<String> getArestas() {
        return arestas;
    }

    public void setArestas(LinkedList<String> arestas) {
        this.arestas = arestas;
    }

    public List<String> getVertice() {
        return vertice;
    }

    public void setVertice(List<String> vertice) {
        this.vertice = vertice;
    }

    public int getNumeroDeVertices() {
        return numeroDeVertices;
    }

    public void setNumeroDeVertices(int numeroDeVertices) {
        this.numeroDeVertices = numeroDeVertices;
    }

    public int[][] getMatriz() {
        return matriz;
    }

    public void setMatriz(int[][] matriz) {
        this.matriz = matriz;
    }
    
}
