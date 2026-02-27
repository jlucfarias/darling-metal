// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLCOMMANDQUEUEINTERNAL_H_
#define _METAL_MTLCOMMANDQUEUEINTERNAL_H_

#import <Metal/MTLCommandQueue.h>

#if DARLING_METAL_ENABLED
#include <indium/indium.hpp>
#endif

@interface MTLCommandQueueInternal : NSObject <MTLCommandQueue>

#if DARLING_METAL_ENABLED
- (instancetype)initWithQueue: (std::shared_ptr<Indium::CommandQueue>)queue
                       device: (id<MTLDevice>)device;
#endif

@end

#endif // _METAL_MTLCOMMANDQUEUEINTERNAL_H_
