//
//  TVMLKitErrors.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TVMLKit/TVMLKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

TVML_DEPRECATED_BEGIN("Please use SwiftUI or UIKit", ios(9.0, 18.0), tvos(9.0, 18.0))

TV_EXTERN NSString* const TVMLKitErrorDomain;

/*
 NSError codes for the TVMLKitErrorDomain
 */
typedef NS_ENUM(NSInteger, TVMLKitError) {
    TVMLKitErrorUnknown = 1,

    TVMLKitErrorInternetUnavailable,
    TVMLKitErrorFailedToLaunch,
    
    TVMLKitErrorLast
};

TVML_DEPRECATED_END

NS_ASSUME_NONNULL_END
