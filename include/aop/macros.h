#ifndef AOP_MACROS_H
#define AOP_MACROS_H

#define AOP_DECLARE_FUNC_BEGIN(func_name, return_value, ...)                                                           \
    class AOPInternalMethodInitFor##func_name {                                                                        \
    public:                                                                                                            \
        AOPInternalMethodInitFor##func_name(AOPInternalInit& aop_internal_init)                                        \
                : aop_internal_init_(aop_internal_init) {                                                              \
            aop_internal_init_.RegisterFunc(#func_name);                                                               \
        }                                                                                                              \
                                                                                                                       \
    private:                                                                                                           \
        AOPInternalInit& aop_internal_init_;                                                                           \
    };                                                                                                                 \
                                                                                                                       \
    inline static AOPInternalMethodInitFor##func_name aop_internal_method_init_for_##func_name##_{aop_internal_init_}; \
                                                                                                                       \
    return_value func_name(__VA_ARGS__) {
#define AOP_DECLARE_FUNC_ASPECT(aspect)

#define AOP_DECLARE_FUNC_END() }

#endif  // AOP_MACROS_H
