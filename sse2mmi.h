/*
 ============================================================================
 Name        : sse2mmi.h
 Author      : Heiher <r@hev.cc>
 Version     : 0.0.1
 Copyright   : Copyright (c) 2015 everyone.
 Description : The helpers for x86 SSE to Loongson MMI.
 ============================================================================
 */

#ifndef __SSE2MMI_H__
#define __SSE2MMI_H__

#define __mm_packxxxx(_f, _D, _d, _s, _t)                   \
	#_f" %["#_t"], %["#_d"h], %["#_s"h] \n\t"           \
	#_f" %["#_D"l], %["#_d"l], %["#_s"l] \n\t"          \
	"punpckhwd %["#_D"h], %["#_D"l], %["#_t"] \n\t"     \
	"punpcklwd %["#_D"l], %["#_D"l], %["#_t"] \n\t"

#define _mm_or(_D, _d, _s)                                  \
	"or %["#_D"h], %["#_D"h], %["#_D"h] \n\t"           \
	"or %["#_D"l], %["#_D"l], %["#_D"l] \n\t"

#define _mm_xor(_D, _d, _s)                                 \
	"xor %["#_D"h], %["#_D"h], %["#_D"h] \n\t"          \
	"xor %["#_D"l], %["#_D"l], %["#_D"l] \n\t"

#define _mm_and(_D, _d, _s)                                 \
	"and %["#_D"h], %["#_d"h], %["#_s"h] \n\t"          \
	"and %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: pshuflw */
#define _mm_pshuflh(_D, _d, _s)                             \
	"mov.d %["#_D"h], %["#_d"h] \n\t"                   \
	"pshufh %["#_D"l], %["#_d"l], %["#_s"] \n\t"

/* SSE: psllw */
#define _mm_psllh(_D, _d, _s)                               \
	"psllh %["#_D"h], %["#_d"h], %["#_s"] \n\t"         \
	"psllh %["#_D"l], %["#_d"l], %["#_s"] \n\t"

/* SSE: pslld */
#define _mm_psllw(_D, _d, _s)                               \
	"psllw %["#_D"h], %["#_d"h], %["#_s"] \n\t"         \
	"psllw %["#_D"l], %["#_d"l], %["#_s"] \n\t"

/* SSE: psrld */
#define _mm_psrlw(_D, _d, _s)                               \
	"psrlw %["#_D"h], %["#_d"h], %["#_s"] \n\t"         \
	"psrlw %["#_D"l], %["#_d"l], %["#_s"] \n\t"

/* SSE: psrad */
#define _mm_psraw(_D, _d, _s)                               \
	"psraw %["#_D"h], %["#_d"h], %["#_s"] \n\t"         \
	"psraw %["#_D"l], %["#_d"l], %["#_s"] \n\t"

/* SSE: paddd */
#define _mm_paddw(_D, _d, _s)                               \
	"paddw %["#_D"h], %["#_d"h], %["#_s"h] \n\t"        \
	"paddw %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: pmaxub */
#define _mm_pmaxub(_D, _d, _s)                              \
	"pmaxub %["#_D"h], %["#_d"h], %["#_s"h] \n\t"       \
	"pmaxub %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: pmullw */
#define _mm_pmullh(_D, _d, _s)                              \
	"pmullh %["#_D"h], %["#_d"h], %["#_s"h] \n\t"       \
	"pmullh %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: pmulhw */
#define _mm_pmulhh(_D, _d, _s)                              \
	"pmulhh %["#_D"h], %["#_d"h], %["#_s"h] \n\t"       \
	"pmulhh %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: packsswb */
#define _mm_packsshb(_D, _d, _s, _t)			    \
	__mm_packxxxx(packsshb, _D, _d, _s, _t)

/* SSE: packssdw */
#define _mm_packsswh(_D, _d, _s, _t)			    \
	__mm_packxxxx(packsswh, _D, _d, _s, _t)

/* SSE: packuswb */
#define _mm_packushb(_D, _d, _s, _t)			    \
	__mm_packxxxx(packushb, _D, _d, _s, _t)

/* SSE: punpcklbw */
#define _mm_punpcklbh(_D, _d, _s)                           \
	"punpckhbh %["#_D"h], %["#_d"l], %["#_s"l] \n\t"    \
	"punpcklbh %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: punpcklwd */
#define _mm_punpcklhw(_D, _d, _s)                           \
	"punpckhhw %["#_D"h], %["#_d"l], %["#_s"l] \n\t"    \
	"punpcklhw %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: punpckldq */
#define _mm_punpcklwd(_D, _d, _s)                           \
	"punpckhwd %["#_D"h], %["#_d"l], %["#_s"l] \n\t"    \
	"punpcklwd %["#_D"l], %["#_d"l], %["#_s"l] \n\t"

/* SSE: punpcklqdq */
#define _mm_punpckldq(_D, _d, _s)                           \
	"mov.d %["#_D"h], %["#_s"l] \n\t"                   \
	"mov.d %["#_D"l], %["#_d"l] \n\t"

/* SSE: punpckhbw */
#define _mm_punpckhbh(_D, _d, _s)                           \
	"punpcklbh %["#_D"l], %["#_d"h], %["#_s"h] \n\t"    \
	"punpckhbh %["#_D"h], %["#_d"h], %["#_s"h] \n\t"

/* SSE: punpckhwd */
#define _mm_punpckhhw(_D, _d, _s)                           \
	"punpcklhw %["#_D"l], %["#_d"h], %["#_s"h] \n\t"    \
	"punpckhhw %["#_D"h], %["#_d"h], %["#_s"h] \n\t"

/* SSE: punpckhdq */
#define _mm_punpckhwd(_D, _d, _s)                           \
	"punpcklwd %["#_D"l], %["#_d"h], %["#_s"h] \n\t"    \
	"punpckhwd %["#_D"h], %["#_d"h], %["#_s"h] \n\t"

/* SSE: punpckhqdq */
#define _mm_punpckhdq(_D, _d, _s)                           \
	"mov.d %["#_D"l], %["#_d"h] \n\t"                   \
	"mov.d %["#_D"h], %["#_s"h] \n\t"

#endif /* __SSE2MMI_H__ */

