//
//  SGPageView.h
//  opera
//
//  Created by Single on 16/6/11.
//  Copyright © 2016年 HL. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SGPageTitleView.h"
#import "SGPageTitleItem.h"

@class SGPageView;

@protocol SGPageItemDelegate <NSObject>
@optional
- (UIScrollView *)scrollViewInPageItem:(UIView *)pageItem;  // if not implemented automatically created.
@end

@protocol SGPageViewDelegate <NSObject>

- (NSInteger)numberOfPagesInPageView:(SGPageView *)pageView;
- (UIView <SGPageItemDelegate> *)pageView:(SGPageView *)pageView viewAtIndex:(NSInteger)index;
- (void)pageView:(SGPageView *)pageView didScrollToIndex:(NSInteger)index;

@optional
- (SGPageTitleView *)pageTitleViewInPageView:(SGPageView *)pageView;
- (SGPageTitleItem *)pageView:(SGPageView *)pageView pageTitleView:(SGPageTitleView *)pageTitleView titleItemAtIndex:(NSInteger)index;

@end

@interface SGPageView : UIView

@property (nonatomic, weak) id <SGPageViewDelegate> delegate;
@property (nonatomic, assign, readonly) NSInteger index;
@property (nonatomic, assign) NSInteger defaultIndex;   // default is 0
@property (nonatomic, assign, readonly) NSInteger numberOfPage;
@property (nonatomic, strong, readonly) SGPageTitleView * pageTitleView;

- (void)reloadData;
- (void)scrollToIndex:(NSInteger)index;
- (void)scrollToIndex:(NSInteger)index animated:(BOOL)animated;

@end
