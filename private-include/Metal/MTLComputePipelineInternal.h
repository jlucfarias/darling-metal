// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLCOMPUTEPIPELINEINTERNAL_H_
#define _METAL_MTLCOMPUTEPIPELINEINTERNAL_H_

#import <Metal/MTLComputePipeline.h>

#if DARLING_METAL_ENABLED
#include <indium/indium.hpp>
#endif

@interface MTLComputePipelineDescriptor (Internal)

#if DARLING_METAL_ENABLED
- (Indium::ComputePipelineDescriptor)asIndiumDescriptor;
#endif

@end

@interface MTLComputePipelineStateInternal : NSObject <MTLComputePipelineState>

#if DARLING_METAL_ENABLED
@property(readonly) std::shared_ptr<Indium::ComputePipelineState> state;

- (instancetype)initWithState: (std::shared_ptr<Indium::ComputePipelineState>)state
                       device: (id<MTLDevice>)device
                        label: (NSString*)label;
#endif

@end

#endif // _METAL_MTLCOMPUTEPIPELINEINTERNAL_H_
