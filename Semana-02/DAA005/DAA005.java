/* 
Npc way
public class DAA005 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); //numero de bakugans
        int[] powerScore = new int[n]; //Forca de cada bakugan
        for (int i = 0; i < n; i++) {
            powerScore[i] = in.nextInt();
        }
        int f=in.nextInt(); //numero de fotos
        int[] photoPower = new int[f]; //Forca de cada foto
        for (int i=0; i<f; i++){
            int a=in.nextInt(); //limite inferior
            int b=in.nextInt(); //limite superior
            a--;b--;
            for (int j=a; j<=b; j++){
                photoPower[i]+=powerScore[j];
            }
        }
        for (int i=0; i<f; i++){
            System.out.println(photoPower[i]);
        }
    }
}
 */

//Soma acumulada

public class DAA005{
    public static void main(String[] args) {
        FastScanner in = new FastScanner(System.in);
        int n = in.nextInt(); //numero de bakugans
        int[] powerScore = new int[n]; //Forca de cada bakugan
        for (int i = 0; i < n; i++) {
            powerScore[i] = in.nextInt();
            if (i!=0){
                powerScore[i]+=powerScore[i-1];
            }
        }

        int f=in.nextInt(); //numero de fotos
        int[] photoPower = new int[f]; //Forca de cada foto
        for (int i=0; i<f; i++){
            int a=in.nextInt(); //limite inferior
            int b=in.nextInt(); //limite superior
            a--;b--;
            if (a==0){
                photoPower[i]=powerScore[b];
            }else{
                photoPower[i]=powerScore[b]-powerScore[a-1];
            }
            FastPrint.out.println(photoPower[i]);
        }
        FastPrint.out.close();
    }
    
}