#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#ifdef PATH_MAX
#ifdef NAME_MAX
#define FILE_SYSTEM_BUFF_SIZE (PATH_MAX + NAME_MAX + 1)
#else
#error "NAME_MAX not defined"
#endif
#else
#error "PATH_MAX not defined"
#endif

#define NR_OF_SUPPORTET_LANG 11
#define CARD_LEN 15
#define MAX_SIZE_ELEMENT 15
#define SUPPORTET_GROUPS 11
#define ERRR 0xFFFAFFFu

typedef struct {
    int doppel;
    const char *name;
    uint64_t countet_size;
    int globalsumindex;
} Type;

typedef struct MemNode {
    void *ptr;
    struct MemNode *next;
} MemNode;

static int unix_index = 0;
static int unix_max = 1024;
static MemNode *mem_head = NULL;

static Type types[NR_OF_SUPPORTET_LANG] = {
    {0, "txt",    0ULL, 0},   // 0: PHP
    {0, "c",      0ULL, 1},   // 1: C
    {0, "cpp",    0ULL, 2},   // 2: C++
    {0, "ino",    0ULL, 3},   // 3: ESP
    {0, "py",     0ULL, 4},   // 4: Python
    {0, "java",   0ULL, 5},   // 5: Java
    {0, "sh",     0ULL, 6},   // 6: Shell
    {0, "js",     0ULL, 7},   // 7: JavaScript
    {0, "html",   0ULL, 8},   // 8: HTML
    {0, "asm",    0ULL, 9},   // 9: Assembly
    {0, "rs",     0ULL, 10}   // 10: Rust
};

static const char *nameList[NR_OF_SUPPORTET_LANG] = {
    "undefined",    // 0
    "C",            // 1
    "C++",          // 2
    "ESP",          // 3
    "Python",       // 4
    "Java",         // 5
    "ShellScript",  // 6
    "JavaScript",   // 7
    "HTML",         // 8
    "Assembly",     // 9
    "Rust"          // 10
};

static const uint64_t colorList[NR_OF_SUPPORTET_LANG] = {
    0x2222077877CC,   // 0: PHP
    0x222205666666,   // 1: C
    0x22220A2222FF,   // 2: C++
    0x22220FEEAA00,   // 3: ESP
    0x222200A8A862,   // 4: Python
    0x222200FFFF00,   // 5: Java
    0x222200FF0010,   // 6: ShellScript
    0x222200BB0010,   // 7: JavaScript
    0x222200888888,   // 8: HTML
    0x222200FF8800,   // 9: Assembly
    0x222200DEA584    // 10: Rust
};

void clipper(char *content) {
    size_t len = strlen(content);
    FILE *p = popen("xclip -selection clipboard", "w");
    int fd = fileno(p);
    ssize_t w = write(fd, content, len);
    pclose(p);
}

/* Convert mode bits to string like ls -l */
static void mode_to_str(mode_t m, char out[11]) {
    out[0] = S_ISDIR(m) ? 'd' : S_ISLNK(m) ? 'l' : S_ISCHR(m) ? 'c' :
             S_ISBLK(m) ? 'b' : S_ISFIFO(m) ? 'p' : S_ISSOCK(m) ? 's' : '-';
    out[1] = (m & S_IRUSR) ? 'r' : '-';
    out[2] = (m & S_IWUSR) ? 'w' : '-';
    out[3] = (m & S_IXUSR) ? 'x' : '-';
    out[4] = (m & S_IRGRP) ? 'r' : '-';
    out[5] = (m & S_IWGRP) ? 'w' : '-';
    out[6] = (m & S_IXGRP) ? 'x' : '-';
    out[7] = (m & S_IROTH) ? 'r' : '-';
    out[8] = (m & S_IWOTH) ? 'w' : '-';
    out[9] = (m & S_IXOTH) ? 'x' : '-';
    out[10] = '\0';
}

static int isDoubleIndex(int ind) {
    return types[ind].doppel;
}

static void process_size(off_t size, char *buf, size_t buflen) {
    const char *units[] = {"B","KB","MB","GB","TB"};
    double s = (double)size;
    int u = 0;
    while (s >= 1024 && u < 4) {
        s /= 1024;
        u++;
    }
    snprintf(buf, buflen, "%.1f %s", s, units[u]);
}

int memlist_add(void *ptr) {
    if (!ptr) return -1;
    MemNode *n = malloc(sizeof(MemNode));
    if (!n) return -1;
    n->ptr = ptr;
    n->next = mem_head;
    mem_head = n;
    return 0;
}

void memlist_free_all() {
    MemNode *cur = mem_head;
    while (cur) {
        MemNode *next = cur->next;
        if (cur->ptr) free(cur->ptr);
        free(cur);
        cur = next;
    }
    mem_head = NULL;
}

char *coloramaprintifarma(const char *ptext, uint64_t col) {
    uint8_t bg_r = (col >> 40) & 0xFF;
    uint8_t bg_g = (col >> 32) & 0xFF;
    uint8_t bg_b = (col >> 24) & 0xFF;
    uint8_t fg_r = (col >> 16) & 0xFF;
    uint8_t fg_g = (col >> 8)  & 0xFF;
    uint8_t fg_b = col & 0xFF;
    const char *suffix = "\033[0m";
    const char *fmt = "\033[38;2;%u;%u;%um\033[48;2;%u;%u;%um";
    int prefix_len = snprintf(NULL, 0, fmt,
                              fg_r, fg_g, fg_b,
                              bg_r, bg_g, bg_b);
    if (prefix_len < 0) return NULL;
    size_t text_len   = strlen(ptext);
    size_t suffix_len = strlen(suffix);
    size_t total_len = (size_t)prefix_len + text_len + suffix_len + 1;
    char *buf = malloc(total_len);
    if (!buf) return NULL;
    memlist_add(buf);
    int written = snprintf(buf, total_len, fmt,
                           fg_r, fg_g, fg_b,
                           bg_r, bg_g, bg_b);
    memcpy(buf + written, ptext, text_len);
    memcpy(buf + written + text_len, suffix, suffix_len + 1);
    return buf;
}

static size_t utf8_char_len(unsigned char c) {
    if (c < 0x80) return 1;
    if ((c >> 5) == 0x6) return 2;
    if ((c >> 4) == 0xE) return 3;
    if ((c >> 3) == 0x1E) return 4;
    return 1;
}

static char* coloramaprintifarmafillup(const char *text, uint64_t advansed_color) {
    if (!text) return NULL;
    char *res = malloc(CARD_LEN + 1);
    if (!res) return NULL;
    memlist_add(res);
    size_t pos = 0;
    size_t i = 0;
    while (pos < CARD_LEN && text[i]) {
        size_t clen = utf8_char_len((unsigned char)text[i]);
        if (pos + clen > CARD_LEN) break;
        memcpy(res + pos, text + i, clen);
        pos += clen;
        i += clen;
    }
    while (pos < CARD_LEN) {
        res[pos++] = ' ';
    }
    res[CARD_LEN] = '\0';
    char *colored = coloramaprintifarma(res, advansed_color);
    return colored;
}

static char *coll(uint64_t col, const char *ptext) {
    uint8_t r = (col >> 16) & 0xFF;
    uint8_t g = (col >> 8)  & 0xFF;
    uint8_t b = col         & 0xFF;
    const char *suffix = "\033[0m";
    const char *fmt = "\033[38;2;%u;%u;%um";
    int prefix_len = snprintf(NULL, 0, fmt, r, g, b);
    if (prefix_len < 0) return NULL;
    size_t text_len   = strlen(ptext);
    size_t suffix_len = strlen(suffix);
    size_t total_len = (size_t)prefix_len + text_len + suffix_len + 1;
    char *buffer = malloc(total_len);
    if (!buffer) return NULL;
    memlist_add(buffer);
    int written = snprintf(buffer, total_len, fmt, r, g, b);
    memcpy(buffer + written, ptext, text_len);
    memcpy(buffer + written + text_len, suffix, suffix_len + 1);
    return buffer;
}

static char *chngg(const char *pp, uint64_t color, int more_space) {
    int mse = (more_space == 1) ? (MAX_SIZE_ELEMENT * 3) : MAX_SIZE_ELEMENT;
    char *rptr = malloc(mse + 1);
    if (!rptr) return NULL;
    memlist_add(rptr);
    size_t pos = 0;
    size_t i = 0;
    while (pos < mse && pp[i]) {
        size_t clen = utf8_char_len((unsigned char)pp[i]);
        if (pos + clen > mse) break;
        memcpy(rptr + pos, pp + i, clen);
        pos += clen;
        i += clen;
    }
    while (pos < mse) {
        rptr[pos++] = ' ';
    }
    rptr[mse] = '\0';
    char *rrr = coll(color, rptr);
    return rrr;
}

static char *chngg_wrapper(int index, uint64_t size) {
    return coloramaprintifarmafillup(nameList[index], colorList[index]);
}

static int get_type_ind_by_name(char *type_s) {
    for (int i = 1; i < NR_OF_SUPPORTET_LANG; ++i) {
        if (strcmp(types[i].name, type_s) == 0) {
                return i;
            }
    }
    return ERRR;
}

static int add_type_value(int pp_index, size_t filesize) {
    uint64_t addid = (uint64_t)filesize;
    types[pp_index].countet_size += addid;
    return 0;
}

static void get_type(const char *fullpath, int size, size_t filesize) {
    int point_index;
    int flag = 0;
    for (point_index = size - 1; point_index >= 0; --point_index) {
        if (fullpath[point_index] == '.') { flag = 1; break; }
        if (fullpath[point_index] == '/') { flag = 0; break; }
    }
    if (!flag) return;
    int len = size - point_index - 1;
    if (len <= 0) return;
    char *type_s = malloc(len + 1);
    if (!type_s) return;
    for (int i = 0; i < len; ++i) type_s[i] = fullpath[point_index + 1 + i];
    type_s[len] = '\0';
    unsigned int index = get_type_ind_by_name(type_s);
    if (index != ERRR) add_type_value(index, filesize);
    free(type_s);
}

static off_t folder_size(const char *path) {
    DIR *d = opendir(path);
    if (!d) {
        perror("opendir");
        return 0;
    }
    off_t total = 0;
    struct dirent *e;
    while ((e = readdir(d)) != NULL) {
        if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0) continue;
        char fullpath[PATH_MAX];
        if (snprintf(fullpath, sizeof(fullpath), "%s/%s", path, e->d_name) >= (int)sizeof(fullpath)) continue;
        struct stat st;
        if (lstat(fullpath, &st) == -1) {
            perror("lstat");
            continue;
        }
        if (S_ISDIR(st.st_mode)) {
            total += folder_size(fullpath);
        } else {
            total += st.st_size;
            get_type(fullpath, (int)strlen(fullpath), st.st_size);
        }
    }
    closedir(d);
    return total;
}

static void getDomLangIndex(int *index, uintptr_t *size) {
    uint64_t local_sums[SUPPORTET_GROUPS] = {0};
    for (int i = 1; i < NR_OF_SUPPORTET_LANG; ++i) {
        int group = types[i].globalsumindex;
        if (group >= 0 && group < SUPPORTET_GROUPS) {
            local_sums[group] += types[i].countet_size;
        }
    }
    int maxIndex = 0;
    uint64_t maxSize = 0;
    for (int i = 0; i < SUPPORTET_GROUPS; ++i) {
        if (local_sums[i] > maxSize) { maxSize = local_sums[i]; maxIndex = i; }
    }
    *index = maxIndex;
    *size = maxSize;
    for (int i = 0; i < NR_OF_SUPPORTET_LANG; ++i) types[i].countet_size = 0;
}

void getAbsolutPath(char *name, int nameLen) {
    char path[FILE_SYSTEM_BUFF_SIZE];
    if (getcwd(path, sizeof(path)) != NULL) {
        int pathLen = strlen(path);
	int len = pathLen + nameLen + 2;
	char *absolutPath = malloc(len + 1);
	absolutPath[len] = '\0';
	int k = 0;
	for (int i = 0; i < len; ++i) {
	    if (i < pathLen) {
	        absolutPath[i] = path[k];
		++k;
	    }
	    if (i > pathLen) {
	        absolutPath[i] = name[k];
		++k;
	    }
	    if (i == pathLen) {
	        absolutPath[i] = '/';
		k = 0;
	    }
	}
	printf("%s\n", absolutPath);
	clipper(absolutPath);
	free(absolutPath);
    } else {
        perror("ERROR: getcwd");
    }
}

void addUnixTimestamp(time_t unixTimestamp, time_t **unixTimestamps) {
    if (*unixTimestamps == NULL) {
        *unixTimestamps = malloc(unix_max * sizeof(time_t));
        if (*unixTimestamps == NULL) {
            perror("malloc unixTimestamps");
            return;
        }
    }
    (*unixTimestamps)[unix_index] = unixTimestamp;
    unix_index++;
    if (unix_index == unix_max) {
        time_t *copy = malloc(unix_max * sizeof(time_t));
        if (copy == NULL) {
            perror("malloc copy");
            return;
        }
        for (int i = 0; i < unix_max; i++) {
            copy[i] = (*unixTimestamps)[i];
        }
        free(*unixTimestamps);
        unix_max *= 2;
        *unixTimestamps = malloc(unix_max * sizeof(time_t));
        if (*unixTimestamps == NULL) {
            perror("malloc new unixTimestamps");
            free(copy);
            return;
        }
        for (int i = 0; i < unix_max / 2; i++) {
            (*unixTimestamps)[i] = copy[i];
        }
        free(copy);
    }
}

typedef struct {
    time_t unixtimestamp;
    char *row;
} TTAS;

void swap(TTAS *a, TTAS *b) {
    TTAS temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(TTAS *arr, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
}

/* 1. Sortieren: neueste zuerst (wie ls -t) */
void sortByTimestamp(time_t *unixTimestamps, char **rows, int n) {
    if (unixTimestamps == NULL || rows == NULL || n <= 1)
        return;
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (unixTimestamps[j] > unixTimestamps[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            time_t tempTime = unixTimestamps[i];
            unixTimestamps[i] = unixTimestamps[maxIndex];
            unixTimestamps[maxIndex] = tempTime;
            char *tempRow = rows[i];
            rows[i] = rows[maxIndex];
            rows[maxIndex] = tempRow;
        }
    }
    TTAS *array = malloc(n * sizeof(TTAS));
    if (array == NULL) {
        perror("malloc TTAS array");
        return;
    }
    for (int i = 0; i < n; ++i) {
        array[i].unixtimestamp = unixTimestamps[i];
        array[i].row           = rows[i]; // copy *ptr
    }
    reverseArray(array, n);
    for (int i = 0; i < n; ++i) {
        unixTimestamps[i] = array[i].unixtimestamp;
        rows[i]           = array[i].row;
    }
    free(array);
}

int main_lll() {
    DIR *d = opendir(".");
    if (d == NULL) {
        perror("opendir");
        return 1;
    }
    struct dirent *e;
    char **rows = NULL;
    time_t *unixTimestamps = NULL;
    size_t count = 0, cap = 0;
    while ((e = readdir(d)) != NULL) {
        if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)
            continue;
        char path[PATH_MAX];
        if (snprintf(path, sizeof(path), "./%s", e->d_name) >= (int)sizeof(path))
            continue;
        struct stat st;
        if (lstat(path, &st) == -1) {
            perror("lstat");
            continue;
        }
        char perms[11];
        mode_to_str(st.st_mode, perms);
        nlink_t links = st.st_nlink;
        struct passwd *pw = getpwuid(st.st_uid);
        struct group  *gr = getgrgid(st.st_gid);
        const char *owner = pw ? pw->pw_name : "unknown";
        const char *group = gr ? gr->gr_name : "unknown";
        char sizebuf[32];
        char timestr[64];
        struct tm tm;
        localtime_r(&st.st_mtime, &tm);
        strftime(timestr, sizeof(timestr), "%e. %b %H:%M", &tm);
        time_t timestamp = st.st_mtime;
        char dtype = S_ISDIR(st.st_mode) ? 'f' : 'd';
        if (S_ISDIR(st.st_mode)) {
            off_t sz = folder_size(path);
            process_size(sz, sizebuf, sizeof(sizebuf));
            get_type(path, (int)strlen(path), (size_t)sz);
        } else {
            process_size(st.st_size, sizebuf, sizeof(sizebuf));
            get_type(path, (int)strlen(path), (size_t)st.st_size);
        }
        int ja_index = 0;
        uintptr_t ja_size = 0;
        getDomLangIndex(&ja_index, &ja_size);
        char line[FILE_SYSTEM_BUFF_SIZE];
        if (S_ISLNK(st.st_mode)) {
            char target[PATH_MAX];
            ssize_t len = readlink(path, target, sizeof(target) - 1);
            if (len != -1) {
                target[len] = '\0';
                snprintf(line, sizeof(line), "%s %2lu %s %s %8s %s %s -> %s",
                         perms, (unsigned long)links, owner, group, sizebuf,
                         timestr, e->d_name, target);
            } else {
                snprintf(line, sizeof(line), "%s %2lu %s %s %8s %s %s",
                         perms, (unsigned long)links, owner, group, sizebuf,
                         timestr, e->d_name);
            }
        } else {
            snprintf(line, sizeof(line), "%s %2lu %s %s %8s %s %s %s",
                     perms, (unsigned long)links,
                     chngg(owner,     0x44FF44, 0),
                     chngg(group,     0x88FF88, 0),
                     chngg(sizebuf,   0xFF0000, 0),
                     chngg(timestr,   0x888866, 0),
                     chngg_wrapper(ja_index, ja_size),
                     chngg(e->d_name, (dtype == 'f') ? 0x9999FF : 0xFF33FF, 1));
        }
        if (count + 1 > cap) {
            size_t ncap = cap ? cap * 2 : 64;
            char **tmp = realloc(rows, ncap * sizeof(char*));
            if (!tmp) {
                perror("realloc rows");
                break;
            }
            rows = tmp;
            cap = ncap;
        }
        rows[count] = strdup(line);
        if (!rows[count]) {
            perror("strdup");
            break;
        }
        addUnixTimestamp(timestamp, &unixTimestamps);
        count++;
    }
    closedir(d);
    sortByTimestamp(unixTimestamps, rows, (int)count);
    for (size_t i = 0; i < count; ++i) {
        puts(rows[i]);
        free(rows[i]);
    }
    free(rows);
    free(unixTimestamps);
    return 0;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        main_lll();
	memlist_free_all();
    }
    if (argc == 2) {
	if (memcmp(argv[1], "max", 3) == 0) {
	    printf("MAX PATH LENGTH: %ld\n", FILE_SYSTEM_BUFF_SIZE);
	    return 0;
	}
        getAbsolutPath(argv[1], strlen(argv[1]));
    }
    return 0;
}

