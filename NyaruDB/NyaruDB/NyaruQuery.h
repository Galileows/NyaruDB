//
//  NyaruQuery.h
//  NyaruDB
//
//  Created by Kelp on 2013/02/19.
//
//

#import <Foundation/Foundation.h>

@class NyaruCollection;


@interface NyaruQuery : NSObject

#pragma mark - Properties
@property (strong, nonatomic, readonly) NyaruCollection *collection;
@property (strong, nonatomic) NSMutableArray *queries;

/**
 Get NyaruQuery instance.
 */
- (id)initWithCollection:(NyaruCollection *)collection;

@end



#pragma mark - Extensions
@interface NyaruQuery (NyaruQueryIn)
#pragma mark - Intersection
- (NyaruQuery *)and:(NSString *)indexName equal:(id)value;
- (NyaruQuery *)and:(NSString *)indexName notEqual:(id)value;
- (NyaruQuery *)and:(NSString *)indexName less:(id)value;
- (NyaruQuery *)and:(NSString *)indexName lessEqual:(id)value;
- (NyaruQuery *)and:(NSString *)indexName greater:(id)value;
- (NyaruQuery *)and:(NSString *)indexName greaterEqual:(id)value;
- (NyaruQuery *)and:(NSString *)indexName like:(NSString *)value;

#pragma mark - Union
- (NyaruQuery *)orAll;
- (NyaruQuery *)or:(NSString *)indexName equal:(id)value;
- (NyaruQuery *)or:(NSString *)indexName notEqual:(id)value;
- (NyaruQuery *)or:(NSString *)indexName less:(id)value;
- (NyaruQuery *)or:(NSString *)indexName lessEqual:(id)value;
- (NyaruQuery *)or:(NSString *)indexName greater:(id)value;
- (NyaruQuery *)or:(NSString *)indexName greaterEqual:(id)value;
- (NyaruQuery *)or:(NSString *)indexName like:(NSString *)value;


#pragma mark - Order By
- (NyaruQuery *)orderBy:(NSString *)indexName;
- (NyaruQuery *)orderByDESC:(NSString *)indexName;


#pragma mark - Count
- (NSUInteger)count;


#pragma mark - Fetch
/**
 Fetch documents.
 @return [NSMutableDictionary()]
 */
- (NSArray *)fetch;
/**
 Fetch documents with limit.
 @param limit The result limit.
 */
- (NSArray *)fetch:(NSUInteger)limit;
/**
 Fetch documents with limit and skip.
 @param limit The result limit.
 @param skip The result skip.
 */
- (NSArray *)fetch:(NSUInteger)limit skip:(NSUInteger)skip;
/**
 Fetch the first document.
 If result is empty it will return nil.
 @return nil or NSMutableDictionary()
 */
- (NSMutableDictionary *)fetchFirst;

#pragma mark Fetch Async
/**
 Async fetch documents.
 @param handler The result handler.
 */
- (void)fetchAsync:(void (^)(NSArray *))handler;


#pragma mark - Remove
- (void)remove;


@end
