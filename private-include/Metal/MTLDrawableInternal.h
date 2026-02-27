// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLDRAWABLEINTERNAL_H_
#define _METAL_MTLDRAWABLEINTERNAL_H_

#import <Metal/MTLDrawable.h>

#if DARLING_METAL_ENABLED
#include <indium/indium.hpp>
#endif

@protocol MTLDrawableInternal <MTLDrawable>

#if DARLING_METAL_ENABLED
@property(readonly) std::shared_ptr<Indium::Drawable> drawable;
#endif

@end

@interface MTLDrawableInternal : NSObject <MTLDrawableInternal>

#if DARLING_METAL_ENABLED
- (instancetype)initWithDrawable: (std::shared_ptr<Indium::Drawable>)drawable;
#endif

@end

#endif // _METAL_MTLDRAWABLEINTERNAL_H_
