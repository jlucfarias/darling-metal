// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#import <Metal/MTLDrawableInternal.h>
#import <Metal/stubs.h>

@implementation MTLDrawableInternal

#if DARLING_METAL_ENABLED

@synthesize drawable = _drawable;

- (instancetype)initWithDrawable: (std::shared_ptr<Indium::Drawable>)drawable
{
	self = [super init];
	if (self != nil) {
		_drawable = drawable;
	}
	return self;
}

- (NSUInteger)drawableID
{
	NSLog(@"STUB: drawableID");
	return 0;
}

- (CFTimeInterval)presentedTime
{
	NSLog(@"STUB: presentedTime");
	return 0;
}

- (void)present
{
	_drawable->present();
}

- (void)presentAfterMinimumDuration: (CFTimeInterval)duration
{
	NSLog(@"STUB: presentAfterMinimumDuration");
	abort();
}

- (void)presentAtTime: (CFTimeInterval)presentationTime
{
	NSLog(@"STUB: presentAtTime");
	abort();
}

- (void)addPresentedHandler: (MTLDrawablePresentedHandler)block
{
	NSLog(@"STUB: addPresentedHandler");
	abort();
}

#else

@dynamic drawableID;
@dynamic presentedTime;

MTL_UNSUPPORTED_CLASS

#endif

@end
