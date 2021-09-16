class AsyncCallback {
    static {
        System.loadLibrary("AsyncCallback");
    }
    public static native void InitNativeThread();
    public static void callback(String message) {
        System.out.println(message);
    }
    public static void main(String[] args) {
        AsyncCallback.InitNativeThread();
        while(true) {
            ;
        }
    }
}
