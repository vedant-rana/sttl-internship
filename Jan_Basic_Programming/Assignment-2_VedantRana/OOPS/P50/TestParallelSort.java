package P50;

import java.util.Arrays;
import java.util.concurrent.RecursiveTask;
import java.util.concurrent.ForkJoinPool;

// ParallelMergeSort class implementing ForkJoinTask
class ParallelMergeSort extends RecursiveTask<int[]> {
    private final int[] array;
    private final int low;
    private final int high;

    public ParallelMergeSort(int[] array, int low, int high) {
        this.array = array;
        this.low = low;
        this.high = high;
    }

    @Override
    protected int[] compute() {
        if (low < high) {
            int mid = (low + high) / 2;

            ParallelMergeSort leftTask = new ParallelMergeSort(array, low, mid);
            ParallelMergeSort rightTask = new ParallelMergeSort(array, mid + 1, high);

            invokeAll(leftTask, rightTask);

            merge(array, low, mid, high);
        }

        return array;
    }

    private void merge(int[] array, int low, int mid, int high) {
        int[] temp = Arrays.copyOfRange(array, low, high + 1);

        int i = low;
        int j = mid + 1;
        int k = low;

        while (i <= mid && j <= high) {
            if (temp[i - low] <= temp[j - low]) {
                array[k++] = temp[i++ - low];
            } else {
                array[k++] = temp[j++ - low];
            }
        }

        while (i <= mid) {
            array[k++] = temp[i++ - low];
        }
    }
}


public class TestParallelSort {
    public static void main(String[] args) {
        int[] array = {5, 3, 8, 4, 2, 7, 1, 6};

        ForkJoinPool forkJoinPool = new ForkJoinPool();
        int[] sortedArray = forkJoinPool.invoke(new ParallelMergeSort(array, 0, array.length - 1));

        System.out.println("Sorted Array: " + Arrays.toString(sortedArray));
    }
}
