import java.util.Scanner;

public class DAA002 {
    public static void main(String args[]){
        Scanner stdin=new Scanner(System.in);
        int n=stdin.nextInt();
        while (n>0){
        int a=stdin.nextInt();
        int b=stdin.nextInt();
        int start = b;
        int end = 9*a;
        while (start <= end) {
        int mid = (start + end) / 2;
        if (soma(mid) == b) {
        System.out.println(mid);
        break;
        } else if (soma(mid) < b) {
        start = mid + 1;
        } else {
        end = mid - 1;
        }
        }
        n--;
        }
        }

    public static int soma(int n){
        int soma=0;
        while (n>0){
            soma+=n%10;
            n/=10;
        }
        return soma;
    }
}
