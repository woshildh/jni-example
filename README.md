## JNI 开发教程

注: 本教程适用于 Windows 平台下的 gcc 开发

开发一个 windows 下的 JNI 流程，以 HelloWorld 为例:

1. 编写HelloWorld.java 文件
```
class HelloWorld {
    // native 关键字表示 hello_world 方法是原生的
    public static native void hello_world();
    static {
        System.loadLibrary("hello_world");
    }
    public static void main(String [] args) {
        hello_world();
    }
}
```

2. 导出头文件, 这里我的 java 版本是1.8.0_291, 不同的java 版本导出头文件的命令可能不同\
`javac -h ./ HelloWorld.java`

3. 编写源文件并且进行编译\
如果你的编译器是 MinGW, 注意由于 mingw 编译器导出函数时，函数名不会包含一个开头的"\_"，因此，需要你自己在头文件和实现文件中加上。再直观点说就是，第二步骤导出的头文件中函数名是 Java_HelloWorld_hello_1world, 而MinGW 生成的 .dll 中函数名中是没有"\_" 的，因此需要我们手动加上 "\_", 因此函数名就是 _Java_HelloWorld_hello_1world。我也尝试过在gcc 编译命令中添加 -fleading-underscore 但是没有用。\
```
// HelloWorld.c
#include "HelloWorld.h"
#include <stdio.h>
JNIEXPORT void JNICALL _Java_HelloWorld_hello_1world(JNIEnv *env, jclass cla) {
    printf("Hello world!\n");
}
```
编译的命令，注意将下面的包含路径改成你自己的，并且将 java/bin 加入到环境变量中:
`gcc .\hello_world.c -o hello_world.dll -ID:\environment\java\include -ID:\environment\java\include\win32 -shared`

如果你的编译器是 Visual Studio 那么不需要修改头文件中的导出函数名，直接写即可，确实方便，但是太重了，我没有用这个来编写工程。

4. 运行 Java
`Java HelloWorld`