// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLPIPELINEINTERNAL_H_
#define _METAL_MTLPIPELINEINTERNAL_H_

#import <Metal/MTLPipeline.h>

#if DARLING_METAL_ENABLED
#include <indium/indium.hpp>
#endif

@interface MTLPipelineBufferDescriptor (Internal)

#if DARLING_METAL_ENABLED
- (Indium::PipelineBufferDescriptor)asIndiumDescriptor;
#endif

@end

@interface MTLPipelineBufferDescriptorArray (Internal) <NSCopying>

#if DARLING_METAL_ENABLED
- (std::unordered_map<size_t, Indium::PipelineBufferDescriptor>)asIndiumDescriptors;
#endif

@end

#endif // _METAL_MTLPIPELINEINTERNAL_H_
