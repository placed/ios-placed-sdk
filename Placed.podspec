Pod::Spec.new do |s|
  s.name         = "Placed"
  s.version      = "4.2.0"
  s.summary      = "Placed Affiliate SDK"
  s.homepage     = "https://www.placed.com"
  s.author       = { "Placed Affiliate Program" => "affiliate@placed.com" }
  s.platform     = :ios, '8.0'

  s.resources           = 'Placed.bundle'
  s.source              = { :git => 'https://github.com/placed/ios-placed-sdk.git' }
  s.vendored_frameworks = 'Placed.framework'
  s.xcconfig            = { 'OTHER_LDFLAGS' => '-ObjC' }
  s.preserve_paths      = 'Placed.framework'

  s.frameworks  = 'CoreData', 'CoreTelephony', 'CoreLocation', 'CoreMotion', 'SystemConfiguration', 'AdSupport', 'Foundation', 'UIKit', 'Security'
  s.dependency 'CocoaLumberjack'
end
