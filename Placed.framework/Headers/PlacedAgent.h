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
    After calling registerUser this method will also handle starting location tracking in the agent.
 
    You should call this in your application:didFinishLaunchingWithOptions: method.
 
    @param appKey the app identification key you received from Placed.
    @param delegate the PlacedAgentDelegate you wish to have notified.
 */
+ (void)createWithAppKey:(NSString *)appKey andDelegate:(id<PlacedAgentDelegate>)delegate;

/** This method allows you to change the delegate that is notified by the agent.
 
    @param delegate the delegate you would like to be notified.
 */
+ (void)setAgentDelegate:(id<PlacedAgentDelegate>)delegate;

/** This will register a new user and start location tracking in the agent.

     This method should only be called once, when a new user enters the app.
 */
+ (void)registerUser;

/** This deregisters a user and stops all location tracking.

 Only call this if you want all tracking to stop. The Placed SDK can only be restarted by calling registerUser again.
 */
+ (void)deregisterUser;

/** This will return if a user is in the registered state.

 This will return true after calling registerUser and false after calling deregisterUser.
 */
+ (BOOL)isUserRegistered;

/** If you have installed a crash handler please add a call to this when you experience a crash.
 
    @param timestamp the time when the crash occurred.
 
 */
+ (void)logCrash:(NSDate *)timestamp;

@end
