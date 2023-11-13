/**
 * Simple sorting algorithms and their performance
 * Reg:
 *
 */

public class Sort {

    // create an array of given size and populate it with random data
    static int[] create_rand_data(int size_of_array) {
        int[] data = new int[size_of_array];
        int i;
        for (i = 0; i < data.length; i++)
            data[i] = (int) (Math.random() * 100);
        return data;
    }

    // create an array of given size and populate it with worst data arrangement
    static int[] create_worst_data(int size_of_array) {
        int[] data = new int[size_of_array];
        int i;
        for (i = 0; i < data.length; i++)
            data[i] = data.length - i;
        return data;
    }

    // create an array of given size and populate it with best data arrangement
    static int[] create_best_data(int size_of_array) {
        int[] data = new int[size_of_array];
        int i;
        for (i = 0; i < data.length; i++)
            data[i] = i;
        return data;
    }

    // function to swap. Would be useful since all need this
    static void swap(int[] d, int i, int j) {
        int tmp = d[i];
        d[i] = d[j];
        d[j] = tmp;
    }

    // check if the soring worked on the array
    static boolean isSorted(int[] data) {
        int i;
        for (i = 1; i < data.length; i++)
            if (data[i] < data[i - 1])
                break;
        return (i == data.length);
    }

    // If you want just display the array as well :)
    static void display(int[] data) {
        System.out.println("=======");
        for (int i = 0; i < data.length; i++)
            System.out.print(data[i] + "  ");
        System.out.println("\n=======");
    }

    /**********************************************************
     * Implementation of sorting algorithms *
     *********************************************************/
    static void buble_sort(int[] data) {
        int len = data.length;
        while (!isSorted(data)) {
            for (int i = 0; i < len - 1; i++)
                if (data[i] > data[i + 1])
                    swap(data, i, i + 1);
            len--;
        }
    }

    static void selection_sort(int[] data) {
        // Implement
        int len = data.length;
        int curr_loc = 0;
        while (!isSorted(data)) {
            int min = curr_loc;
            for (int i = curr_loc + 1; i < len; i++) {
                if (data[i] < data[min])
                    min = i;
            }
            swap(data, curr_loc, min);
            curr_loc++;
        }
    }

    static void insertion_sort(int[] data) {
        // Implement
        int curr_pos = 0;
        while (!isSorted(data)) {
            for (int i = curr_pos + 1; i > 0 && data[i] < data[i - 1]; i--) {
                swap(data, i, i - 1);
            }
            curr_pos++;
        }
    }

    public static void main(String[] args) {
        // create arrays of different size populate with data
        // measure the time taken by different algorithms to
        // sort the array.
        // Think about effects of caches, other apps running etc.

        System.out.print(" \t\t Bubble \t\t Selection \t\t Insertion \n");

        for (int i = 10; i < 100000; i *= 5) {
            System.out.print(i + "\t ");

            int[] worst1 = Sort.create_worst_data(i);
            int[] best1 = Sort.create_best_data(i);
            int[] rand1 = Sort.create_rand_data(i);

            // System.out.println("Before sort");
            // display(worst1);
            // display(best1);
            // display(rand1);

            long time1 = System.nanoTime();
            Sort.buble_sort(worst1);
            long time2 = System.nanoTime();
            Sort.buble_sort(best1);
            long time3 = System.nanoTime();
            Sort.buble_sort(rand1);
            long time4 = System.nanoTime();

            // System.out.println("After sort");
            // display(worst1);
            // display(best1);
            // display(rand1);

            System.out.print(time2 - time1 + " ");
            System.out.print(time3 - time2 + " ");
            System.out.print(time4 - time3 + "\t ");

            worst1 = Sort.create_worst_data(i);
            best1 = Sort.create_best_data(i);
            rand1 = Sort.create_rand_data(i);

            // System.out.println("Before Sort");
            // display(worst1);
            // display(best1);
            // display(rand1);

            time1 = System.nanoTime();
            Sort.selection_sort(worst1);
            time2 = System.nanoTime();
            Sort.selection_sort(best1);
            time3 = System.nanoTime();
            Sort.selection_sort(rand1);
            time4 = System.nanoTime();

            // System.out.println("After sort");
            // display(worst1);
            // display(best1);
            // display(rand1);

            System.out.print(time2 - time1 + " ");
            System.out.print(time3 - time2 + " ");
            System.out.print(time4 - time3 + " \t");

            // System.out.println("Before Sort");
            // display(worst1);
            // display(best1);
            // display(rand1);

            time1 = System.nanoTime();
            Sort.insertion_sort(worst1);
            time2 = System.nanoTime();
            Sort.insertion_sort(best1);
            time3 = System.nanoTime();
            Sort.insertion_sort(rand1);
            time4 = System.nanoTime();

            // System.out.println("After sort");
            // display(worst1);
            // display(best1);
            // display(rand1);

            System.out.print(time2 - time1 + " ");
            System.out.print(time3 - time2 + " ");
            System.out.print(time4 - time3 + " ");

            System.out.print("\n");
        }
    }
}