import java.util.Random;

public class Bogosort {

    public static void main(String[] args) {
        int[] array = {3, 2, 5, 1, 4};
        System.out.println("Original array:");
        printArray(array);
        
        bogosort(array);
        
        System.out.println("Sorted array:");
        printArray(array);
    }

    public static void bogosort(int[] array) {
        while (!isSorted(array)) {
            shuffle(array);
        }
    }

    public static boolean isSorted(int[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i - 1] > array[i]) {
                return false;
            }
        }
        return true;
    }

    public static void shuffle(int[] array) {
        Random random = new Random();
        for (int i = 0; i < array.length; i++) {
            int randomIndex = random.nextInt(array.length);
            // Swap elements
            int temp = array[i];
            array[i] = array[randomIndex];
            array[randomIndex] = temp;
        }
    }

    public static void printArray(int[] array) {
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
