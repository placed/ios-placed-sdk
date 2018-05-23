//
//  SampleAlertViewController.m
//  SampleApp
//
//  Created by Stanislav Stasiuk on 5/9/18.
//  Copyright © 2018 Placed. All rights reserved.
//

#import "SampleAlertViewController.h"
#import <Placed/PlacedAgent.h>

@interface SampleAlertViewController ()

@end

@implementation SampleAlertViewController

- (instancetype)init {
    self = [super init];
    if (self) {
        self.modalPresentationStyle = UIModalPresentationOverCurrentContext;
        self.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

#pragma mark - Actions
- (IBAction)accept:(id)sender {
    // User has accepted the EULA. Call registerUser to start up the Placed SDK.
    [PlacedAgent registerUser];
    [self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)dismiss:(id)sender {
    // User has declined the EULA. Call deregisterUser to make sure the Placed SDK is shut down.
    [PlacedAgent deregisterUser];
    [self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)showTermsOfService:(id)sender {
    NSURL *url = [[NSURL alloc] initWithString:@"https://www.placed.com/terms-of-service"];
    [UIApplication.sharedApplication openURL:url options:@{} completionHandler:nil];
}

- (IBAction)showPrivacyPolicy:(id)sender {
    NSURL *url = [[NSURL alloc] initWithString:@"https://www.placed.com/privacy-policy"];
    [UIApplication.sharedApplication openURL:url options:@{} completionHandler:nil];
}

@end
