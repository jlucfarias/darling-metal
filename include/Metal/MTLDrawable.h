// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLDRAWABLE_H_
#define _METAL_MTLDRAWABLE_H_

#import <Foundation/Foundation.h>

#import <Metal/MTLDefines.h>

METAL_DECLARATIONS_BEGIN

@protocol MTLDrawable;

typedef void (^MTLDrawablePresentedHandler)(id<MTLDrawable>);

@protocol MTLDrawable <NSObject>

@property(nonatomic, readonly) NSUInteger drawableID;
@property(nonatomic, readonly) CFTimeInterval presentedTime;

- (void)present;
- (void)presentAfterMinimumDuration: (CFTimeInterval)duration;
- (void)presentAtTime: (CFTimeInterval)presentationTime;
- (void)addPresentedHandler: (MTLDrawablePresentedHandler)block;

@end

METAL_DECLARATIONS_END

#endif // _METAL_MTLDRAWABLE_H_
