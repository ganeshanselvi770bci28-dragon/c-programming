int strStr(char* haystack, char* needle) {
    int h_len = 0;
    while (haystack[h_len] != '\0') {
        h_len++;
    }

    int n_len = 0;
    while (needle[n_len] != '\0') {
        n_len++;
    }

    if (n_len == 0) {
        return 0;
    }

    if (h_len < n_len) {
        return -1;
    }

    for (int i = 0; i <= h_len - n_len; i++) {
        int j = 0;
        while (j < n_len && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == n_len) {
            return i;
        }
    }

    return -1;
}
