//
//  TVImageElement.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#import <TVMLKit/TVViewElement.h>

NS_ASSUME_NONNULL_BEGIN

TVML_DEPRECATED_BEGIN("Please use SwiftUI or UIKit", ios(9.0, 18.0), tvos(9.0, 18.0))

typedef NS_ENUM(NSInteger, TVImageType) {
    TVImageTypeImage,
    
    TVImageTypeFullscreen,
    TVImageTypeDecoration,
    TVImageTypeHero
};

/*!
 @decription Convenience class representing <img /> element.
 */
@interface TVImageElement : TVViewElement

@property (nonatomic, readonly, nullable) NSURL *URL;
@property (nonatomic, readonly, nullable) NSDictionary<NSString *, NSURL *> *srcset;
@property (nonatomic, readonly) TVImageType imageType;

@end

TVML_DEPRECATED_END

NS_ASSUME_NONNULL_END
