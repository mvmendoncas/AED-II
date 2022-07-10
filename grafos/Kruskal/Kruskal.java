package matrizPonderada;

import java.util.Collections;
import java.util.HashSet;
import java.util.List;


/**
 *
 * @author  Maria Virgínia Mendonça dos Santos
 */
public class Kruskal {
    Grafo grafo;
    List<Aresta> arestas;
    HashSet conjuntoDeVertices; //Conjunto de vertices

   
    public Kruskal(Grafo grafo) {
       this.grafo = grafo;
       this.conjuntoDeVertices  = new HashSet<>();    
       this.arestas = grafo.getListaDePesosArestas(); 
    }
    public String encontrarConjunto(HashSet<String> conjunto, String nome){
        for (String c : conjunto){
            if(c.contains(nome)){
                return c;
            }
        }
        return null;
    }
    
   public void algoritmoDeKruskal(){
       HashSet arvoreMinima = new HashSet<>();
       this.conjuntoDeVertices = grafo.getConjuntoDeVertices();
   
       Collections.sort(arestas);
       System.out.println("Arestas e pesos em ordem não decrescente: " + arestas.toString());
       String u, v;
       String origem, destino;
       int cont = 0;
       for(Aresta a : arestas){
           origem = Character.toString(a.getAresta().charAt(0));
           destino = Character.toString(a.getAresta().charAt(1));
           u = encontrarConjunto(this.conjuntoDeVertices, origem);
           v = encontrarConjunto(this.conjuntoDeVertices, destino);
           if(!u.equals(v)){
               cont += a.getPeso();
               this.conjuntoDeVertices.remove(u);
               this.conjuntoDeVertices.remove(v);
               this.conjuntoDeVertices.add(u+v);
               String aresta = a.getAresta();
               arvoreMinima.add(aresta);
                   
           }
       }
       System.out.println("Árvore Mínima: " + arvoreMinima);
       System.out.println("Soma dos Pesos: " + cont);  
       
   }
   
   
   
    /**
    for(HashSet<Vertice> conjunto : listaConjuntos)
			if(conjunto.contains(procurado))
				c1 = conjunto;
		
		
		listaConjuntos.remove(c1);
		c1.addAll(c2);
		listaConjuntos.add(c1);
    public Aresta encontrarConjuntos(Aresta a){
        
    }
    0*/  
    
}
