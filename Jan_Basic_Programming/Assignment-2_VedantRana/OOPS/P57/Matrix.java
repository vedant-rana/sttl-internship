import java.util.Arrays;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class Matrix {

    private final int rows;
    private final int columns;
    private final double[][] data;

    public Matrix(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;
        this.data = new double[rows][columns];
    }

    public Matrix(double[][] data) {
        this.rows = data.length;
        this.columns = data[0].length;
        this.data = new double[rows][columns];
        for (int i = 0; i < rows; i++) {
            System.arraycopy(data[i], 0, this.data[i], 0, columns);
        }
    }

    public int getRows() {
        return rows;
    }

    public int getColumns() {
        return columns;
    }

    public double get(int row, int col) {
        return data[row][col];
    }

    public void set(int row, int col, double value) {
        data[row][col] = value;
    }

    public Matrix multiply(Matrix other) {
        if (this.columns != other.rows) {
            throw new IllegalArgumentException("Incompatible matrix dimensions for multiplication");
        }

        Matrix result = new Matrix(this.rows, other.columns);
        ForkJoinPool pool = new ForkJoinPool();
        MultiplyTask multiplyTask = new MultiplyTask(this, other, result, 0, this.rows);
        pool.invoke(multiplyTask);

        return result;
    }

    private static class MultiplyTask extends RecursiveAction {
        private final Matrix a;
        private final Matrix b;
        private final Matrix result;
        private final int startRow;
        private final int endRow;

        MultiplyTask(Matrix a, Matrix b, Matrix result, int startRow, int endRow) {
            this.a = a;
            this.b = b;
            this.result = result;
            this.startRow = startRow;
            this.endRow = endRow;
        }

        @Override
        protected void compute() {
            if (endRow - startRow <= 1) {
                multiplySequential();
            } else {
                int mid = startRow + (endRow - startRow) / 2;
                MultiplyTask leftTask = new MultiplyTask(a, b, result, startRow, mid);
                MultiplyTask rightTask = new MultiplyTask(a, b, result, mid, endRow);
                invokeAll(leftTask, rightTask);
            }
        }

        private void multiplySequential() {
            for (int i = startRow; i < endRow; i++) {
                for (int j = 0; j < b.getColumns(); j++) {
                    double sum = 0.0;
                    for (int k = 0; k < a.getColumns(); k++) {
                        sum += a.get(i, k) * b.get(k, j);
                    }
                    result.set(i, j, sum);
                }
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (double[] row : data) {
            sb.append(Arrays.toString(row)).append("\n");
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Matrix A = new Matrix(new double[][]{{1, 2}, {3, 4}});
        Matrix B = new Matrix(new double[][]{{5, 6}, {7, 8}});

        System.out.println("Matrix A:\n" + A);
        System.out.println("Matrix B:\n" + B);

        Matrix result = A.multiply(B);
        System.out.println("Result of multiplication:\n" + result);
    }
}
