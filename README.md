# Placed Affiliate SDK

## Introduction

The Placed SDK for iOS is designed to help you add Placed location gathering to your app. It exposes simple public API calls that can be used to turn location gathering on.

The SDK has been designed for easy setup and integration with both new and existing mobile applications.

## Setup

The preferred method for installing the Placed SDK in your app is using CocoaPods. CocoaPods is dependency management system for Objective-C development. You can learn more about it at [http://cocoapods.org/](http://cocoapods.org/).

1. Add the following lines to your project's Podfile
`pod 'Placed', :git => 'https://github.com/placed/ios-placed-sdk.git'`

2. Celebrate!

If you are not using CocoaPods, you can integrate the Placed.framework and Placed.bundle directly in your project.

## Location Permission

This SDK requires Apple's background location permission. Under the "Required background modes" key in your app’s main plist file you should make sure to add:

    App registers for location updates

In addition, for iOS 11, you must provide all of the following location usage descriptions in your app's plist:

    NSLocationAlwaysAndWhenInUseUsageDescription
    NSLocationWhenInUseUsageDescription
    NSLocationAlwaysUsageDescription
    NSLocationUsageDescription

**These permissions are very important to the Placed SDK. If your app does not currently use background location permission, please contact a Placed representative.**

## Integration

1. Add `#import <Placed/PlacedAgent.h>` to your main AppDelegate.

2. Initialize the agent in your AppDelegate's `application:didFinishLaunchingWithOptions:`.

    - Call `[PlacedAgent createWithAppKey:@"<Application Key>" andDelegate:nil];` providing the app key you received from Placed. Optionally, you may provide a `PlacedAgentDelegate` to this method but it is not required.
    - Next, call `[PlacedAgent startTracking]`. This method must be called on every app start, but will only begin location collection if the user has been registered via the `[PlacedAgent registerUser]` method (see below).

3. Call `[PlacedAgent registerUser]` to register a new user for location collection by the Placed SDK. This method should only be called once in the user's lifecycle. If you have EULA or terms of service that the user is required to accept before tracking, call this method after the user accepts those terms.

## How to join
Please contact your Placed representative to find out how to register your account. If you do not have a representative yet, please email [affiliate@placed.com](mailto:affiliate@placed.com)

## Support
For further guidance contact [affiliate@placed.com](mailto:affiliate@placed.com)
