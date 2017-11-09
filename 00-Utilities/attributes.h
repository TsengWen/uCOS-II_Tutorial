#ifndef __ATTRIBUTES_H
#define __ATTRIBUTES_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Check for GNUC */
#if defined (__GNUC__)
	#ifndef __weak		
		#define __weak   	__attribute__((weak))
	#endif	/* Weak attribute */
	#ifndef __packed	
		#define __packed 	__attribute__((__packed__))
	#endif	/* Packed attribute */
#endif

#ifdef __cplusplus
}
#endif

#endif /* __ATTRIBUTES_H */

