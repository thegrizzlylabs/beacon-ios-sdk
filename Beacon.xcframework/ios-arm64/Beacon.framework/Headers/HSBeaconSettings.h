#import <UIKit/UIKit.h>

#import <Beacon/HSBeaconContactForm.h>
#import <Beacon/HSBeaconMessagingSettings.h>
#import <Beacon/HSBeaconSettings.h>
#import <Beacon/HSBeaconFocusMode.h>

NS_ASSUME_NONNULL_BEGIN

/**
 `HSBeaconDelegate` can optionally be set on your `HSBeaconSettings` object to customize
 the runtime behavior of the Beacon SDK.
 */
@protocol HSBeaconDelegate <NSObject>


@optional
/**
 The `prefill` method is called before showing the new conversation contact form. Any values
 set on the `form` object will be prepopulated for the customer.

 @note Prefilled forms will be ignored if there is an existing draft message. Draft messages can be removed by calling the `reset` function on `HSBeacon`.
 */
- (void)prefill:(HSBeaconContactForm *)form;

@optional
/**
 The `sessionAttributes` method is called before showing the new conversation contact form or before starting a chat. Keys (labels) and values in this dictionary (up to 20)
 will be added into the Beacon visitor activity note that’s only relevant to a specific conversation or chat. We do not sync this data to either the customer
 profile or the Beacon Sidebar app.

 @note Each attribute label can contain up to 100 characters, and each value can contain up to 10,000 characters.
 */
- (NSDictionary<NSString*, NSString*> *)sessionAttributes;

@optional
/**
 This method is called the first time the Beacon is displayed, after the configuration
 has been successfully loaded over the network.
 */
- (void)onBeaconInitialOpen:(HSBeaconSettings *)beaconSettings;


@optional
/**
 This method is called anytime the Beacon modal is displayed.
 */
- (void)onBeaconOpen:(HSBeaconSettings *)beaconSettings;


@optional
/**
 This method is called the first time the Beacon is dismissed each session.
 */
- (void)onBeaconInitialClose:(HSBeaconSettings *)beaconSettings;


@optional
/**
 This method is called every time the Beacon modal is dismissed.
 */
- (void)onBeaconClose:(HSBeaconSettings *)beaconSettings;

@end


/**
 `HSBeaconSettings` allows you to customize the Beacon SDK and provide the
 Beacon identifier to use.

 ### Initialization

     HSBeaconSettings *settings = [[HSBeaconSettings alloc] initWithBeaconId:@"beacon-id"];
     settings.useNavigationBarAppearance = NO;
 */
@interface HSBeaconSettings: NSObject

/**
 The Beacon ID to use.

 @note This can be found during Beacon creation.
 */
@property(strong, nonatomic, readonly, nonnull) NSString *beaconId;

/**
 The title used in the main Beacon interface. This is `Support` by default.
 */
@property(strong, nonatomic) NSString *beaconTitle;

/**
 * Display strings from BeaconLocalizable.strings instead of those setup in the Beacon Web UI
 */
@property BOOL useLocalTranslationOverrides;

/**
 Allows the Beacon SDK to use the `UIAppearance` settings for `UINavigationController`.
 This is false by default, and will instead use the Beacon color defined in the Beacon Builder.
 */
@property BOOL useNavigationBarAppearance;

/**
 Disable the contact options manually if it's enabled in the Beacon config.

 This will not enable the contact options if it's disabled in the config.
 */
@property BOOL messagingEnabled;

/**
Disable previous messages manually if messaging is enabled in the Beacon config.
*/
@property BOOL enablePreviousMessages;

/**
 Disable the Docs integration manually if it's enabled in the Beacon config.

 This will not enable Docs if it's disabled in the config.
 */
@property BOOL docsEnabled;

/**
 Disable the Chat integration manually if it's enabled in the Beacon config.

 This will not enable Chat if it's disabled in the config.
 */
@property BOOL chatEnabled;

/**
 Override the focusMode configured on the Beacon config.
*/
@property (nonatomic, assign) HSBeaconFocusMode focusModeOverride;

/**
 Was focusModeOverride set with a local override.
 */
@property (nonatomic, readonly) BOOL focusModeOverrideSet;

/**
 This replaces the default blue color used for clickable text throughout Beacon. For example,
 you may want to set this to the tintColor of your window to match the look and feel of the
 rest of your app.
 */
@property UIColor *tintColorOverride;

/**
 Used for customizing the runtime behavior of the Beacon SDK
 */
@property (weak, nonatomic, nullable) id<HSBeaconDelegate> delegate;

/**
 Override the color from the Beacon Builder. The `useNavigationBarAppearance` option
 will override this value.
 */
@property (strong, nonatomic, nullable) UIColor *color;

/**
 Set different display options for messaging.
 */
@property (nonatomic, nonnull, readonly) HSBeaconMessagingSettings *messagingSettings;

// also use translations from the API or local translation strings (maybe)

/**
 Initialize Beacon settings with a given Beacon ID.
 */
- (instancetype)initWithBeaconId:(NSString * _Nonnull)beaconId;

//MARK: - Unavailable Methods

/**
 `-[HSBeaconSettings init]` is not available because `HSBeaconSettings` must be initialized with a `beaconId`
 Use the `initWithBeaconId:` method to display the Beacon SDK.
 */
- (instancetype)init __attribute__((unavailable("HSBeaconSettings must be initialized with a `beaconId`")));

@end

NS_ASSUME_NONNULL_END
