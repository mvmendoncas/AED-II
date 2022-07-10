package matrizPonderada;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * @author Maria Virgínia Mendonça dos Santos
 */
public class MatrizAdjacentePonderada {
   private  int arestas;
   private  List<String> vertice;
   private  int matriz[][];
   private int numeroDeVertices;
  
   private Map<String, Integer> arestasEmIndices = new HashMap<String, Integer>();
  

    public MatrizAdjacentePonderada(List<String> vertices) {
        this.vertice = vertices;
        this.numeroDeVertices = vertices.size();
        this.arestas = 0;
        this.matriz = new int[numeroDeVertices][numeroDeVertices];
        
        for(int i = 0; i < this.numeroDeVertices; i++){
            for(int j = 0; j < this.numeroDeVertices; j++){
                matriz[i][j] = 0;
            }
        }
    }
    
    public void adicionaAresta(int v1, int v2, int peso){
       this.matriz[v1][v2] = peso;
       this.matriz[v2][v1] = peso;
       this.arestas++;
    }
    
    public int numeroDeArestas(){
        return this.arestas;
    }
    
    public void indexarArestas(String aresta, int peso){
        this.arestasEmIndices.put(aresta, peso);
    }
    
    public int getArestas() {
        return arestas;
    }

    public void setArestas(int arestas) {
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
