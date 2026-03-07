// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLBUFFER_H_
#define _METAL_MTLBUFFER_H_

#import <Foundation/Foundation.h>

#import <Metal/MTLResource.h>
#import <Metal/MTLDefines.h>

METAL_DECLARATIONS_BEGIN

@protocol MTLBuffer <MTLResource>

@property(readonly) NSUInteger length;
@property(readonly) uint64_t gpuAddress;

- (void*)contents;

- (void)didModifyRange: (NSRange)range;

@end

METAL_DECLARATIONS_END

#endif // _METAL_MTLBUFFER_H_
