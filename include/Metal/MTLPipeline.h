// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLPIPELINE_H_
#define _METAL_MTLPIPELINE_H_

#import <Foundation/Foundation.h>

#import <Metal/MTLDefines.h>

METAL_DECLARATIONS_BEGIN

@class MTLPipelineBufferDescriptor;
@class MTLPipelineBufferDescriptorArray;

typedef NS_ENUM(NSUInteger, MTLMutability) {
	MTLMutabilityDefault = 0,
	MTLMutabilityMutable = 1,
	MTLMutabilityImmutable = 2,
};

MTL_EXPORT
@interface MTLPipelineBufferDescriptor : NSObject <NSCopying>

@property(readwrite, nonatomic, assign) MTLMutability mutability;

@end

MTL_EXPORT
@interface MTLPipelineBufferDescriptorArray : NSObject

- (MTLPipelineBufferDescriptor*)objectAtIndexedSubscript: (NSUInteger)index;

-    (void)setObject: (MTLPipelineBufferDescriptor*)buffer
  atIndexedSubscript: (NSUInteger)index;

@end

METAL_DECLARATIONS_END

#endif // _METAL_MTLPIPELINE_H_
