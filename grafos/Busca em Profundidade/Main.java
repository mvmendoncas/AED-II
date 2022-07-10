package listaAdjacente;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * Classe criada com o intuito de testar a busca em profundidade
 * Para inserir os arquivos no bufferReader, no linux, siga o seguinte exemplo:
 * -> listaAdjacente.testes\teste.txt
 * @author Maria Virgínia Mendonça dos Santos
 */
public class Main {
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        
        Scanner scanner = new Scanner(System.in);
        Character[] vertices;
        String[] arestas;                                           //Ex -> listaAdjacente.testes\teste.txt
                                                                     //Ou copie o diretório da pasta
        try(BufferedReader file = new BufferedReader(new FileReader("C:\\Users\\maria\\OneDrive\\Documentos\\NetBeansProjects\\Main\\src\\main\\java\\listaAdjacente\\testes\\teste.txt"))){
            String linha = file.readLine();
            Scanner scan = new Scanner(linha);
            
            int numeroDeVertices = scan.nextInt();
            int numeroDeArestas = scan.nextInt();

            vertices = new Character[numeroDeVertices];
            arestas = new String[numeroDeArestas];
            
            for (int i = 0; i < numeroDeVertices; i++) {
                linha = file.readLine();
                vertices[i] = linha.charAt(0);
            }
            for (int i = 0; i < numeroDeArestas; i++) {
                    linha = file.readLine();
                    Scanner scanTemp = new Scanner(linha);
                    arestas[i] = linha;
                }
            
            System.out.println("Grafo da Lista de Adjacência");
            ListaAdjacente l = new ListaAdjacente(vertices, arestas);
            System.out.println(l);
            
            System.out.println("");
            System.out.println("=============================================================");
            System.out.println("");
            
            System.out.println("Busca em Profundidade");
            BuscaEmProfundidade busca = new BuscaEmProfundidade(l);
            busca.buscar();
            System.out.println(" ");
            
            
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        
        
        /**
        Character v[]= new Character[3];
        v[0] = 'A';
        v[1] = 'D';
        v[2] = 'E';
        
        String a[] = new String[2];
        a[0] = "DE";
        a[1] = "AD";
        
        * ListaAdjacente l = new ListaAdjacente(v, a);
        System.out.println(l);
        
        BuscaEmProfundidade b = new BuscaEmProfundidade(l);
        b.buscar();
        * 
        * */
    }
    
    
    
}
