//
//  AppDelegate.h
//  iTunes Volume Control
//
//  Created by Andrea Alberti on 25.12.12.
//  Copyright (c) 2012 Andrea Alberti. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/CoreAnimation.h>
//#import <ScreenSaver/ScreenSaver.h>
#import "iTunes.h"
#import "AppleRemote.h"

@class IntroWindowController;

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    CALayer *mainLayer;
    CALayer *volumeImageLayer;
    CALayer *volumeBar[16];
    
    NSImage *imgVolOn,*imgVolOff;
    
    NSUserDefaults *preferences;
    
    CABasicAnimation *fadeOutAnimation;
    CABasicAnimation *fadeInAnimation;
    
    CFMachPortRef eventTap;
    CFRunLoopSourceRef runLoopSource;
    
    NSImage *statusImageOn;
    NSImage *statusImageOff;
    
    AppleRemote* remote;
    
    NSInteger oldVolumeSetting;
    
    bool _AppleRemoteConnected;
    bool _Tapping;
    bool _UseAppleCMDModifier;
    bool _AutomaticUpdates;
    bool _hideFromStatusBar;
    
@public
    iTunesApplication *iTunes;
    IntroWindowController *introWindowController;
    bool keyIsRepeat;
    NSTimer* timer;
    NSTimer* timerImgSpeaker;
    NSTimeInterval waitOverlayPanel;
    bool fadeInAnimationReady;
}

@property (nonatomic, assign) IBOutlet NSWindow* volumeWindow;
@property (nonatomic, assign) IBOutlet NSMenu* statusMenu;

@property (nonatomic, readonly, strong) NSStatusItem* statusBar;
@property (nonatomic, readonly, assign) BOOL menuIsVisible;

@property (assign, nonatomic) bool AppleRemoteConnected;
@property (assign, nonatomic) bool StartAtLogin;
@property (assign, nonatomic) bool Tapping;
@property (assign, nonatomic) bool UseAppleCMDModifier;
@property (assign, nonatomic) bool AutomaticUpdates;
@property (assign, nonatomic) bool hideFromStatusBar;
@property (assign, nonatomic) bool loadIntroAtStart;

- (void)showSpeakerImg:(NSTimer*)theTimer;
- (void)hideSpeakerImg:(NSTimer*)theTimer;

- (void)refreshVolumeBar:(NSInteger)volume;
- (void) createVolumeBar;
- (void) displayVolumeBar;

- (IBAction)toggleUseAppleCMDModifier:(id)sender;
- (void) setUseAppleCMDModifier:(bool)enabled;

- (IBAction)toggleAutomaticUpdates:(id)sender;
- (bool) AutomaticUpdates;
- (void) setAutomaticUpdates:(bool)enabled;

- (IBAction)toggleHideFromStatusBar:(id)sender;
- (void)setHideFromStatusBar:(bool)enabled;

- (bool) StartAtLogin;
- (void) setStartAtLogin:(bool)enabled savePreferences:(bool)savePreferences;

- (IBAction)toggleStartAtLogin:(id)sender;
- (void) setLoadIntroAtStart:(bool)enabled;

- (IBAction)toggleTapping:(id)sender;
- (void) setTapping:(bool)enabled;

- (IBAction)toggleAppleRemote:(id)sender;
- (void)setAppleRemoteConnected:(bool)enabled;

- (IBAction)aboutPanel:(id)sender;
- (IBAction)showIntroWindow:(id)sender;

- (void) appleRemoteButton: (AppleRemoteEventIdentifier)buttonIdentifier pressedDown: (BOOL) pressedDown clickCount: (unsigned int) count;
- (void) appleRemoteInit;

- (bool)checkEventTap;
- (void)createEventTap;

- (void)introWindowWillClose:(NSNotification *)aNotification;
- (void)playPauseITunes:(NSNotification *)aNotification;
- (void)decreaseITunesVolume:(NSNotification *)aNotification;
- (void)increaseITunesVolume:(NSNotification *)aNotification;
- (void)muteITunesVolume:(NSNotification *)aNotification;
- (void)nextTrackITunes:(NSNotification *)aNotification;
- (void)previousTrackITunes:(NSNotification *)aNotification;

- (void)rampVolumeUp:(NSTimer*)theTimer;
- (void)rampVolumeDown:(NSTimer*)theTimer;

- (void)stopTimer;

- (void)changeVol:(bool)increase;

- (void)initializePreferences;

@end


