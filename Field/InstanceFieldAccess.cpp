/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class InstanceFieldAccess */

#ifndef _Included_InstanceFieldAccess
#define _Included_InstanceFieldAccess
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     InstanceFieldAccess
 * Method:    accessField
 * Signature: ()V
 */
JNIEXPORT void JNICALL _Java_InstanceFieldAccess_accessField(JNIEnv *env, jobject obj) {
    jfieldID fid;
    jstring jstr;
    const char *str;
    // 获取一个对象的类的引用
    jclass cls = env->GetObjectClass(obj);
    // 获取fieldID
    fid = env->GetFieldID(cls, "s", "Ljava/lang/String;");
    // 获取对象的成员
    jstr = (jstring)env->GetObjectField(obj, fid);
    // 获取原先的字符串
    str = env->GetStringUTFChars(jstr, NULL);
    if(str == NULL) {
        return;
    }
    printf(" c.s = \"%s\"\n", str);
    env->ReleaseStringUTFChars(jstr, str);
    // 创建一个新的字符串
    jstr = env->NewStringUTF("new string in c.");
    if(!jstr) {
        return;
    }
    env->SetObjectField(obj, fid, jstr);
}

#ifdef __cplusplus
}
#endif
#endif
