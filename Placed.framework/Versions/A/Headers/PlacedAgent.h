//
//  PlacedAgent.h
//
//  Copyright (c) 2016 Placed. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlacedAgentDelegate.h"

/** The object used to interact with the Placed SDK.
 */
@interface PlacedAgent : NSObject

/** This method initializes the PlacedAgent and sets the delegate to be notified of updates.
 
    You should call this in your application:didFinishLaunchingWithOptions: method.
 
    @param appKey the app identification key you received from Placed.
    @param delegate the PlacedAgentDelegate you wish to have notified.
 */
+ (void)createWithAppKey:(NSString *)appKey andDelegate:(id<PlacedAgentDelegate>)delegate;

/** This method starts location tracking in the agent.
 
    Call this when you want location gathering to begin, but after initializing the agent.
 */
+ (void)startTracking;

/** This method stops all location tracking for the agent.
 
    Only call this if you want all tracking to stop.
 */
+ (void)stopTracking;

/** This method allows you to change the delegate that is notified by the agent.
 
    @param delegate the delegate you would like to be notified.
 */
+ (void)setAgentDelegate:(id<PlacedAgentDelegate>)delegate;

/** This method will present the opt in dialog.
 
    If the users selects Accept this will call startTracking.
    If the users selects Close this will call stopTracking.
 */
+ (void)showOptInDialogFromPresentingView:(UIViewController *)presentingView completion:(void (^)())completion;

+ (void)changeOptInDialogBackgroundColor:(UIColor *)color;
+ (void)changeOptInDialogButtonColor:(UIColor *)color;
+ (void)changeOptInDialogTextColor:(UIColor *)color;

/** Returns the result of the last check for unasnwered surveys
 */
+ (BOOL)userHasSurveys;

/** Checks to see if the user has survey questions and executes the provided block with the answer.
 */
+ (void)checkForSurveysWithCompletionBlock:(void (^)(BOOL hasSurveys))callback;

/** This method will open a UIWebView hosted in the provided UIView. The webview will close when the user completes the survey.
 */
+ (void)openSurveyWebViewInHostView:(UIView*)hostView;

/** If you have installed a crash handler please add a call to this when you experience a crash.
 
    @param timestamp the time when the crash occurred.
 
 */
+ (void)logCrash:(NSDate *)timestamp;

@end
