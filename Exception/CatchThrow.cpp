/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class CatchThrow */

#ifndef _Included_CatchThrow
#define _Included_CatchThrow
#ifdef __cplusplus
extern "C" {
#endif

void JNU_ThrowByName(JNIEnv *env, const char *name, const char *msg) {
    jclass cls = env->FindClass(name);
    if(cls) {
        // 从 c++ 中抛出 Java异常
        env->ThrowNew(cls, msg);
    }
    env->DeleteLocalRef(cls);
}

/*
 * Class:     CatchThrow
 * Method:    doit
 * Signature: ()V
 */
JNIEXPORT void JNICALL _Java_CatchThrow_doit(JNIEnv *env, jobject obj) {
    jthrowable exc;
    jclass cls = env->GetObjectClass(obj);
    jmethodID mid = env->GetMethodID(cls, "callback", "()V");
    if(!mid) {
        return;  
    }
    env->CallVoidMethod(obj, mid);
    // 检查 jni 是否报了异常
    exc = env->ExceptionOccurred();
    if(exc) {
        jclass newExcCls;
        // 对原来的 java 异常进行描述和打印
        env->ExceptionDescribe();
        // 清除原先 JVM 中存在的Java 异常
        env->ExceptionClear();
        // 抛出异常
        JNU_ThrowByName(env, "java/lang/IllegalArgumentException", "Throw from C code");
    }
}

#ifdef __cplusplus
}
#endif
#endif