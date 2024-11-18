//
//  TVStyleFactory.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVMLKit/TVMLKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

TVML_DEPRECATED_BEGIN("Please use SwiftUI or UIKit", ios(9.0, 18.0), tvos(9.0, 18.0))

typedef NS_ENUM(NSInteger, TVViewElementStyleType) {
    TVViewElementStyleTypeInteger = 1,
    TVViewElementStyleTypeDouble,
    TVViewElementStyleTypePoint,
    TVViewElementStyleTypeString,
    TVViewElementStyleTypeColor,
    TVViewElementStyleTypeURL,
    TVViewElementStyleTypeTransform,
    TVViewElementStyleTypeEdgeInsets
};

/*!
 @description Factory to register new styles to define custom style data.
 */
@interface TVStyleFactory : NSObject

+ (void)registerStyle:(NSString *)styleName withType:(TVViewElementStyleType)type inherited:(BOOL)inherited;

@end

TVML_DEPRECATED_END

NS_ASSUME_NONNULL_END
