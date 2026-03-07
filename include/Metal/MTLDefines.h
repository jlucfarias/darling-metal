// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLDEFINES_H_
#define _METAL_MTLDEFINES_H_

#include <sys/cdefs.h>

#define METAL_DECLARATIONS_BEGIN __BEGIN_DECLS
#define METAL_DECLARATIONS_END __END_DECLS

#define MTL_EXPORT __attribute__((visibility("default")))

#if __cplusplus
	#define MTL_EXTERN extern "C"
#else
	#define MTL_EXTERN extern
#endif

#endif // _METAL_MTLDEFINES_H_
