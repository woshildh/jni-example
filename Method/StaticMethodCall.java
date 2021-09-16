class StaticMethodCall {
    static {
        System.loadLibrary("StaticMethodCall");
    }
    private native void nativeMethod();
    private static void callback() {
        System.out.println("In java");
    }
    public static void main(String[] args) {
        StaticMethodCall obj = new StaticMethodCall();
        obj.nativeMethod();
    }
}