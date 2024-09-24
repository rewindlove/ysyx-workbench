#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
	if(s == NULL){
		assert(0);
	}
	size_t len = 0;
	while(*s++ != '\0')
		len ++;
	return len;
}

size_t strnlen(const char *s, size_t count){
	const char *sc;

	for(sc = s; (sc - s) < count && *sc != '\0'; ++sc)
			;
		return (sc - s);
	}

char *strcpy(char *dst, const char *src) {
	if(src == NULL || dst == NULL)
		return dst;
	char *p = dst;
	while(*src != '\0'){
		*dst = *src;
		dst++;
		src++;
		}
		return p;
}

char *strncpy(char *dst, const char *src, size_t n) {
	if(dst == NULL || src == NULL)
		return dst;
	char *p = dst;
	while(*src != '\0' && n != 0){
		*dst++ = *src++;
		--n;
		}
	while(n != 0){	//dst剩余位置写入空字符，直到n=0
		*dst++ = '\0';
		--n;
		}
	return p;
}

char *strcat(char *dst, const char *src) {
	if(dst == NULL || src == NULL)
		return dst;
	char *p = dst;
	while(*p != '\0')
		p++;
	while(*src != '\0'){
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	if(s1 == NULL || s2 == NULL)
		return 0;
	while((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2)){
		s1++;
		s2++;
		}
		return *s1 == *s2 ? 0 : (unsigned char)*s1 < (unsigned char)*s2 ? -1 : 1;
}

int strncmp(const char *s1, const char *s2, size_t n) {
	if(s1 == NULL || s2 == NULL)
		assert(0);
	while(n != 0 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2){
		--n;
		++s1;
		++s2;
		}
		return *s1 == *s2 || n == 0 ? 0 : (unsigned char)*s1 < (unsigned char)*s2 ? -1 : 1;
	}

void *memset(void *s, int c, size_t n) {
	if(s == NULL || n < 0)
		assert(0);
	unsigned char *p = s;
	while(n != 0){
		--n;
		*p = c;
		++p;
		}
		return s;
}

void *memmove(void *dst, const void *src, size_t n) {
	if(dst == NULL || src == NULL || n == 0 || dst == src)
		return dst;
	void* ret = dst;
	if(dst < src){
		while(n--){	//dst在src左边，从前向后拷
			*(char*)dst = *(char*)src;
			(char*)dst++;
			(char*)src++;
			}
		}
	else{
		while(n--){
			*((char*)dst + n) = *((char*)src + n);
			}
		}
		return ret;
}

void *memcpy(void *out, const void *in, size_t n) {
	if(out == NULL || in == NULL || n < 0)
		return NULL;
	void * dst = out;
	if(out <= in || (char *)out >= (char *)in + n){
		while(n--){
			*(char *)out = *(char *)in;
			out = (char *)out + 1;
			in = (char *)in + 1;
			}
		}
		else{
			in = (char *)in + n -1;
			out = (char *)out + n - 1;
			while(n--){
				*(char *)out = *(char *)in;
				out = (char *)out - 1;
				in = (char *)in - 1;

				}
			}
	return dst;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	if(s1 == NULL || s2 == NULL)
		return 0;
	const unsigned char *src1 = s1;
	const unsigned char *src2 = s2;
	while(n != 0 && *src1 != '\0' && *src2 != '\0' && *src1 == *src2){
		--n;
		++src1;
		++src2;
		}
	return *src1 == *src2 || n == 0 ? 0 : (unsigned char)*src1 < (unsigned char)*src2 ? -1 : 1;
}

#endif
