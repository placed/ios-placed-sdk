//
//  ViewController.m
//  SampleApp
//
//  Created by Daniel Granahan on 12/4/17.
//  Copyright © 2017 Placed. All rights reserved.
//

#import "ViewController.h"
#import "SampleAlertViewController.h"
#import <Placed/PlacedAgent.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)registerUser:(id)sender {
    if (![PlacedAgent isUserRegistered]) {
        // If the user isn't registered with the Placed SDK, we'll show them the EULA so they can opt in.
        [self presentViewController:[SampleAlertViewController new] animated:YES completion:nil];
    } else {
        UIAlertController *successAlert = [UIAlertController
                                            alertControllerWithTitle:@"User registered!"
                                            message:@"The user is registered and the Placed SDK is running."
                                            preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okButton = [UIAlertAction
                                    actionWithTitle:@"OK"
                                    style:UIAlertActionStyleDefault
                                    handler:nil];
        [successAlert addAction:okButton];
        [self presentViewController:successAlert animated:YES completion:nil];
    }
}

@end
