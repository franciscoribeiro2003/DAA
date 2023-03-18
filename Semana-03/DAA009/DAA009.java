import java.util.*;


public class DAA009{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s=in.nextLine(); // le o input
        counter(s);
    }

    public static void counter(String s){
        char[] ord = s.toCharArray(); // transforma o input numa array de chars

        // cria uma map para guardar o numero de ocorrencias de cada caracter
        Map<Character, Integer> map = new TreeMap<Character, Integer>();
        Arrays.sort(ord); // ordena o input mas e desnecessario

        //Coloca o numero de ocorrencias de cada caracter numa map
        for (int i = 0; i < ord.length; i++) {
            if(map.containsKey(ord[i])){
                map.put(ord[i], map.get(ord[i])+1);
            }else{
                map.put(ord[i], 1);
            }
        }

        // cria uma lista para ordenar a map
        List<Map.Entry<Character, Integer>> list = new ArrayList<Map.Entry<Character, Integer>>(map.entrySet());

        // comparador personalizado para ordenar a map
        Collections.sort(list, new Comparator<Map.Entry<Character, Integer>>() {
            public int compare(Map.Entry<Character, Integer> o1, Map.Entry<Character, Integer> o2) {

                // compara os valores
                int cmp = o2.getValue().compareTo(o1.getValue());
                if (cmp != 0) { // como valores sao diferentes, ordena por ordem decrescente
                    return cmp; 
                } else { // como valores sao iguais, ordena por ordem crescente de posicao
                    int pos1 = s.indexOf(o1.getKey());
                    int pos2 = s.indexOf(o2.getKey());
                    return Integer.compare(pos1, pos2); 
                }
            }
        });

        // print o mapa ordenado
        for (Map.Entry<Character, Integer> entry : list) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
        
    }
}


