Pod::Spec.new do |s|
  s.name             = "AtSugarMixin"
  s.version          = "0.1.0"
  s.summary          = "Sugar for your @ -- mixin style"
  s.homepage         = "https://github.com/MediaHound/AtSugarMixin"
  s.license          = 'Apache'
  s.author           = { "Dustin Bachrach" => "dustin@mediahound.com" }
  s.source           = { :git => "https://github.com/MediaHound/AtSugarMixin.git", :tag => s.version.to_s }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Source/*.{h,m}'

  s.dependency 'ObjectiveMixin' 
end
