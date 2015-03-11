Pod::Spec.new do |s|
  s.name             = "AtSugarMixin"
  s.version          = "0.0.1"
  s.summary          = "Sugar for your @ -- mixin style"
  s.homepage         = ""
  s.license          = 'Apache'
  s.author           = { "Dustin Bachrach" => "ahdustin@gmail.com" }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Source/*.{h,m}'

  s.dependency 'ObjectiveMixin' 
end
