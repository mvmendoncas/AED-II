package listaPonderada;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * Classe criada com o intuito de testar o algoritmo de Prim
 * Para inserir os arquivos no bufferReader, no linux, siga o seguinte exemplo:
 * -> listaPonderada.teste\teste.txt
 * @author Maria Virgínia Mendonça dos Santos
 */
public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Character[] vertices;
        No[] arestas;
        String verticeOrigemDaBusca;
        boolean verificaVertice = false;
                                                    //Ex -> listaPonderada.teste\teste.txt
                                                    //Ou copie o diretório da pasta
        try(BufferedReader file = new BufferedReader(new FileReader("C:\\Users\\maria\\OneDrive\\Documentos\\NetBeansProjects\\MainSegundaParte\\src\\main\\java\\listaPonderada\\teste\\teste.txt"))){
            String linha = file.readLine();
            Scanner scan = new Scanner(linha);
            
            int numeroDeVertices = scan.nextInt();
            int numeroDeArestas = scan.nextInt();

            vertices = new Character[numeroDeVertices];
            arestas = new No[numeroDeArestas];
            
            for (int i = 0; i < numeroDeVertices; i++) {
                linha = file.readLine();
                vertices[i] = linha.charAt(0);
            }
            for (int i = 0; i < numeroDeArestas; i++) {
                    linha = file.readLine();
                    Scanner verticesDaAresta = new Scanner(linha);
                    String aresta =  verticesDaAresta.next();
                    int peso =  verticesDaAresta.nextInt();
                    arestas[i] = new No(aresta, peso);
                }
            
            System.out.println("Grafo da Lista de Adjacência");
            listaAdjacentePonderada l = new listaAdjacentePonderada(vertices, arestas);
            System.out.println(l);
            
            System.out.println("");
            System.out.println("=============================================================");
            System.out.println("");
            
            System.out.println("Algoritmo de Prim");
            System.out.println("Insira o vertice de partida: ");
            verticeOrigemDaBusca = entrada.nextLine();
            Prim prim = new Prim(l);
            System.out.println("Algoritmo de Prim");
            for (int i = 0; i < numeroDeVertices; i++) {
               if(verticeOrigemDaBusca.toUpperCase().charAt(0) == (vertices[i])){
                   verificaVertice = true;
               }
            }
            if(verificaVertice == true){
                System.out.println("Resultado da busca em profundidade");
                prim.algoritmoDePrim(verticeOrigemDaBusca.toUpperCase().charAt(0));
            } else {
                System.out.println("Esse vertice não pertence a essa lista");
            }
            
            
           
            
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        
        
        
        
        
        
        
        
        
        
        /**
        Character v[]= new Character[9];
        v[0] = 'A';
        v[1] = 'B';
        v[2] = 'C';
        v[3] = 'D';
        v[4] = 'E';
        v[5] = 'F';
        v[6] = 'G';
        v[7] = 'H';
        v[8] = 'I';
        
        
        No n[] = new No[14];
        n[0] = new No("AB", 4);
        n[1] = new No("AH", 8);
        n[2] = new No("BH", 11);
        n[3] = new No("HI", 7);
        n[4] = new No("HG", 1);
        n[5] = new No("IG", 6);
        n[6] = new No("IC", 2);
        n[7] = new No("BC", 8);
        n[8] = new No("GF", 2);
        n[9] = new No("CF", 4);
        n[10] = new No("CD", 7);
        n[11] = new No("DF", 14);
        n[12] = new No("DE", 9);
        n[13] = new No("FE", 10);
       
        
        
        listaAdjacentePonderada l = new listaAdjacentePonderada(v, n);
        System.out.println(l);
       Prim p = new Prim(l);
        
       p.algoritmoDePrim('C');*/
      
    }
    
}
