

#define COLOR(msg, code, args...) printf("\033[0;1;" #code "m" msg "\033[0m", ##args)
#define RED(msg, args...)    COLOR(msg, 31, args)
#define GREEN(msg, args...)  COLOR(msg, 32, args)
#define YELLOW(msg, args...) COLOR(msg, 33, args)
#define BLUE(msg, args...)   COLOR(msg, 34, args)

// #define RED(msg, args...) printf("\033[0;31m" msg "\033[0m", args)
// #define GREEN(msg, args...) printf("\033[0;32m" msg "\033[0m", args)
// #define YELLOW(msg, args...) printf("\033[0;33m" msg "\033[0m", args)
// #define BLUE(msg, args...) printf("\033[0;34m" msg "\033[0m", args)