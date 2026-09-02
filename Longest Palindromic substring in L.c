char* longestPalindrome(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    if (len < 1) {
        char* empty_res = (char*)malloc(sizeof(char));
        empty_res[0] = '\0';
        return empty_res;
    }

    int start = 0;
    int max_len = 1;

    for (int i = 0; i < len; i++) {
        int left = i;
        int right = i;
        while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
            int current_len = right - left + 1;
            if (current_len > max_len) {
                start = left;
                max_len = current_len;
            }
            left--;
            right++;
        }

        left = i;
        right = i + 1;
        while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
            int current_len = right - left + 1;
            if (current_len > max_len) {
                start = left;
                max_len = current_len;
            }
            left--;
            right++;
        }
    }

    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    for (int i = 0; i < max_len; i++) {
        result[i] = s[start + i];
    }
    result[max_len] = '\0';

    return result;
}
