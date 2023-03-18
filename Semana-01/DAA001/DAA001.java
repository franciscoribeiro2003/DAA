import java.util.Scanner;

class DAA001{
    public static void main(String[] args){
        int count = 0;
        Scanner stdin = new Scanner(System.in);
        int n = stdin.nextInt();
        for (int i = 0; i < n; i++){
            int a = stdin.nextInt();
            if (a==42) count++;
        }
        System.out.println(count);
    }
}
