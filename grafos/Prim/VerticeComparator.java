package listaPonderada;

import java.util.Comparator;

public class VerticeComparator implements Comparable<VerticeComparator> {
    int chave;
    char vertice;

    public VerticeComparator( int chave, char vertice){
        this.chave = chave;
        this.vertice = vertice;
    }

    @Override
    public int compareTo(VerticeComparator verticeComparator) {
        return Integer.compare(this.chave, verticeComparator.chave);
    }


    @Override
    public boolean equals(Object o) {
        if (o == this) {
            return true;
        }

        if (!(o instanceof VerticeComparator)) {
            return false;
        }

        VerticeComparator aresta = (VerticeComparator) o;

        return this.vertice == aresta.vertice;
    }

}