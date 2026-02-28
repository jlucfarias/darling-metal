/*
SPDX-FileCopyrightText: 2022 Apple Inc.
SPDX-License-Identifier: MIT

Abstract:
Header for a platform independent renderer class, which performs Metal setup and per frame rendering.
*/
// this file has been modified to use #import instead of @import

#import <MetalKit/MetalKit.h>

@interface AAPLRenderer : NSObject<MTKViewDelegate>

- (nonnull instancetype)initWithMetalKitView:(nonnull MTKView *)mtkView;

@end
