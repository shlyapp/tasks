import java.util.Scanner;

public class Main {
    public static double system(double a, double b, double x) {
        if (x <= a) {
            return Math.log(x);
        }
        if (x >= b) {
            return Math.exp(x);
        }
        return 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите параметр a: ");
        double a = scanner.nextDouble();
        System.out.println("Введите параметр b: ");
        double b = scanner.nextDouble();
        System.out.println("Введите начальное число: ");
        double x1 = scanner.nextDouble();
        System.out.println("Введите конечное число: ");
        double x2 = scanner.nextDouble();
        System.out.println("Введите значение шага: ");
        double step = scanner.nextDouble();

        System.out.println("Таблица значений f = z(x)");
        System.out.println("x:\t\tf:");
        for(double i = x1; i < x2 + 1; i+=step)
        {
            System.out.println(i + "\t\t" + system(a, b, i));
        }

    }
}