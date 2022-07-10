package matrizPonderada;

import java.util.Objects;

/**
 *
 * @author Maria Virgínia Mendonça dos Santos
 */
public class Aresta implements Comparable<Aresta>{
    private String  aresta;
    private int peso;

    public Aresta(String aresta, int peso) {
        this.aresta = aresta;
        this.peso = peso;
    }

    @Override
    public String toString() {
        return aresta + "[" + peso + "]";
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 37 * hash + Objects.hashCode(this.aresta);
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Aresta other = (Aresta) obj;
        return true;
    }

   

    @Override
    public int compareTo(Aresta o) {
        return  Integer.compare(this.peso, o.peso);
    }

    public String getAresta() {
        return aresta;
    }

    public void setAresta(String aresta) {
        this.aresta = aresta;
    }

    public int getPeso() {
        return peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }
    
    
    
    
    
        
    
    
    

    
    
    
    
}
