//
//  TVElementFactory.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVMLKit/TVMLKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

TVML_DEPRECATED_BEGIN("Please use SwiftUI or UIKit", ios(9.0, 18.0), tvos(9.0, 18.0))

/*!
 @description Factory for registration of new elements that extend Apple TV markup language. Registration is required
        in order for the framework to parse these new elements and should happen prior to initializing TVApplicationController.
 */
@interface TVElementFactory : NSObject

+ (void)registerViewElementClass:(Class)elementClass forElementName:(NSString *)elementName;

@end

TVML_DEPRECATED_END

NS_ASSUME_NONNULL_END
