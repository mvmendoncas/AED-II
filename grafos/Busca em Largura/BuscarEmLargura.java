package matrizAdjacente;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author  Maria Virgínia Mendonça dos Santos
 */
public class BuscarEmLargura{ 
    MatrizAdjacencia matriz;
    Grafos grafo;
    int distancia[];
    Cores cor[];
    String pai[];
    
    public enum Cores {
        BRANCO,
        PRETO,
        CINZA
    }

    public BuscarEmLargura(MatrizAdjacencia matriz, Grafos grafo) {
        this.matriz = matriz;
        this.grafo = grafo;
        this.distancia = new int[matriz.getNumeroDeVertices()];
        this.cor = new Cores[matriz.getNumeroDeVertices()];
        this.pai = new String[matriz.getNumeroDeVertices()];
        
    }
     
    
    public void buscar(String origem){
        for(int i = 0; i < matriz.getNumeroDeVertices(); i++){
            cor[i] = Cores.BRANCO;
            distancia[i] = Integer.MAX_VALUE;
            pai[i] = null;
            
        }
        int indice = grafo.getNomeEmIndices().get(origem);
        distancia[indice] = 0;
        cor[indice] = Cores.CINZA;
        Queue<String> fila = new LinkedList<>();
        fila.add(origem);
        
        while(!fila.isEmpty()){
            String vertice = fila.poll();
            for(int i = 0; i < matriz.getNumeroDeVertices(); i++){
                int vizinho[] = grafo.linhaDaMatriz(vertice);
               
                if(vizinho[i] == 1){
                    if(cor[i] == Cores.BRANCO){
                        cor[i] = Cores.CINZA;
                        distancia[i] = distancia[grafo.getNomeEmIndices().get(vertice)]+1;
                        pai[i] = vertice;
                        fila.add(grafo.getVertices().get(i)); //TESTAR ESSA PARTE SEPARADA
                    }
                }
            }
            cor[grafo.getNomeEmIndices().get(vertice)] = Cores.PRETO;
        } 
        exibirGrafos(cor, distancia, pai);
       
    }
    
    public void exibirGrafos(Cores[] cor, int[] distancia, String[] pai){
        System.out.println("Cores: " + Arrays.toString(cor));
        System.out.println("Distancia: " + Arrays.toString(distancia));
        System.out.println("Pai: " + Arrays.toString(pai));
    }
    
    
    
}
