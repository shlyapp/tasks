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
        System.out.println("Введите аргумент x: ");
        double x = scanner.nextDouble();

        System.out.println("Результат выполнения программы: ");
        System.out.println(system(a, b, x));
    }
}