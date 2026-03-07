// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#import <Metal/MTLPipelineInternal.h>
#import <Metal/stubs.h>

@implementation MTLPipelineBufferDescriptor

#if DARLING_METAL_ENABLED

- (instancetype)init
{
	return [self initWithMutability: MTLMutabilityDefault];
}

- (instancetype)initWithMutability: (MTLMutability)mutability
{
	self = [super init];
	if (self != nil) {
		_mutability = mutability;
	}
	return self;
}

- (id)copyWithZone:(NSZone *)zone
{
	return [[MTLPipelineBufferDescriptor alloc] initWithMutability: _mutability];
}

#else

@dynamic mutability;

MTL_UNSUPPORTED_CLASS

#endif

@end

@implementation MTLPipelineBufferDescriptor (Internal)

#if DARLING_METAL_ENABLED

- (Indium::PipelineBufferDescriptor)asIndiumDescriptor
{
	return Indium::PipelineBufferDescriptor {
		static_cast<Indium::Mutability>(_mutability),
	};
}

#endif

@end

@implementation MTLPipelineBufferDescriptorArray

#if DARLING_METAL_ENABLED

{
	NSMutableDictionary<NSNumber*, MTLPipelineBufferDescriptor*>* _dict;
}

- (instancetype)init
{
	self = [super init];
	if (self != nil) {
		_dict = [NSMutableDictionary new];
	}
	return self;
}

- (instancetype)initWithDictionary: (NSDictionary<NSNumber*, MTLPipelineBufferDescriptor*>*)dictionary
{
	self = [super init];
	if (self != nil) {
		_dict = [dictionary mutableCopy];
	}
	return self;
}

- (void)dealloc
{
	[_dict release];
	[super dealloc];
}

- (MTLPipelineBufferDescriptor*)objectAtIndexedSubscript: (NSUInteger)index
{
	if (!_dict[@(index)]) {
		_dict[@(index)] = [[MTLPipelineBufferDescriptor new] autorelease];
	}
	return [[_dict[@(index)] retain] autorelease];
}

-    (void)setObject: (MTLPipelineBufferDescriptor*)desc
  atIndexedSubscript: (NSUInteger)index
{
	_dict[@(index)] = desc;
}

#else

MTL_UNSUPPORTED_CLASS

#endif

@end

@implementation MTLPipelineBufferDescriptorArray (Internal)

#if DARLING_METAL_ENABLED

- (id)copyWithZone: (NSZone*)zone
{
	return [[MTLPipelineBufferDescriptorArray alloc] initWithDictionary: _dict];
}

- (std::unordered_map<size_t, Indium::PipelineBufferDescriptor>)asIndiumDescriptors
{
	std::unordered_map<size_t, Indium::PipelineBufferDescriptor> result;

	for (NSNumber* index in _dict) {
		result[[index unsignedIntegerValue]] = [_dict[index] asIndiumDescriptor];
	}

	return result;
}

#endif

@end
