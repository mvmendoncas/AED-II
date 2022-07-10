package matrizPonderada;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * Classe criada com o intuito de testar o algoritmo de Kruskal
 * Para inserir os arquivos no bufferReader, no linux, siga o seguinte exemplo:
 * -> matrizPonderada.testes\teste.txt
 * @author Maria Virgínia Mendonça dos Santos
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        String[] vertices;
        String[] arestas;
                
        String verticeOrigemDaBusca;
        boolean verificaVertice = false;
                                                                  //Ex -> matrizPonderada.testes\teste.txt
                                                                  //Ou copie o diretório da pasta
        try(BufferedReader file = new BufferedReader(new FileReader("C:\\Users\\maria\\OneDrive\\Documentos\\NetBeansProjects\\MainSegundaParte\\src\\main\\java\\matrizPonderada\\testes\\teste.txt"))){
            String linha = file.readLine();
            Scanner scan = new Scanner(linha);
            
            int numeroDeVertices = scan.nextInt();
            int numeroDeArestas = scan.nextInt();
            
            Grafo grafo = new Grafo(numeroDeVertices);

            vertices = new String[numeroDeVertices];
            arestas = new String[numeroDeArestas];
            
            for (int i = 0; i < numeroDeVertices; i++) {
                linha = file.readLine();
                vertices[i] = linha.toUpperCase();
                grafo.AdicionarVertice(vertices[i]);
                
            }
            for (int i = 0; i < numeroDeArestas; i++) {
                    linha = file.readLine();
                    Scanner lerAresta = new Scanner(linha);
                    String verticesDaAresta = lerAresta.next().toUpperCase();
                    int peso = lerAresta.nextInt();
                    String v1 = Character.toString(verticesDaAresta.charAt(0));
                    String v2 = Character.toString(verticesDaAresta.charAt(1));
                    grafo.conectarVertices(v1, v2, peso); 
                   
            }
            
            System.out.println("Grafo da Matriz de Adjacência Ponderada");
            //grafo.mostrarMatriz();
            System.out.println(grafo);
            
            System.out.println("");
            System.out.println("================================================================");
            System.out.println("");
            
            System.out.println("Algoritmo de Kruskal");
            Kruskal kruskal = new Kruskal(grafo);
            kruskal.algoritmoDeKruskal();
            
            
         
           
        } catch (IOException e) {
            throw new RuntimeException(e);
        }  
        
        
        
        
        
        
        
        
        /**
        Grafos grafo = new Grafos(9);
        try{
            grafo.AdicionarVertice("A");
            grafo.AdicionarVertice("B");
            grafo.AdicionarVertice("C");
            grafo.AdicionarVertice("D");
            grafo.AdicionarVertice("E");
            grafo.AdicionarVertice("F");
            grafo.AdicionarVertice("G");
            grafo.AdicionarVertice("H");
            grafo.AdicionarVertice("I");
            
            grafo.conectarVertices("A", "B", 4); 
            grafo.conectarVertices("A", "H", 8); 
            grafo.conectarVertices("B", "H", 11); 
            grafo.conectarVertices("H", "I", 7); 
            grafo.conectarVertices("H", "G", 1); 
            grafo.conectarVertices("I", "G", 6); 
            grafo.conectarVertices("I", "C", 2); 
            grafo.conectarVertices("B", "C", 8); 
            grafo.conectarVertices("G", "F", 2); 
            grafo.conectarVertices("C", "F", 4); 
            grafo.conectarVertices("C", "D", 7); 
            grafo.conectarVertices("D", "F", 14); 
            grafo.conectarVertices("D", "E", 9); 
            grafo.conectarVertices("F", "E", 10); 
            grafo.mostrarMatriz();
            
            Kruskal k = new Kruskal(grafo);
           // System.out.println( k.arestas.toString());
            k.algoritmoDeKruskal();
           
            
            
            
           //  BuscarEmLargura busca = new BuscarEmLargura(grafo.getMatriz(), grafo);
            // busca.buscar("S");
        }catch (Exception e) {
			System.out.println(e.getMessage());
		}*/
        
    }
    
}

