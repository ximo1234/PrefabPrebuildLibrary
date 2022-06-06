#include <jni.h>

#include <externalLibrary.h>
#include <internalLibrary.h>

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_mylib_myJavaClass_myPublicJavaMethod(JNIEnv *env, jclass clazz) {
    return  TheAnswerToLifeTheUniverseAndEverything() * luckyNumber();
}
