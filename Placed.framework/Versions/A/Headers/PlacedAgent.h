//
//  PlacedAgent.h version 1.3.1
//
//  Created by Mike Gottlieb on 1/10/12.
//  Copyright (c) 2012 Placed. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlacedAgentDelegate.h"
#import "PlacedTypes.h"

/** The object used to interact with the Placed SDK.
 */
@interface PlacedAgent : NSObject

/** This method initializes the PlacedAgent and sets the delegate to be notified of updates.
 
    This must be called before logStartSession.
 
    You should call this in your application:didFinishLaunchingWithOptions: method.
 
    @param appKey the app identification key you received from Placed
    @param del the PlacedAgentDelegate you wish to have notified
    @param prompt if true this will call showOptInDialog: 
 */
+ (void)createWithAppKey:(NSString *)appKey andDelegate:(id<PlacedAgentDelegate>)del;

+ (OptInStatus)getOptInStatus;
+ (void)setOptInStatus:(OptInStatus)status;

/** This method starts location tracking in the agent.
 
    Call this when you want location gathering to begin, but after initializing the agent.
 */
+ (void)startTracking;

/** This method stops all location tracking for the agent.
 
    Only call this if you want all tracking to stop.
 */
+ (void)stopTracking;

/** This method allows you to change the delegate that is notified by the agent.
 
    @param del the delegate you would like to be notified.
 */
+ (void)setAgentDelegate:(id<PlacedAgentDelegate>)del;

/** This method will present the opt in dialog.
 
    If the users selects Accept this will call startTracking.
    If the users selects Close this will call stopTracking.
 */
+ (void)showOptInDialogFromPresentingView:(UIViewController*)presentingView;

+ (void)changeOptInDialogBackgroundColor:(UIColor*)color;
+ (void)changeOptInDialogButtonColor:(UIColor*)color;
+ (void)changeOptInDialogTextColor:(UIColor*)color;

/** Returns the result of the last check for unasnwered surveys
 */
+ (BOOL)userHasSurveys;

/** Checks to see if the user has survey questions and executes the provided block with the answer.
 */
+ (void)checkForSurveysWithCompletionBlock:(void (^)(BOOL hasSurveys))callback;

/** This method will open a UIWebView hosted in the provided UIView. The webview will close when the user completes the survey.
 */
+ (void)openSurveyWebViewInHostView:(UIView*)hostView;

/** This method is used to log demographics
 
    @param demographicsJSON A string representing a JSON blob of the raw data returned by the source API
    @param source A string with the name of the demographics source (e.g. Facebook)
    @param version If the source API is versioned please include the version number.
 */
+ (void)logDemographicsJSON:(NSString*)demographicsJSON fromSource:(NSString*)source withAPIVersion:(NSString*)version;

/** This method will log a user's Facebook Likes
 
    @param likesJSON The JSON data returned by Facebook as a NSString
 
    For an explanation of likes refer to https://developers.facebook.com/docs/reference/api/user/#likes
 */
+ (void)logFacebookLikesJSON:(NSString*)likesJSON;

/** This method logs a string as a unique ID to be mapped to this user
 
    @param uniqueId the string you would like associated with the app user

 */
+ (void)logUniqueId:(NSString*)uniqueId;


/** If you have installed a crash handler please add a call to this when you experience a crash
 
    @param the time when the crash occurred.
 
 */
+ (void)logCrash:(NSDate*)timestamp;

@end
