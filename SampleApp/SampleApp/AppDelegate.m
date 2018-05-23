//
//  AppDelegate.m
//  SampleApp
//
//  Created by Daniel Granahan on 12/4/17.
//  Copyright © 2017 Placed. All rights reserved.
//

#import "AppDelegate.h"
#import <Placed/PlacedAgent.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Initialize Placed SDK
    // IMPORTANT: This is where you'll want to enter your app key.
    [PlacedAgent createWithAppKey:@"<Your Application Key>" andDelegate:nil];

    return YES;
}

@end
