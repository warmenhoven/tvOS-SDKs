//
//  TVViewElement.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVMLKit/TVMLKitDefines.h>
#import <TVMLKit/TVViewElementStyle.h>

NS_ASSUME_NONNULL_BEGIN

TVML_DEPRECATED_BEGIN("Please use SwiftUI or UIKit", ios(9.0, 18.0), tvos(9.0, 18.0))

typedef NS_ENUM(NSInteger, TVElementEventType) {
    TVElementEventTypePlay = 1,
    TVElementEventTypeSelect,
    TVElementEventTypeHoldSelect,
    TVElementEventTypeHighlight,
    TVElementEventTypeChange
};

typedef NS_ENUM(NSInteger, TVElementUpdateType) {
    TVElementUpdateTypeNone,
    
    /*!
     @brief Signifies that one of the elements in the subtree is updated without
            affecting the order of immediate children.
     */
    TVElementUpdateTypeSubtree,
    
    /*!
     @brief Signifies that style property on view elements could have changed as
     a result of reevaluating media queries.
     */
    TVElementUpdateTypeStyles TVML_DEPRECATED_IOS(10_0, 18_0),

    /*!
     @brief Signifies that the order of children is updated due to addition,
            removal or replacement of child nodes.
     */
    TVElementUpdateTypeChildren,
    
    /*!
     @brief Signifies that the node itself and its subtree is modified.
     */
    TVElementUpdateTypeSelf,
};

/*!
 @abstract Properties of TVViewElement that can be reset by the client to their
 default values. These properties communicate a message from the DOM, as opposed to
 define the model, which the client should reset after their values have been
 read.
 */
typedef NS_ENUM(NSInteger, TVElementResettableProperty) {
	/*!
	 @brief Maps to updateType property.
	 */
	TVElementResettablePropertyUpdateType,
	
	/*!
	 @brief Maps to autoHighlightIdentifier.
	 */
	TVElementResettablePropertyAutoHighlightIdentifier,
};

/*!
 @description TVViewElement represents a read only DOM node along with it's
                attributes and aggregated style. This model object is traversed
                by the factory to construct view/view controllers, to render templates.
                View/View controllers should use the avaliable dispatch API's to
                send user events to JavaScript.
 */
@interface TVViewElement : NSObject <NSCopying>

// Unique identifier for the element
@property (nonatomic, readonly) NSString* elementIdentifier;
@property (nonatomic, readonly) NSString *elementName;
@property (nonatomic, weak, readonly, nullable) TVViewElement *parentViewElement;
@property (nonatomic, readonly, nullable) NSArray<__kindof TVViewElement *> *childViewElements;
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, NSString *> *attributes;
@property (nonatomic, readonly, nullable) TVViewElementStyle *style;
// Value for "autoHighlight" attribute, defines the inital focused element.
@property (nonatomic, readonly, nullable) NSString *autoHighlightIdentifier;
// Value for "disabled" attribute
@property (nonatomic, getter = isDisabled) BOOL disabled;
// Defines the update type after a DOM re-parse. Initial state is TVElementUpdateTypeNone.
@property (nonatomic, readonly) TVElementUpdateType updateType;
@property (nonatomic, readonly) NSDictionary<NSString *, id> *elementData TVML_DEPRECATED_IOS(13_0, 18_0);

/*!
 @abstract Resets the property to its default value. This API can be used to reset 
 	a resettable property to its default value after the changes have been read.
 */
- (void)resetProperty:(TVElementResettableProperty)resettableProperty;

// API's to dispatch events to JavaScript
- (void)dispatchEventOfType:(TVElementEventType)type
                  canBubble:(BOOL)canBubble
               cancellable:(BOOL)isCancellable
                  extraInfo:(nullable NSDictionary<NSString *, id> *)extraInfo
            completion:(nullable void (^)(BOOL isDispatched, BOOL isCancelled))completion;

- (void)dispatchEventWithName:(NSString *)eventName
            canBubble:(BOOL)canBubble
         cancellable:(BOOL)isCancellable
            extraInfo:(nullable NSDictionary<NSString *, id> *)extraInfo
      completion:(nullable void (^)(BOOL isDispatched, BOOL isCancelled))completion;

@end

TVML_DEPRECATED_END

NS_ASSUME_NONNULL_END
