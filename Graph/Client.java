import java.util.Scanner;

/**
 * Created by LiuMingyu on 11/3/17.
 */
public class Client {

    public static void main(String[] args) {
        System.out.print("Enter something, would you?: ");
        Scanner userInput = new Scanner(System.in);
        System.out.println("You have entered " + userInput.nextLine());
    }
}
