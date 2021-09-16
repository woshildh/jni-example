class IntArray {
    public native static int sumArray(int[] arr);
    static {
        System.loadLibrary("IntArray");
    }
    public static void main(String[] args) {
        int[] arr = new int[10];
        for(int i = 0; i < 10; ++i) {
            arr[i] = i + 1;
        }
        int sum = sumArray(arr);
        System.out.println("sum = " + sum);
    }
}