//
//  PlacedAgentDelegate.h
//
//  Copyright (c) 2016 Placed. All rights reserved.
//
//

#include <Foundation/Foundation.h>
#include <CoreLocation/CoreLocation.h>

/** This is the protocol used for objects that would like to access the locations collected by the Placed SDK.
 */
@protocol PlacedAgentDelegate <NSObject>

/** This method mirrors the new CLLocationManagerDelegate method didReceiveLocations.
 
 @param locations an array of CLLocation objects
 */
@optional
-(void)didReceiveLocations:(NSArray *)locations;

/** This method is called when the Placed SDK is about to sync data to the server
 */
@optional
-(void)syncStart;

/** This method is called when the user Accepts the terms of the Placed agreement
 */
@optional
-(void)userAcceptedAgreement;

/** This method is called when the user Declines the terms of the Placed agreement
 */
@optional
-(void)userDeclinedAgreement;

@end;
