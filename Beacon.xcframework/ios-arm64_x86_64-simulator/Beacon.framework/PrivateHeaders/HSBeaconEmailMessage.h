#import <Foundation/Foundation.h>

#import <Beacon/HSBeaconAttachment.h>
#import <Beacon/HSBeaconCustomFieldValue.h>

@interface HSBeaconEmailMessage: NSObject

@property(strong, nonatomic) NSString *email;
@property(strong, nonatomic) NSString *name;
@property(strong, nonatomic) NSString *subject;
@property(strong, nonatomic) NSString *text;
@property(strong, nonatomic) NSMutableArray<HSBeaconAttachment *> *attachments;
@property(strong, nonatomic) NSArray<NSDictionary *> *activity;
@property(strong, nonatomic) NSArray<HSBeaconCustomFieldValue *> *customFieldValues;
@property (nonatomic, strong) NSDictionary<NSString*, NSString*> *sessionAttributes;

-(NSDictionary *)toDictionary;

- (BOOL)isEmpty;

@end
