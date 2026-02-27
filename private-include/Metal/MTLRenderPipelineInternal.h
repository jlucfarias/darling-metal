// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLRENDERPIPELINEINTERNAL_H_
#define _METAL_MTLRENDERPIPELINEINTERNAL_H_

#import <Metal/MTLRenderPipeline.h>

#if DARLING_METAL_ENABLED
#include <indium/indium.hpp>
#endif

METAL_DECLARATIONS_BEGIN

@protocol MTLDevice;

#if DARLING_METAL_ENABLED
@interface MTLRenderPipelineDescriptor (Internal)

- (Indium::RenderPipelineDescriptor)asIndiumDescriptor;

@end

@interface MTLRenderPipelineColorAttachmentDescriptorArray (Internal) <NSCopying>

- (std::unordered_map<size_t, Indium::RenderPipelineColorAttachmentDescriptor>)asIndiumDescriptors;

- (std::vector<Indium::RenderPipelineColorAttachmentDescriptor>)asContiguousIndiumDescriptors;

@end

@interface MTLRenderPipelineColorAttachmentDescriptor (Internal)

- (Indium::RenderPipelineColorAttachmentDescriptor)asIndiumDescriptor;

@end
#endif

@interface MTLRenderPipelineStateInternal : NSObject <MTLRenderPipelineState>

#if DARLING_METAL_ENABLED
@property(readonly) std::shared_ptr<Indium::RenderPipelineState> state;

- (instancetype)initWithState: (std::shared_ptr<Indium::RenderPipelineState>)state
                       device: (id<MTLDevice>)device
                        label: (NSString*)label;
#endif

@end

METAL_DECLARATIONS_END

#endif // _METAL_MTLRENDERPIPELINEINTERNAL_H_
