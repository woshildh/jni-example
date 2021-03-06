/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <stdio.h>
/* Header for class GlobalRefTest */

#ifndef _Included_GlobalRefTest
#define _Included_GlobalRefTest
#ifdef __cplusplus
extern "C" {
#endif

jstring g_input = NULL;

/*
 * Class:     GlobalRefTest
 * Method:    setInput
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL _Java_GlobalRefTest_setInput(JNIEnv *env, jobject obj, jstring input) {
    // 通过 NewGlobalRef 阻止 JVM 直接将变量在退出作用域后进行垃圾回收
    g_input = (jstring)env->NewGlobalRef(input);
    // 直接将 java 的局部变量保存到c++全局变量中会导致错误
    // g_input = input;
}

/*
 * Class:     GlobalRefTest
 * Method:    printInput
 * Signature: ()V
 */
JNIEXPORT void JNICALL _Java_GlobalRefTest_printInput(JNIEnv *env, jobject obj) {
    const char *c_input = env->GetStringUTFChars(g_input, NULL);
    printf("In native: %s\n", c_input);
    env->ReleaseStringUTFChars(g_input, c_input);
}

/*
 * Class:     GlobalRefTest
 * Method:    releaseInput
 * Signature: ()V
 */
JNIEXPORT void JNICALL _Java_GlobalRefTest_releaseInput(JNIEnv *env, jobject obj) {
    if(g_input) {
        env->DeleteGlobalRef(g_input);
    }
}

#ifdef __cplusplus
}
#endif
#endif
