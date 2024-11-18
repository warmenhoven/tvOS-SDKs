//
//  TVInterfaceFactory.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVMLKit/TVMLKitDefines.h>
#import <TVMLKit/TVViewElement.h>
#import <TVMLKit/TVPlayback.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

TVML_DEPRECATED_BEGIN("Please use SwiftUI or UIKit", ios(9.0, 18.0), tvos(9.0, 18.0))

@protocol TVInterfaceCreating <NSObject>

@optional

/*!
 @description Return a view for the given view element. It is preferred to reuse the existingView if it can be updated.
        When existingView is an instance of UICollectionViewCell, the cell must be configured instead of creating a new instance.
        Application must return nil if event is not handled.
 */
- (nullable UIView *)viewForElement:(TVViewElement *)element existingView:(nullable UIView *)existingView;

/*!
 @description Return a view controller for the given view element. It is preferred to reuse the existingViewController if it can be updated.
        Application must return nil if event is not handled.
 */
- (nullable UIViewController *)viewControllerForElement:(TVViewElement *)element existingViewController:(nullable UIViewController *)existingViewController;

/*!
 @description Return a URL given the resource name. The resource name is retrieved from a resource URL specified in elements like badge, img etc. 
        For example, <badge src="resource://developer-resource" will request for resource with name 'developer-resource'. Application must return
        nil if event is not handled.
 */
- (nullable NSURL *)URLForResource:(NSString *)resourceName;

/*!
 @description Return a UIImage given the resource name. The resource name is retrieved from a resource URL specified in elements like badge, img etc.
        For example, <badge src="resource://developer-resource" will request for resource with name 'developer-resource'. This only works for image 
        elements. Return nil if no image matches the resource name or it is not handled.
 */
- (nullable UIImage *)imageForResource:(NSString *)resourceName TVML_DEPRECATED_IOS(9_2, 18_0);

/*
 @description Return a collection view cell class given an element contained in a list, shelf or grid. A common cell class is used for all elements
 		that share the same name in a collection, hence this method is only called once per a unique element name. Return nil for default handling.
 */
- (nullable Class)collectionViewCellClassForElement:(TVViewElement *)element TVML_DEPRECATED_IOS(10_0, 18_0);

/*
 @description Return customer player user interface for a custom player
 */
- (nullable UIViewController *)playerViewControllerForPlayer:(TVPlayer *)player TVML_DEPRECATED("Please use SwiftUI or UIKit", tvos(12.0, 18.0)) NS_SWIFT_NAME(playerViewController(for:));

@end

/*!
 @description Interface factory for creation of views and view controllers. Application can extend or override framework implementation by setting extendedInterfaceCreator.
 */
@interface TVInterfaceFactory : NSObject <TVInterfaceCreating>

/*!
 @abstract Returns the singelton instance of the interface factory.
 */
+ (instancetype)sharedInterfaceFactory;

/*!
 @description Application must provide its own implementation to handle custom registered elements. Optionally application can also override framework implementation of farmework defined elements.
 */
@property (nonatomic, strong, nullable) id<TVInterfaceCreating> extendedInterfaceCreator;

@end

TVML_DEPRECATED_END

NS_ASSUME_NONNULL_END
