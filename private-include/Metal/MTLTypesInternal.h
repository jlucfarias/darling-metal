// SPDX-FileCopyrightText: 2026 Darling Developers
// SPDX-License-Identifier: MPL-2.0

#ifndef _METAL_MTLTYPESINTERNAL_H_
#define _METAL_MTLTYPESINTERNAL_H_

#import <Metal/MTLTypes.h>

#if DARLING_METAL_ENABLED
#include <indium/indium.hpp>

NS_INLINE
Indium::Size MTLSizeToIndium(MTLSize size) {
	return Indium::Size { size.width, size.height, size.depth };
};

NS_INLINE
Indium::Range<size_t> NSRangeToIndium(NSRange range) {
	return Indium::Range<size_t> { range.location, range.length };
};

NS_INLINE
Indium::Region MTLRegionToIndium(MTLRegion region) {
	return Indium::Region {
		Indium::Origin { region.origin.x, region.origin.y, region.origin.z },
		Indium::Size { region.size.width, region.size.height, region.size.depth },
	};
};
#endif

#endif // _METAL_MTLTYPESINTERNAL_H_
