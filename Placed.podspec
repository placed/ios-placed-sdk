Pod::Spec.new do |s|
  s.name         = "Placed"
  s.version      = "4.0.1"
  s.summary      = "Placed Affiliate SDK"
  s.homepage     = "http://www.placed.com"
  s.author       = { "Placed Affiliate Program" => "affiliate@placed.com" }
  s.platform     = :ios, '7.0'

  s.resources           = 'Placed.bundle'
  s.source              = { :git => 'https://github.com/placed/placed-sdk.git' }
  s.vendored_frameworks = 'Placed.framework'
  s.xcconfig            = { 'OTHER_LDFLAGS' => '-lObjc' }
  s.preserve_paths      = 'Placed.framework'

  s.frameworks  = 'CoreData', 'CoreTelephony', 'CoreLocation', 'CoreMotion', 'SystemConfiguration', 'AdSupport', 'Foundation', 'CoreGraphics', 'UIKit', 'Security'
  s.libraries   = 'z', 'sqlite3'

  s.dependency 'Reachability', '~> 3.2'
  s.dependency 'Base64', '~> 1.0.1'
end
