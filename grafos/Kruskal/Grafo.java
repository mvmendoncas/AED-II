package matrizPonderada;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

/**
 *
 * @author Maria Virgínia Mendonça dos Santos
 */
public class Grafo {
    private List<String> vertices;
    private List<String> arestas;
    private List<Aresta> listaDePesosArestas;
    private int numeroMaximoDeVertices;
    private int numeroAtualDeVertices;
    private HashSet<String> conjuntoDeVertices = new HashSet<>();
   
    
    private Map<String, Integer> nomeEmIndices = new HashMap<String, Integer>();
    private MatrizAdjacentePonderada matriz;

    public Grafo(int numeroMaximoDeVertices) {
        this.numeroMaximoDeVertices = numeroMaximoDeVertices;
        this.numeroAtualDeVertices = 0;
        this.vertices  = new ArrayList<String>();
        this.arestas  = new ArrayList<String>();
        this.listaDePesosArestas  = new ArrayList<Aresta>();
        
    }
    
   
    
    public void AdicionarVertice(String nome)  throws Exception{
        if(numeroAtualDeVertices <= numeroMaximoDeVertices - 1){
            if(isVerticeExists(nome)){
                throw new  Exception("O vértice  " + nome + " já existe!");
            }
            nomeEmIndices.put(nome, numeroAtualDeVertices);
            this.vertices.add(nome);
            this.conjuntoDeVertices.add(nome);
           
            numeroAtualDeVertices++;
        } else{
            throw new Exception("Limite da quantidade máxima de vértices: " + numeroMaximoDeVertices);
        }
    }
    
    public List<String> listarVertices(){
        return Collections.unmodifiableList(vertices);
    }
    
    public int[] linhaDaMatriz(String vertice){
        int indice = nomeEmIndices.get(vertice);
        int linha[]= matriz.getMatriz()[indice];
        
        return linha;
        
    }
    
    public void conectarVertices(String nome_1, String nome_2, int peso)  throws Exception{
            if(!isVerticeExists(nome_1) || !isVerticeExists(nome_2)){
                throw new Exception("Ambos ou um dos vertices indicados não existem!");
            }
            criarMatrizDeAdjacencia();
            
            int indice_1 = this.nomeEmIndices.get(nome_1);
            int indice_2 = this.nomeEmIndices.get(nome_2);
            String aresta = nome_1+nome_2;
            
            this.matriz.adicionaAresta(indice_1, indice_2, peso);
            this.matriz.indexarArestas(aresta, peso);
            
            this.arestas.add(aresta);
            Aresta a = new Aresta(aresta, peso);
            this.listaDePesosArestas.add(a);
    }
    
    private boolean isVerticeExists(String nome){
        if(this.nomeEmIndices.containsKey(nome)){
            return true;
        } else {
            return false;
        }
    }
    private boolean isVerticeExistsOrThrow(String nome){
        if(!isVerticeExists(nome)){
            throw new IllegalArgumentException("O vértice não existe!");
        }
        return true;
    }
    
    private void criarMatrizDeAdjacencia(){
        if(this.matriz == null){
            this.matriz = new MatrizAdjacentePonderada(new ArrayList<String>(vertices));
        }
    }
    
    
    @Override
    public String toString() {
        StringBuilder grafo = new StringBuilder();
        
        
        grafo.append("\t");
        
        for(String vertice : this.vertices){
            grafo.append(vertice).append("\t");
        }
        grafo.append("\n");
        
        for(int i = 0; i < this.numeroMaximoDeVertices; i++){
            grafo.append(this.vertices.get(i)).append("\t");
            for(int j = 0; j < this.numeroMaximoDeVertices; j++){
                grafo.append(this.matriz.getMatriz()[i][j]).append("\t");
            }
            grafo.append("\n");
        }
        return grafo.toString();
        
    }
   
    public int getNumeroMaximoDeVertices() {
        return numeroMaximoDeVertices;
    }

    public void setNumeroMaximoDeVertices(int numeroMaximoDeVertices) {
        this.numeroMaximoDeVertices = numeroMaximoDeVertices;
    }

    public int getNumeroAtualDeVertices() {
        return numeroAtualDeVertices;
    }

    public void setNumeroAtualDeVertices(int numeroAtualDeVertices) {
        this.numeroAtualDeVertices = numeroAtualDeVertices;
    }

    public Map<String, Integer> getNomeEmIndices() {
        return nomeEmIndices;
    }

    public void setNomeEmIndices(Map<String, Integer> nomeEmIndices) {
        this.nomeEmIndices = nomeEmIndices;
    }

    public List<String> getVertices() {
        return vertices;
    }

    public void setVertices(List<String> vertices) {
        this.vertices = vertices;
    }

    public MatrizAdjacentePonderada getMatriz() {
        return matriz;
    }

    public void setMatriz(MatrizAdjacentePonderada matriz) {
        this.matriz = matriz;
    }

    public List<String> getArestas() {
        return arestas;
    }

    public void setArestas(List<String> arestas) {
        this.arestas = arestas;
    }

    public List<Aresta> getListaDePesosArestas() {
        return listaDePesosArestas;
    }

    public void setListaDePesosArestas(List<Aresta> listaDePesosArestas) {
        this.listaDePesosArestas = listaDePesosArestas;
    }

    public HashSet<String> getConjuntoDeVertices() {
        return conjuntoDeVertices;
    }

    public void setConjuntoDeVertices(HashSet<String> conjuntoDeVertices) {
        this.conjuntoDeVertices = conjuntoDeVertices;
    }


    
    
    
}
