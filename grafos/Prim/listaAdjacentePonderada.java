package listaPonderada;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 *
 * @author Maria Virgínia Mendonça dos Santos
 */
public class listaAdjacentePonderada {
    public  LinkedList<Character> vertices;
    public  LinkedList<No>[] listaDeArestas;
    public  Character[] containsVertices;
    public  int numeroDeVertices;
    public  Map<Character, Integer> nomeEmIndices = new HashMap<Character, Integer>();
   

    public listaAdjacentePonderada(Character[] vertices, No[] arestas) {
        this.vertices = new LinkedList<>(List.of(vertices));
        this.containsVertices = vertices;
        numeroDeVertices = this.vertices.size();
    
        listaDeArestas = new LinkedList[numeroDeVertices];
        for (int i = 0; i < numeroDeVertices; i++) {
            listaDeArestas[i] = new LinkedList<>();
            this.nomeEmIndices.put(vertices[i], i);         
        }
        adicionarAresta(arestas);
        
    }
    
    public void adicionarAresta(No[] arestas){
         for (No a : arestas) {
            char v1 = a.no.charAt(0);
            char v2 = a.no.charAt(1);

            int indice_1 = this.nomeEmIndices.get(v1);
            int indice_2 = this.nomeEmIndices.get(v2);
            
            String origem = String.valueOf(v2);
            String destino = String.valueOf(v1);
            
            listaDeArestas[indice_1].add(new No(origem, a.peso));
            listaDeArestas[indice_2].add(new No(destino, a.peso));
            
        }
        
    }
  
    
      @Override
    public String toString() {
        StringBuilder lista = new StringBuilder();

        for (int i = 0; i < numeroDeVertices; i++) {
            lista.append(vertices.get(i))
                    .append(": ");
            LinkedList<No> linkedList = this.listaDeArestas[this.nomeEmIndices.get(this.containsVertices[i])];
            for (No indice : linkedList) {
                String aresta = indice.no + "[" + indice.peso + "]";
                lista.append("").append(aresta).append(" -> ");
            }
            lista.append("\n");
        }

        return lista.toString();
    }

}
   


