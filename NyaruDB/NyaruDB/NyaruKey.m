//
//  NyaruKey.m
//  NyaruDB
//
//  Created by Kelp on 2013/02/19.
//
//

#import "NyaruKey.h"

@implementation NyaruKey

@synthesize indexOffset = _indexOffset;
@synthesize documentOffset = _documentOffset;
@synthesize documentLength = _documentLength;
@synthesize blockLength = _blockLength;

- (id)initWithIndexOffset:(unsigned)index documentOffset:(unsigned)offset documentLength:(unsigned)length blockLength:(unsigned)blockLength
{
    self = [super init];
    if (self) {
        _indexOffset = index;
        _documentLength = length;
        _documentOffset = offset;
        _blockLength = blockLength;
    }
    return self;
}

@end
