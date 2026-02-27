// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METALKIT_MTKVIEW_H_
#define _METALKIT_MTKVIEW_H_

#import <AppKit/AppKit.h>
#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>

@class MTKView;

@protocol MTKViewDelegate

- (void)         mtkView: (MTKView*)view
  drawableSizeWillChange: (CGSize)size;

- (void)drawInMTKView: (MTKView*)view;

@end

MTL_EXPORT
@interface MTKView : NSView <NSCoding, CALayerDelegate>

#if __OBJC2__
@property(nonatomic, weak, nullable) id<MTKViewDelegate> delegate;
#else
@property(nonatomic, assign, nullable) id<MTKViewDelegate> delegate;
#endif

@property(nonatomic, retain, nullable) id<MTLDevice> device;
@property(readonly) id<MTLDevice> preferredDevice;
@property(nonatomic) MTLPixelFormat colorPixelFormat;
@property(nonatomic) CGColorSpaceRef colorspace;
@property(nonatomic) BOOL framebufferOnly;
@property(nonatomic) CGSize drawableSize;
@property(nonatomic, readonly) CGSize preferredDrawableSize;
@property(nonatomic) BOOL autoResizeDrawable;
@property(nonatomic) MTLClearColor clearColor;
@property(nonatomic) MTLPixelFormat depthStencilPixelFormat;
@property(nonatomic) MTLTextureUsage depthStencilAttachmentTextureUsage;
@property(nonatomic) double clearDepth;
@property(nonatomic) uint32_t clearStencil;
@property(nonatomic) NSUInteger sampleCount;
@property(nonatomic) MTLTextureUsage multisampleColorAttachmentTextureUsage;
@property(nonatomic, readonly, nullable) MTLRenderPassDescriptor* currentRenderPassDescriptor;
@property(nonatomic, readonly, nullable) id<CAMetalDrawable> currentDrawable;
@property(nonatomic, readonly, nullable) id<MTLTexture> depthStencilTexture;
@property(nonatomic, readonly, nullable) id<MTLTexture> multisampleColorTexture;
@property(nonatomic) NSInteger preferredFramesPerSecond;
@property(nonatomic, getter=isPaused) BOOL paused;
@property(nonatomic) BOOL enableSetNeedsDisplay;
@property(nonatomic) BOOL presentsWithTransaction;
@property(nonatomic) MTLStorageMode depthStencilStorageMode;

- (instancetype)initWithFrame: (NSRect)frame
                       device: (id<MTLDevice>)device;
- (void)draw;
- (void)releaseDrawables;

@end

#endif // _METALKIT_MTKVIEW_H_
