////
//// Created by 鲁蕴铖 on 16/3/30.
////
//
//template <typename  To,typename  From>
//inline To implicit_cast(From const &f) {
//    return f;
//};
//
//
//template <typename  To,typename From>
//inline To down_cast(From *f) {
//    if(false) {
//        implicit_cast(From*,To)(0);
//    }
//#if !defined(NDEBUG) && !defined(GOOGLE_PROTOBUF_NO_RTTI)
//    assert(f == NULL || dynamic_cast<To>(f) !=NULL);
//#endif
//    return static_cast<To>(f);
//};