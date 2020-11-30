#ifdef DEBUG

#define LOG(frm, args...) { \
    printf("[%s  :  %s  :  %d] ", __FILE__, __func__, __LINE__);
    printf(frm, ##args); \
    printf("\n"); \
}

else

#define LOG(frm, args...)

#endif