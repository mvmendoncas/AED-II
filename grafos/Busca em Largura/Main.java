package matrizAdjacente;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * Classe criada com o intuito de testar a busca em largura
 * Para inserir os arquivos no bufferReader, no linux, siga o seguinte exemplo:
 * -> matrizAdjacente.testes\teste.txt
 * @author Maria Virgínia Mendonça dos Santos
 */
public class Main{

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        String[] vertices;
        String[] arestas;
                
        String verticeOrigemDaBusca;
        boolean verificaVertice = false;
                                                      //Ex -> matrizAdjacente.testes\teste.txt
                                                      //Ou copie o diretório da pasta
        try(BufferedReader file = new BufferedReader(new FileReader("C:\\Users\\maria\\OneDrive\\Documentos\\NetBeansProjects\\Main\\src\\main\\java\\matrizAdjacente\\testes\\teste.txt"))){
            String linha = file.readLine();
            Scanner scan = new Scanner(linha);
            
            int numeroDeVertices = scan.nextInt();
            int numeroDeArestas = scan.nextInt();
            
            Grafos grafo = new Grafos(numeroDeVertices);

            vertices = new String[numeroDeVertices];
            arestas = new String[numeroDeArestas];
            
            for (int i = 0; i < numeroDeVertices; i++) {
                linha = file.readLine();
                vertices[i] = linha.toUpperCase();
                grafo.AdicionarVertice(vertices[i]);
            }
            for (int i = 0; i < numeroDeArestas; i++) {
                    linha = file.readLine();
                    Scanner scanTemp = new Scanner(linha);
                    String v = scanTemp.next().toUpperCase();
                    grafo.conectarVertices(Character.toString(v.charAt(0)).toUpperCase(), Character.toString(v.charAt(1)).toUpperCase());
            }
            
            System.out.println("Grafo da Matriz de Adjacência"); 
            System.out.println(grafo);
            
            
            System.out.println("Insira o vertice de origem para busca em profundidade"); 
            verticeOrigemDaBusca = scanner.nextLine();  
            BuscarEmLargura busca = new BuscarEmLargura(grafo.getMatriz(), grafo);
            
            for (int i = 0; i < numeroDeVertices; i++) {
               if(verticeOrigemDaBusca.toUpperCase().equals(vertices[i])){
                   verificaVertice = true;
               }
            }
            if(verificaVertice == true){
                System.out.println("Resultado da busca em profundidade");
                busca.buscar(verticeOrigemDaBusca.toUpperCase());
            } else {
                System.out.println("Esse vertice não pertence a essa matriz");
            }
            
           
            
        } catch (IOException e) {
            throw new RuntimeException(e);
        }  
        /**
        Grafos grafo = new Grafos(8);
        
        try{
            grafo.AdicionarVertice("R");
            grafo.AdicionarVertice("S");
            grafo.AdicionarVertice("T");
            grafo.AdicionarVertice("U");
            grafo.AdicionarVertice("V");
            grafo.AdicionarVertice("W");
            grafo.AdicionarVertice("X");
            grafo.AdicionarVertice("Y");
            
            grafo.conectarVertices("R", "S");
            grafo.conectarVertices("R", "V");
            grafo.conectarVertices("S", "W");
            grafo.conectarVertices("W", "X");
            grafo.conectarVertices("W", "T");
            grafo.conectarVertices("T", "U");
            grafo.conectarVertices("T", "X");
            grafo.conectarVertices("X", "U");
            grafo.conectarVertices("X", "Y");
            grafo.conectarVertices("U", "Y");
            grafo.mostrarMatriz();
             BuscarEmLargura busca = new BuscarEmLargura(grafo.getMatriz(), grafo);
             busca.buscar("S");
        }catch (Exception e) {
			System.out.println(e.getMessage());
		}*/
    }
    
    
    
}
