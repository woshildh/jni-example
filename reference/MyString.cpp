#include <jni.h>

#ifdef _cplusplus
extern "C" {
#endif

jstring MyNewString(JNIEnv *env, jchar *chars, jint len) {
    static jclass stringClass;
    jmethodID cid;
    jcharArray elemArr;
    jstring result;
    if(!stringClass) {
        stringClass = env->FindClass("java/lang/String");
        if(!stringClass) {
            return 0;
        }
    }
    cid = env->GetMethodID(stringClass, "<init>", "([C)V");
    if(!cid) {
        return 0;
    }
    elemArr = env->NewCharArray(len);  // 这里新建了局部变量，因此要进行释放
    if(elemArr) {
        return 0;
    }
    env->SetCharArrayRegion(elemArr, 0, len, chars);
    // 建立一个字符串
    result = (jstring)env->NewObject(stringClass, cid, elemArr);
    // 释放局部的引用
    env->DeleteLocalRef(elemArr);     // 之前新建了局部变量，因此要进行释放
    return result;
}

#ifdef _cplusplus
}
#endif