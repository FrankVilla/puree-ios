#import <Foundation/Foundation.h>
#import "PUROutput.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const PURBufferedOutputSettingsLogLimitKey;
extern NSString * const PURBufferedOutputSettingsFlushIntervalKey;
extern NSString * const PURBufferedOutputSettingsMaxRetryCountKey;

@interface PURBufferedOutputChunk : NSObject

- (instancetype)initWithLogs:(NSArray<PURLog *> *)logs;

@property (nonatomic, readonly) NSArray<PURLog *> *logs;
@property (nonatomic) NSUInteger retryCount;

@end

@interface PURBufferedOutput : PUROutput

- (void)writeChunk:(PURBufferedOutputChunk *)chunk completion:(void (^)(BOOL success))completion NS_SWIFT_NAME(write(chunk:completion:));
- (void)tick;

@property (nonatomic, readonly) NSUInteger logLimit;
@property (nonatomic, readonly) NSTimeInterval flushInterval;
@property (nonatomic, readonly) NSUInteger maxRetryCount;
@property (nonatomic, readonly) CFAbsoluteTime recentFlushTime;
@property (nonatomic, readonly) NSTimer *timer;

@end

NS_ASSUME_NONNULL_END
