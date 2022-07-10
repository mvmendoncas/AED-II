package matrizAdjacente;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * @author  Maria Virgínia Mendonça dos Santos
 */
public class Grafos {
    private List<String> vertices = new ArrayList<String>();
    private int numeroMaximoDeVertices;
    private int numeroAtualDeVertices;
    
    private Map<String, Integer> nomeEmIndices = new HashMap<String, Integer>();
    private MatrizAdjacencia matriz;

    public Grafos(int numeroMaximoDeVertices) {
        this.numeroMaximoDeVertices = numeroMaximoDeVertices;
        this.numeroAtualDeVertices = 0;
    }
    
   
    
    public void AdicionarVertice(String nome)  throws Exception{
        if(numeroAtualDeVertices <= numeroMaximoDeVertices - 1){
            if(isVerticeExists(nome)){
                throw new  Exception("O vértice  " + nome + " já existe!");
            }
            nomeEmIndices.put(nome, numeroAtualDeVertices);
            this.vertices.add(nome);
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
    
    public void conectarVertices(String nome_1, String nome_2)  throws Exception{
            if(!isVerticeExists(nome_1) || !isVerticeExists(nome_2)){
                throw new Exception("Ambos ou um dos vertices indicados não existem!");
            }
            criarMatrizDeAdjacencia();
            
            int indice_1 = this.nomeEmIndices.get(nome_1);
            int indice_2 = this.nomeEmIndices.get(nome_2);
            
            this.matriz.adicionaAresta(indice_1, indice_2);
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
            this.matriz = new MatrizAdjacencia(new ArrayList<String>(vertices));
        }
    }

   
    public void mostrarMatriz(){
        this.matriz.verMatriz();;
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

    public MatrizAdjacencia getMatriz() {
        return matriz;
    }

    public void setMatriz(MatrizAdjacencia matriz) {
        this.matriz = matriz;
    }


    
    
    
}
