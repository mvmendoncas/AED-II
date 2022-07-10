package listaPonderada;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
/**
 *
 * @author Maria Virgínia Mendonça dos Santos
 */
public class Prim {
    private listaAdjacentePonderada lista;
    private int chave[]; //recebe infinito
    private String pai[]; //recebe null

    public Prim(listaAdjacentePonderada lista) {
        int indice = lista.vertices.size();
        this.lista = lista;
        this.chave  = new int[indice]; 
        this.pai  = new String[indice]; 
    }

   
    public void algoritmoDePrim(Character v){
        //Inicializa as chaves com infinito e o pai com null
        for(int i = 0; i <lista.vertices.size(); i++){
            chave[i] = Integer.MAX_VALUE;
            pai[i] = null;
        }  
        //chave[pontoDePartida] = 0
        int pontoDePartida = lista.nomeEmIndices.get(v);
        chave[pontoDePartida] = 0;
        
        //filaDePrioridade = vertices   
        PriorityQueue<VerticeComparator> filaDePrioridade = new PriorityQueue<VerticeComparator>();
          
        int i = 0;
        for (Character vertices : this.lista.vertices) {
            filaDePrioridade.add(new VerticeComparator(chave[i], this.lista.containsVertices[i]));
            i++;
        }
        int cont = 0;
        //Se a fila não estiver vazia
        while(!filaDePrioridade.isEmpty()){
            //retirar o primeiro elemento
            VerticeComparator u = filaDePrioridade.poll();
            char verticeU = u.vertice;
          
            //percorre a lista de adjacencia daquele elemento
            //para todo elemento adjcente a esse elemento recem incluido
            LinkedList<No> linkedList = lista.listaDeArestas[lista.nomeEmIndices.get(verticeU)];
            
            for(No indice : linkedList){  
               filaDePrioridade.remove(u);
               
               VerticeComparator aresta = new VerticeComparator(indice.peso, indice.no.charAt(0));
               //Verifica se os elementos pertencem a fila e se o peso da aresta é menor que a chave[v] 
               if(filaDePrioridade.contains(aresta) && indice.peso < chave[lista.nomeEmIndices.get(aresta.vertice)]){
                   //O predecessor de v rebece o a
                   pai[lista.nomeEmIndices.get(aresta.vertice)] = Character.toString(u.vertice);
                   
                   //atualiza chave com o peso de v 
                   chave[lista.nomeEmIndices.get(indice.no.charAt(0))] = aresta.chave;
                    
                   filaDePrioridade.add(aresta); 
                  
               }
            
            }     
            
        }
        
        for(int c = 0; c < chave.length; c++){
            cont+= chave[c];
        }
        
         verPrim(cont);
        
                
    }

    private void verPrim(int cont) {
        System.out.println("Predecessor: " + Arrays.toString(pai));
        System.out.println("Chaves: " + Arrays.toString(chave));
        System.out.println("Soma dos pesos: " + cont);
    }

  
    
   
    
}
