# AtSugarMixin

AtSugarMixin extends [AtSugar](https://github.com/MediaHound/AtSugar) to easily uses Mixins. Mixin functionality is provided by [ObjectiveMixin](https://github.com/vl4dimir/ObjectiveMixin).

## Installation

AtSugarMixin is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

    pod "AtSugarMixin"

Then include the header:

```objc
#import <AtSugarMixin/ASMixin.h>
```

First, declare a protocol for behavior implemented by a mixin. AtSugarMixin even allows you to mixin properties!

```objc
@protocol MyMixinProtocol <NSObject>

@property (strong, nonatomic) NSString* aStringProperty;
@property (strong, nonatomic) NSArray* anArrayProperty;

- (void)doSomething;

@end
```

You then create a class that will provide the mixin implementation. This class conforms to your mixin protocol.

```objc
#define MyMixinSynthesizeProperties aStringProperty, anArrayProperty


@interface MyMixin : NSObject <MYMixinProtocol>

@end
```

We need to define `MyMixinSynthesizeProperties` so that that AtSugarMixin will synthesize the properties from the protocol.

```objc
@implementation MyMixin

@synthesize_from_mixin (MyMixin)

- (void)doSomething
{
    // implementation
}

@end
```

Now we can mixin our `MyMixin` behavior to any class we want.

```objc
@interface MyObject : NSObject <MyMixinProtocol>

@end

@implementation MyObject

@synthesize_from_mixin (MyMixin)

@end
```

Now `MyObject` has 2 mixed in properties: `aStringProperty` and `anArrayProperty`. It also has a mixed in method: `-doSomething`.

## Author

MediaHound

## License

AtSugarMixin is available under the Apache License 2.0. See the LICENSE file for more info.

