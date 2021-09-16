class GlobalRefTest {
    static {
        System.loadLibrary("GlobalRefTest");
    }
    native void setInput(String input);
    native void releaseInput();
    native void printInput();
    public void javaSetInput() {
        String input = new String("Hello world!");
        setInput(input);
    }
    public static void main(String[] args) {
        GlobalRefTest grt = new GlobalRefTest();
        grt.javaSetInput();
        //grt.releaseInput();
        grt.printInput();
    }
}
