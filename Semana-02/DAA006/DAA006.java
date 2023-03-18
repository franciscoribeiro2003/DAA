import java.util.Scanner;

public class DAA006{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i=0;i<n;i++){
            int qx=in.nextInt(),qy=in.nextInt(),qi=in.nextInt();
            int cx=in.nextInt(),cy=in.nextInt(),ci=in.nextInt();
            System.out.println(intersection( qx, qy, qi,cx, cy, ci,0));
        }
    }

    public static double intersection(double qx, double qy, double qi, double cx, double cy, double ci,int profundidade){
        Box box=new Box(qx, qy, qi);
        Circle circle=new Circle(cx, cy, ci);
    
        if (circle.boxIsInside(box)) return circle.area();
            
        else if (box.circleIsInside(circle)) return box.area();

        else if (box.area()>=0.0001){
            return intersection(qx,      qy,      qi/2, cx, cy, ci, profundidade+1) +
                   intersection(qx+qi/2, qy,      qi/2, cx, cy, ci, profundidade+1) +
                   intersection(qx+qi/2, qy+qi/2, qi/2, cx, cy, ci, profundidade+1) +
                   intersection(qx,      qy+qi/2, qi/2, cx, cy, ci, profundidade+1);
        }
        


        return 0.0;
    }
}

class Box{
    double x;
    double y;
    double lado;

    public Box(double x, double y, double lado){
        this.x = x;
        this.y = y;
        this.lado = lado;
    }

    public boolean isInside(double x, double y){
        if(x >= this.x && x <= this.x + this.lado && y >= this.y && y <= this.y + this.lado){
            return true;
        }
        return false;
    }

    public double area(){
        return Math.pow(lado,2);
    }

    //ver se o quadrado está dentro do circulo
    public boolean circleIsInside(Circle circle){
        if (circle.isInside(x,y+lado) && circle.isInside(x-lado, y) && circle.isInside(x, y-lado) && circle.isInside(x+lado, y)) return true;
        return false;
    }


}

class Circle{
    double x;
    double y;
    double raio;

    public Circle(double x, double y, double raio){
        this.x = x;
        this.y = y;
        this.raio = raio;
    }

    public boolean isInside(double x, double y){
        if(Math.sqrt(Math.pow(x - this.x, 2) + Math.pow(y - this.y, 2)) <= this.raio){
            return true;
        }
        return false;
    }

    public double area(){
        return Math.PI*Math.pow(raio,2);
    }

    //ver se o circulo está dentro do quadrado
    public boolean boxIsInside(Box box){
        if (box.isInside(x,y+raio) && box.isInside(x-raio, y) && box.isInside(x, y-raio) && box.isInside(x+raio, y) && box.isInside(x, y)) return true;
        return false;
    }

}