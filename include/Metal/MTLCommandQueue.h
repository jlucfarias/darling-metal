// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLCOMMANDQUEUE_H_
#define _METAL_MTLCOMMANDQUEUE_H_

#import <Foundation/Foundation.h>

#import <Metal/MTLDefines.h>

METAL_DECLARATIONS_BEGIN

@protocol MTLDevice;
@protocol MTLCommandBuffer;
@protocol MTLCommandQueue;

@protocol MTLCommandQueue <NSObject>

@property(readonly) id<MTLDevice> device;
@property(nullable, copy, atomic) NSString* label;

- (id<MTLCommandBuffer>)commandBuffer;

@end

METAL_DECLARATIONS_END

#endif // _METAL_MTLCOMMANDQUEUE_H_
