class HelloWorld {
    public static native void hello_world();
    static {
        System.loadLibrary("hello_world");
    }
    public static void main(String [] args) {
        hello_world();
    }
}
