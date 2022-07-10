package listaAdjacente;

import java.util.LinkedList;
import java.util.List;

/**
 *
 * @author  Maria Virgínia Mendonça dos Santos
 */
public class ListaAdjacente {
    private  LinkedList<Character> vertices;
    private  LinkedList<Integer>[] indicesDeVertices;
    private  int numeroDeVertices;

    public ListaAdjacente(Character[] vertices, String[] arestas) {
        this.vertices = new LinkedList<>(List.of(vertices));
        this.numeroDeVertices = this.vertices.size();

        indicesDeVertices = new LinkedList[numeroDeVertices];
        for (int i = 0; i < numeroDeVertices; i++) {
            indicesDeVertices[i] = new LinkedList<>();
        }
        adicionarAresta(arestas);
        
    }
    
    public void adicionarAresta(String[] arestas){
         for (String edge : arestas) {
            char vertex1 = edge.charAt(0);
            char vertex2 = edge.charAt(1);

            int indiceVertice1 = this.vertices.indexOf(vertex1);
            int indiceVertice2 = this.vertices.indexOf(vertex2);

            indicesDeVertices[indiceVertice1].add(indiceVertice2);
            indicesDeVertices[indiceVertice2].add(indiceVertice1);
        }
    }

    @Override
    public String toString() {
        StringBuilder graph = new StringBuilder();

        for (int i = 0; i < numeroDeVertices; i++) {
            graph.append(vertices.get(i))
                    .append(": ");
            LinkedList<Integer> linkedList = indicesDeVertices[i];
            for (Integer index : linkedList) {
                graph.append(vertices.get(index))
                        .append(" -> ");
            }
            graph.append("\n");
        }

        return graph.toString();
    }

    public LinkedList<Character> getVertices() {
        return vertices;
    }

    public void setVertices(LinkedList<Character> vertices) {
        this.vertices = vertices;
    }

    public LinkedList<Integer>[] getIndicesDeVertices() {
        return indicesDeVertices;
    }

    public void setIndicesDeVertices(LinkedList<Integer>[] indicesDeVertices) {
        this.indicesDeVertices = indicesDeVertices;
    }

    public int getNumeroDeVertices() {
        return numeroDeVertices;
    }

    public void setNumeroDeVertices(int numeroDeVertices) {
        this.numeroDeVertices = numeroDeVertices;
    }
    
    
    
}
