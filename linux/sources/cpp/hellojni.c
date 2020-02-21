#include <dlfcn.h>
#include <hybris/common/binding.h>
#include <jni.h>

/*
#ifdef __cplusplus
extern "C" {
#endif
    JNIEXPORT jstring JNICALL Java_com_kevinread_hellojni_HelloJni_stringFromJNI(JNIEnv*, jobject);
#ifdef __cplusplus
}
#endif */

HYBRIS_LIBRARY_INITIALIZE(hellojni, "libhello-jni.so")

/*
 * Class:     com_meituan_android_common_candy_CandyJni
 * Method:    CandyClientKey
 * Signature: (Ljava/lang/Object;[BLjava/lang/String;)Ljava/lang/String;
 */

JNIEXPORT jstring JNICALL Java_com_kevinread_hellojni_HelloJni_stringFromJNI(JNIEnv* env, jobject obj) {
        static jstring (*f)(JNIEnv*, jobject) FP_ATTRIB = NULL; \
        HYBRIS_DLSYSM(hellojni, &f, "Java_com_kevinread_hellojni_HelloJni_stringFromJNI"); \
        return f(env, obj); \
//   static void (*f)(JNIEnv*, jobject) = NULL;
//   HYBRIS_DLSYSM(libjpeg, &f, "Java_com_kevinread_hellojni_HelloJni_stringFromJNI");
//  return f(env, obj);
}

// HYBRIS_IMPLEMENT_FUNCTION2 (hellojni, jstring, Java_com_kevinread_hellojni_HelloJni_stringFromJNI, JNIEnv *, jobject);
 