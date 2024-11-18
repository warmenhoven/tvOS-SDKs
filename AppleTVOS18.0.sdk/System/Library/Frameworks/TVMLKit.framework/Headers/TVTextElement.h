//
//  TVTextElement.h
//  TVMLKit
//
//  Copyright (c) 2014-2015 Apple. All rights reserved.
//

#import <TVMLKit/TVViewElement.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

TVML_DEPRECATED_BEGIN("Please use SwiftUI or UIKit", ios(9.0, 18.0), tvos(9.0, 18.0))

typedef NS_ENUM(NSInteger, TVTextElementStyle) {
    TVTextElementStyleNone,

    TVTextElementStyleTitle,
    TVTextElementStyleSubtitle,
    TVTextElementStyleDescription,
    TVTextElementStyleDecoration
};

/*!
 @decription Represents textual content for the DOM element.
 */
@interface TVTextElement : TVViewElement

@property (nonatomic, readonly, nullable) NSAttributedString *attributedText;
@property (nonatomic, readonly) TVTextElementStyle textStyle;

- (NSAttributedString *)attributedStringWithFont:(UIFont *)font;
- (NSAttributedString *)attributedStringWithFont:(UIFont *)font
                                 foregroundColor:(nullable UIColor *)foregroundColor
                                   textAlignment:(NSTextAlignment)alignment;

@end

TVML_DEPRECATED_END

NS_ASSUME_NONNULL_END
