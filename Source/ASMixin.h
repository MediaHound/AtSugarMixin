//
//  ASMixin.h
//  AtSugar
//
//  Created by Dustin Bachrach on 11/19/14.
//
//

#import <ObjectiveMixin/Mixin.h>

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL(, ##__VA_ARGS__, 5,4,3,2,1,0)
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N

#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro ## nargs


#define synthesize_property_list0(...)
#define synthesize_property_list1(A0, ...)      @synthesize A0 = _##A0;
#define synthesize_property_list2(A0, A1, ...)      @synthesize A0 = _##A0; @synthesize A1 = _##A1;
#define synthesize_property_list3(A0, A1, A2, ...)      @synthesize A0 = _##A0; @synthesize A1 = _##A1; @synthesize A2 = _##A2;
#define synthesize_property_list4(A0, A1, A2, A3, ...)      @synthesize A0 = _##A0; @synthesize A1 = _##A1; @synthesize A2 = _##A2; @synthesize A3 = _##A3;

#define synthesize_property_list(...) macro_dispatcher(synthesize_property_list, __VA_ARGS__)(__VA_ARGS__)

#define synthesize_from_mixin(m) class __AS_MIXIN__4__UNUSED__;\
synthesize_property_list(m ## SynthesizeProperties)


// TODO: It would be nice to not have to pass in name of the class here.
#define mixin2(name, m1) \
+ (void)initialize\
{\
    if (self.class == name.class) {\
        [self mixinFrom:m1.class];\
    }\
}\
@synthesize_from_mixin (m1)


#define mixin3(name, m1, m2) \
+ (void)initialize\
{\
    if (self.class == name.class) {\
        [self mixinFrom:m1.class];\
        [self mixinFrom:m2.class];\
    }\
}\
@synthesize_from_mixin (m1)\
@synthesize_from_mixin (m2)


#define mixin(...) class __AS_MIXIN__3__UNUSED__;\
macro_dispatcher(mixin, __VA_ARGS__)(__VA_ARGS__)
