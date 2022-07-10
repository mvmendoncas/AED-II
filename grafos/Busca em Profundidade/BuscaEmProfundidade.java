package listaAdjacente;

import java.lang.reflect.Array;
import java.util.Arrays;


/**
 *
 * @author  Maria Virgínia Mendonça dos Santos
 */
public class BuscaEmProfundidade {
    ListaAdjacente lista;
    Cores[] cor;
    Character[] predecessor;
    int[] d;  //tempo de duração
    int[] f;  //tempo final
    int contadorDeTempo;

    public enum Cores {
        BRANCO,
        PRETO,
        CINZA
    }

    public BuscaEmProfundidade(ListaAdjacente lista) {
        this.lista = lista;
        int indice = lista.getNumeroDeVertices();
        this.cor = new Cores[indice];
        this.predecessor = new Character[indice];
        this.d = new int[indice];
        this.f = new int[indice];
        
    }
    
    public void buscar(){
        int indice = lista.getNumeroDeVertices();
        for(int i = 0; i < indice; i++){
            cor[i] = Cores.BRANCO;
            predecessor[i] = null;
            d[i] = 0;
            f[i] = 0;
        }
        
        contadorDeTempo = 0;
        for(int i = 0; i < indice; i ++){
            if(cor[i] == Cores.BRANCO){
                dfs_Visit(i);
            }
        }
        verBuscaEmProfundidade();
    }
    
    private void dfs_Visit(int i) {
       d[i] = ++contadorDeTempo;
       cor[i] = Cores.CINZA;
       
       for(Integer vertice : lista.getIndicesDeVertices()[i]){
           if(cor[vertice] == Cores.BRANCO){
               predecessor[vertice] = lista.getVertices().get(i);
               dfs_Visit(vertice);
           }
       }
       cor[i] = Cores.PRETO;
       f[i] = ++contadorDeTempo;
    }
    
    private void verBuscaEmProfundidade(){
        System.out.println("Cores: " + Arrays.toString(this.cor));
        System.out.println("Predecessores: " + Arrays.toString(this.predecessor));
        System.out.println("Tempo Carregado: " + Arrays.toString(this.d));
        System.out.println("Tempo Final: " + Arrays.toString(this.f));
    }
    
}

