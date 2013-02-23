//
//  NyaruSchema.h
//  NyaruDB
//
//  Created by Kelp on 2013/02/19.
//
//

#import <Foundation/Foundation.h>


@class NyaruKey;
@class NyaruIndex;


enum {
    NyaruSchemaTypeNumber = 0,
    NyaruSchemaTypeString = 1,
    NyaruSchemaTypeDate = 2,
    NyaruSchemaTypeNil = 3,
    NyaruSchemaTypeUnknow = 4
};
typedef NSUInteger NyaruSchemaType;


/**
 NyaruKey is a key to document offset.
 It provites fetch data.
 
 NyaruIndex is a value to key mapping.
 It provites get NyaruKey by the value of field in document.
 */
@interface NyaruSchema : NSObject {
    /**
     index of schema of 'key'. If self.unique is YES then use this.
     { key: NSString value of index key, value: NyaruKey }
     */
    NSMutableDictionary *_indexKey;
    
    /**
     index of other schemas. If self.unique is NO then use this.
     _indexNil: [NyaruIndex.key] only store key because all value are nil.
     _index: [NyaruIndex] data is sorted by index.value.
                NyaruIndex.value: document.value
                NyaruIndex.keySet: [document.key]
     */
    NSMutableArray *_indexNil;
    NSMutableArray *_index;
}

#pragma mark - Properties
/**
 Schema's data offset in the file.
 */
@property (nonatomic) unsigned int offsetInFile;
@property (nonatomic) unsigned int previousOffsetInFile;
@property (nonatomic) unsigned int nextOffsetInFile;
/**
 Schema name.
 */
@property (strong, nonatomic, readonly) NSString *name;

/**
 Is schema name @"key" ?
 */
@property (nonatomic, readonly) BOOL unique;
/**
 If the field of document is schema, all value's data type should be same.
 This is the data type of theis schema.
 */
@property (nonatomic, readonly) NyaruSchemaType schemaType;

#pragma mark - Init
/**
 Get NyaruSchema instance with schema data and offset in the file.
 */
- (id)initWithData:(NSData *)data andOffset:(NSUInteger)offset;
/**
 Create a new NyaruSchema then get the instance.
 */
- (id)initWithName:(NSString *)name previousOffser:(unsigned int)previous nextOffset:(unsigned int)next;

#pragma mark - Get Binary Data For Write Schema File
- (NSData *)dataFormate;

#pragma mark - Push Key/Index
/**
 Push NyaruKey into schema.
 @param key key of NyaruKey
 @param nyaruKey NyaruKey
 @return YES / NO
 */
- (BOOL)pushNyaruKey:(NSString *)key nyaruKey:(NyaruKey *)nyaruKey;
/**
 Push NyaruIndex into schema.
 @param key key of document
 @param value NyaruIndex.value
 */
- (void)pushNyaruIndex:(NSString *)key value:(id)value;

#pragma mark - Get Key/Index
/**
 Get NyaruKey / NyaruIndex in this schema.
 */
- (NSDictionary *)allKeys;
- (NSArray *)allNilIndexes;
- (NSArray *)allNotNilIndexes;

#pragma mark - Remove by key
- (void)removeWithKey:(NSString *)key;
- (void)removeAll;

#pragma mark - Private methods
/**
 Remove all dictionarys and arrays.
 */
- (void)close;

@end
