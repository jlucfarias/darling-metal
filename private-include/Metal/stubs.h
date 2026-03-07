// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_STUBS_H_
#define _METAL_STUBS_H_

// this is mainly used for the 32-bit build.
// in the 32-bit build, Metal builds and links, but any attempt to use it fails.
// this is the correct behavior according to the official framework.
#define MTL_UNSUPPORTED_CLASS \
	- (NSMethodSignature*)methodSignatureForSelector: (SEL)selector \
	{ \
		return [NSMethodSignature signatureWithObjCTypes: "v@:"]; \
	} \
	- (void)forwardInvocation: (NSInvocation*)invocation \
	{ \
		NSLog(@"Method invocation in unsupported class %@ in %@", NSStringFromSelector(invocation.selector), self.class); \
		abort(); \
	}

#if !__OBJC2__ || !DARLING_METAL_ENABLED
	// shut Clang up about unimplemented methods and properties
	#pragma clang diagnostic ignored "-Wobjc-property-implementation"
	#pragma clang diagnostic ignored "-Wprotocol"
	#pragma clang diagnostic ignored "-Wincomplete-implementation"
	#pragma clang diagnostic ignored "-Wobjc-protocol-property-synthesis"

	#undef DARLING_METAL_ENABLED
#endif

#endif // _METAL_STUBS_H_
